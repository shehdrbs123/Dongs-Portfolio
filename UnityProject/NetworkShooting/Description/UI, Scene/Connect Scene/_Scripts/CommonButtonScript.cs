using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CommonButtonScript : MonoBehaviour {
    public void switchScene(string name){
        SceneManager.LoadScene (name);
    }

    public void exitGame(){
        Application.Quit ();
    }
}
