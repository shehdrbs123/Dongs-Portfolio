using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CommonButtonScript : MonoBehaviour {


    void Start()
    {
        //Screen.SetResolution(1440, 2560, false);
        //Screen.SetResolution(Screen.height * 9/16, Screen.height, false);
    }
    public void switchScene(string name)
	{
		SceneManager.LoadScene (name);
	}
	public void exitGame(){
		Application.Quit ();
	}
}
