using UnityEngine;
using System.Collections;

public class FunkyScript : MonoBehaviour {

	public GameObject thing, character;

	void Start () {
	
	}
	
	void Update () {
		float dist = Vector3.Distance(
			thing.transform.position,
			character.transform.position
			);
		thing.transform.localScale = new Vector3(1, dist, 1);
	}
}
