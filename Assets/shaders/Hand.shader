Shader "Custom/Hand" {
	Properties {
		_MainColor ("Main Color", Color) = (1,1,1,1)
		_ShineColor ("Shine Color", Color) = (1,1,1,1)
		_ShineColorMult ("Shine Color mult", float) = 1
		_DisplayPos ("Display pos", float) = 0
		_ShineRange ("Shine range", float) = 0
		_SplitRange ("Split range", float) = 0
		_NoiseTex ("Noise tex", 2D) = "white" {}
		_ShineTexMult ("Shine tex mult", float) = 0
		_Glossiness ("Smoothness", Range(0,1)) = 0.5
		_CutOff ("CutOff", float) = 0
		_Metallic ("Metallic", Range(0,1)) = 0.0
	}
	SubShader {
				Tags { "RenderType"="Opaque" }
		LOD 200
		//Blend SrcAlpha OneMinusSrcAlpha 

		Cull Off
		CGPROGRAM

		// Physically based Standard lighting model, and enable shadows on all light types
		#pragma surface surf Standard vertex:vert

		// Use shader model 3.0 target, to get nicer looking lighting
		#pragma target 3.0


		struct Input {
			float2 uv_NoiseTex;
			float3 worldPos;
			float3 worldNormal;
		};

		half _Glossiness;
		half _Metallic;
		fixed4 _MainColor;
		fixed4 _ShineColor;
		fixed _ShineColorMult;
		fixed _ShineRange;
		fixed _SplitRange;
		fixed _DisplayPos;
		sampler2D _NoiseTex;
		fixed _ShineTexMult;

		struct appdata {
            float4 vertex : POSITION;
            float4 tangent : TANGENT;
            float3 normal : NORMAL;
            float2 texcoord : TEXCOORD0;
        };

		void vert (inout appdata v) {


			float pValue = v.texcoord.y + _SplitRange;


			if (_DisplayPos < pValue){
				//v.vertex.xyz += v.normal * (pValue - _DisplayPos)/4;
				v.vertex.xyz += normalize(v.vertex.xyz) * (pValue - _DisplayPos)/4;
			}
		}

		void surf (Input IN, inout SurfaceOutputStandard o) {
			fixed4 c; 
			
			float pValue = IN.uv_NoiseTex.y + tex2D (_NoiseTex, IN.uv_NoiseTex).r*_ShineTexMult;

			if (_DisplayPos > pValue && dot(IN.worldNormal, IN.worldPos - _WorldSpaceCameraPos) < 0.05f)
			{
				c = _MainColor;
				o.Alpha = c.a;
				o.Metallic = _Metallic;
				o.Smoothness = _Glossiness;

			} else if (_DisplayPos + _ShineRange > pValue){
				o.Emission = _ShineColor * _ShineColorMult;
				c = _ShineColor;
				o.Alpha = c.a;
				o.Metallic = 0.0f;
				o.Smoothness = 0.0f;
			} else {
				discard;
			}

			o.Albedo = c.rgb;


		}
		ENDCG
	}
	FallBack "Diffuse"
}
