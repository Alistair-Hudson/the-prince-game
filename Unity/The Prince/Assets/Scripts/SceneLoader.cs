using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour
{
    [SerializeField] int numNonPlayable = 5;

    public void LoadAnotherScene()
    {
        if(FindObjectOfType<FactionHandler>().CheckForRebelion())
        {
            LoadRebelion();
            return;
        }

        FindObjectOfType<FactionHandler>().DecreaseTurns();
        if (0 >= FindObjectOfType<FactionHandler>().GetTurnsRemaining())
        {
            LoadVictory();
            return;
        }

        int index = Mathf.RoundToInt(Random.Range(numNonPlayable, SceneManager.sceneCountInBuildSettings));
        SceneManager.LoadScene(index);
    }

    public void LoadRebelion()
    {
        SceneManager.LoadScene("Rebelion");
        Destroy(FindObjectOfType<FactionHandler>());
    }

    public void LoadVictory()
    {
        SceneManager.LoadScene("Victory");
        Destroy(FindObjectOfType<FactionHandler>());
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
