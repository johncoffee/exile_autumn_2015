Shader "Hidden/ScreenGlitch"
{
	Properties
	{
		_MainTex("Base (RGB)", 2D) = "white" {}
		_GlitchTexture("GLitch Texture", 2D) = "white" {}
		_ShakeFrequency("SHake Frequency", float) = 0.3
		_ShakeAmount("SHake Frequency", float) = 5.0
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
			uniform sampler2D _GlitchTexture;
			uniform fixed _ShakeFrequency;
			uniform fixed _ShakeAmount;

			fixed4 frag(v2f_img i) : SV_Target
			{

				fixed2 offset = fixed2(0, 0);

				fixed4 glitchDecision = tex2D(_GlitchTexture, fixed2(_Time.x/2, _Time.x/2));


				if (glitchDecision.r < _ShakeFrequency) {
					
					fixed4 glitchPoint = tex2D(_GlitchTexture, fixed2(_Time.x*10, _Time.x*100));
					offset = fixed2(glitchPoint.g - 0.5f, glitchPoint.b - 0.5f);

					offset = offset / 100.0f * _ShakeAmount;
				}

				offset = offset + i.uv;
				offset.x = offset.x % 1.0f;
				offset.y = offset.y % 1.0f;

				fixed4 original = tex2D(_MainTex, offset);

				return original;
			}
			ENDCG
		}
	}
		Fallback off
}
