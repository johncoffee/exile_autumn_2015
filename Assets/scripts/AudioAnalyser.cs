using UnityEngine;
using System.Collections;
using System.Linq;

public class AudioAnalyser : MonoBehaviour {

    private AudioSource _as;
    private float[] _spectrumData = new float[512];

    [Range(0.0f, 1.0f)]
    public float TrackTime;

    private static AudioAnalyser _instance;

    public static AudioAnalyser Instance
    {
        get
        {
            return _instance;
        }
    }

    void Awake()
    {
        _instance = this;
        _as = GetComponent<AudioSource>();
    }

	
	void Update () {
        if (Mathf.Abs(TrackTime - _as.time / _as.clip.length) > 0.01f)
        {
            _as.time = TrackTime * _as.clip.length;
        }

        _as.GetSpectrumData(_spectrumData, 0, FFTWindow.Rectangular);
        TrackTime = _as.time / _as.clip.length;

    }

    public float RetrievePeakOfData(int startIndex, int endIndex)
    {
        return _spectrumData.ToList().GetRange(startIndex, endIndex - startIndex).Max();
    }
}
