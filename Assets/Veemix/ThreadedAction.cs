using UnityEngine;
using System.Collections;
using System.Net;
using System.Threading;
using System;

public class ThreadedAction : MonoBehaviour
{
	public ThreadedAction(Action action) {
		var thread = new Thread(() => {
			if(action != null)
				action();
			_isDone=true;
		});
		thread.Start();
	}
	
	public IEnumerator WaitForComplete() {
		
		while (!_isDone)
			yield return null;
	}
	
	private bool _isDone = false;
	
}
