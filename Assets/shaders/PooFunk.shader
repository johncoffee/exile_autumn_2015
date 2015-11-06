Shader "Hidden/ScreenGlitchPoo"
{
	Properties
	{
		_MainTex("Base (RGB)", 2D) = "white" {}
		_ShakeMagnitude("Shake magnitude", float) = 0.005
	}
	SubShader
	{
		Pass
		{
			ZTest Always Cull Off ZWrite Off

			CGPROGRAM
			#pragma vertex vert_img
			#pragma fragment frag
			#include "UnityCG.cginc"

			uniform sampler2D _MainTex;
			uniform float _ShakeMagnitude;

			fixed4 frag(v2f_img i) : SV_Target
			{			
				fixed2 offset = fixed2(0, 0);				
				offset = offset + i.uv;
//				offset.x = offset.x + cos(_Time.y * 50.0f) * _ShakeMagnitude;
//				offset.y = offset.y + sin(_Time.y * 51.0f) * _ShakeMagnitude;								
				
				fixed4 original = tex2D(_MainTex, offset);
//				original.x = original.z + sin(_Time.y * tex2D(_MainTex, offset).z ) ;
				original.r = original.z + sin(_Time.y * tex2D(_MainTex, offset).z ) ;
				return original;
			}
			ENDCG
		}
	}
	Fallback off
}
