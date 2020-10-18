using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Faction : MonoBehaviour
{
    //Variables
    float m_attitude = 0;
    float m_influence = 0;

    //Constants
    float MAX_ATTITUDE = 100;
    float MAX_INFLUENCE = 100;

    public void DecreaseAttitudeLevel(float dcr)
    {
        m_attitude -= dcr;
        if (m_attitude <= -MAX_ATTITUDE)
        {
            m_attitude = -MAX_ATTITUDE;
        }
        if (m_attitude >= MAX_ATTITUDE)
        {
            m_attitude = MAX_ATTITUDE;
        }
    }

    public void IncreaseAttitudeLevel(float inc)
    {
        m_attitude += inc;
        if (m_attitude >= MAX_ATTITUDE)
        {
            m_attitude = MAX_ATTITUDE;
        }
        if (m_attitude <= -MAX_ATTITUDE)
        {
            m_attitude = -MAX_ATTITUDE;
        }
    }

    public void DecreaseInfluenceLevel(int dcr)
    {
        m_influence -= dcr;
        if (m_influence >= MAX_INFLUENCE)
        {
            m_influence = MAX_INFLUENCE;
        }
        if (m_influence <= 0)
        {
            m_influence = 0;
        }
    }

    public void IncreaseInfluenceLevel(int inc)
    {
        m_influence += inc;
        if (m_influence >= MAX_INFLUENCE)
        {
            m_influence = MAX_INFLUENCE;
        }
        if (m_influence <= 0)
        {
            m_influence = 0;
        }
    }

    public float GetAttitude()
    {
        return m_attitude;
    }

    public float GetInfluence()
    {
        return m_influence;
    }

    public bool Rebelion()
    {
        if (Random.Range(0, 100) <= Mathf.Abs(m_attitude) * (float)m_influence / 100)
        {
            return true;
        }
        return false;
    }
}
