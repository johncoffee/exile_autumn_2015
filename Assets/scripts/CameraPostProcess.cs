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
        if (Application.isPlaying)
        {
            float amount = AudioAnalyser.Instance.RetrievePeakOfData(0, 20) * 100.0f;
            if (amount > 55.0f)
            {
                ShakeFrequency = 1.0f;
                ShakeAmount = (amount - 20.0f) / 5.0f;

            }
            else
            {
                ShakeFrequency = 0.0f;
            }
        }

        material.SetFloat("_ShakeFrequency", ShakeFrequency);
        material.SetFloat("_ShakeAmount", ShakeAmount);
        
        Graphics.Blit(source, destination, material);
    }

}
