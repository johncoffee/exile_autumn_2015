using UnityEngine;
using System.Collections;
using UnityStandardAssets.ImageEffects;

[ExecuteInEditMode]
[AddComponentMenu("Image Effects/Color Adjustments/Grayscale")]
public class CameraPostProcess : ImageEffectBase
{

    public Texture GlitchTexture;
    public float ShakeFrequency;
    public float ShakeAmount;

    void OnRenderImage(RenderTexture source, RenderTexture destination)
    {
        material.SetTexture("_GlitchTexture", GlitchTexture);
        material.SetFloat("_ShakeFrequency", ShakeFrequency);
        material.SetFloat("_ShakeAmount", ShakeAmount);
        Graphics.Blit(source, destination, material);
    }

}
