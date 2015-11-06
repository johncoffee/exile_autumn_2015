using UnityEngine;
using System.Collections;
using UnityStandardAssets.ImageEffects;

[ExecuteInEditMode]
public class CameraPostProcessTemplate : ImageEffectBase
{

    //public Texture GlitchTexture;
    void OnRenderImage(RenderTexture source, RenderTexture destination)
    {
        //material.SetTexture("_GlitchTexture", GlitchTexture);
        Graphics.Blit(source, destination, material);
    }

}
