using UnityEngine;
using System.Collections;
using UnityStandardAssets.ImageEffects;

[ExecuteInEditMode]
public class CameraPostProcessFunk : ImageEffectBase
{
	public float ShakeMagnitude;

    //public Texture GlitchTexture;
    void OnRenderImage(RenderTexture source, RenderTexture destination)
    {
		material.SetFloat("_ShakeMagnitude", ShakeMagnitude);
        //material.SetTexture("_GlitchTexture", GlitchTexture);
        Graphics.Blit(source, destination, material);
    }

}
