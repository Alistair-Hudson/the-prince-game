﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FactionHandler : MonoBehaviour
{
    [SerializeField] List<Faction> factions;


    private void Awake()
    {
        if (1 < FindObjectsOfType<FactionHandler>().Length)
        {
            Destroy(gameObject);
        }
        else
        {
            DontDestroyOnLoad(gameObject);
        }
    }

    public void CheckForRebelion()
    {
        foreach (Faction faction in factions)
        {
            if (faction.Rebelion())
            {
                FindObjectOfType<SceneLoader>().LoadRebelion();
            }
        }
    }

    public void PositiveOption(string factionTag)
    {
        foreach (Faction faction in factions)
        {
            if (factionTag == faction.tag)
            {
                faction.IncreaseAttitudeLevel(1);
                faction.IncreaseInfluenceLevel(1);
            }
            else
            {
                faction.DecreaseAttitudeLevel(1);
            }
        }

    }

    public void NegativeOption(string factionTag)
    {
        foreach (Faction faction in factions)
        {
            if (factionTag == faction.tag)
            {
                faction.DecreaseAttitudeLevel(1);
                faction.DecreaseInfluenceLevel(1);
            }
            else
            {
                faction.IncreaseAttitudeLevel(1);
            }
        }
    }



    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}