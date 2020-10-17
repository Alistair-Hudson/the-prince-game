/******************************************************************************
 *	Title:		Faction
 *	Authour:	Alistair Hudson
 *	Reviewer:	
 *	Version:	20.08.2020.0
 ******************************************************************************/
#include "faction.hpp"

using namespace the_prince;

/******MACROS******/
#define MAX_ATTITUDE   (100)
#define MAX_INFLUENCE  (100)

/******TYPEDEFS*****/

/****** GLOBAL VARIABLES*****/

/*****STRUCTS*******/

/*****CLASSES******/

/*****FUNCTORS*****/

/******INTERNAL FUNCTION DECLARATION******/


/******CLASS METHODS*******/
/*===Facton===*/
void Faction::DecreaseAttitudeLevel(float dcr)
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

void Faction::IncreaseAttitudeLevel(float inc)
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

void Faction::DecreaseInfluenceLevel(int dcr)
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

void Faction::IncreaseInfluenceLevel(int inc)
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


/*****FUNCTION DEFINITION******/
 