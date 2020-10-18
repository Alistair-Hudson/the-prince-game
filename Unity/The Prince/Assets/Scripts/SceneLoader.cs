using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour
{
    [SerializeField] int numNonPlayable = 5;

    public void LoadAnotherScene()
    {
        int index = Mathf.RoundToInt(Random.Range(numNonPlayable, SceneManager.sceneCountInBuildSettings));
        SceneManager.LoadScene(index);
    }

    public void LoadRebelion()
    {
        SceneManager.LoadScene("Rebelion");
    }

    public void LoadVictory()
    {
        SceneManager.LoadScene("Victory");
    }

    public void LoadCredits()
    {
        SceneManager.LoadScene("Credits");
    }

    public void LoadStart()
    {
        SceneManager.LoadScene(0);
        Destroy(FindObjectOfType<FactionHandler>());
    }

    public void LoadIntro()
    {
        SceneManager.LoadScene("Intro");
    }

    public void QuitGame()
    {
        Application.Quit();
    }

    public void Test(int i)
    {

    }
}
