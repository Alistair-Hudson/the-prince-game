#ifndef __THE_PRINCE_FACTION_HPP__
#define __THE_PRINCE_FACTION_HPP__
/*****************************************************************************
 * FACTION API
 * Alistair Hudson
 * version 20.08.2020.0
******************************************************************************/
#include <map>
#include <string>
#include <iterator>

namespace the_prince
{
class Faction
{
public:
    Faction(std::string name):  m_name(name), 
                                m_attitude(0), 
                                m_influence(0)
    {}

    inline std::string GetName(){return m_name;}
    inline bool Rebelion()const
    {
        return ((rand()%100+1) < (abs(m_attitude)*(float)m_influence/100) ? 1 : 0);
    }

    inline float GetAttitudeLevel()const {return m_attitude;}
    void DecreaseAttitudeLevel(float dcr);
    void IncreaseAttitudeLevel(float inc);

    inline int GetInfluenceLevel()const {return m_influence;}
    void DecreaseInfluenceLevel(int dcr);
    void IncreaseInfluenceLevel(int inc);

private:
    std::string m_name;
    float m_attitude;
    int m_influence;

};

void CreateFactionMap(std::map<std::string, Faction>& map);

}//namespace the_prince
#endif /* __THE_PRINCE_FACTION_HPP__ */