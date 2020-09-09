/******************************************************************************
 *	Title:		Action
 *	Authour:	Alistair Hudson
 *	Reviewer:	
 *	Version:	24.08.2020.0
 ******************************************************************************/
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <unistd.h>

#include "action.hpp"

using namespace the_prince;

/******MACROS******/

/******TYPEDEFS*****/

/****** GLOBAL VARIABLES*****/

/*****STRUCTS*******/

/*****CLASSES******/
class FundLawEnforcement: public Action
{
public:
    FundLawEnforcement( sf::RenderWindow& window, 
                        std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                        m_window(window)
    {}
    ~FundLawEnforcement(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class OpenNewDryDock: public Action
{
public:
    OpenNewDryDock( sf::RenderWindow& window, 
                    std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                    m_window(window)
    {}
    ~OpenNewDryDock(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class ExpandFishing:public Action
{
public:
    ExpandFishing(  sf::RenderWindow& window, 
                    std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                    m_window(window)
    {}
    ~ExpandFishing(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class NewReligionArrives: public Action
{
public:
    NewReligionArrives( sf::RenderWindow& window, 
                        std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                        m_window(window)
    {}
    ~NewReligionArrives(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class FundingMilitary: public Action
{
public:
    FundingMilitary(    sf::RenderWindow& window, 
                        std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                        m_window(window)
    {}
    ~FundingMilitary(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class IncreaseTaxes: public Action
{
public:
    IncreaseTaxes(  sf::RenderWindow& window, 
                    std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                    m_window(window)
    {}
    ~IncreaseTaxes(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class ClearLand: public Action
{
public:
    ClearLand(  sf::RenderWindow& window, 
                std::map<std::string, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~ClearLand(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<std::string, Faction> m_factions;
    sf::RenderWindow& m_window;
};

/*****FUNCTORS*****/

/******INTERNAL FUNCTION DECLARATION******/

/******CLASS METHODS*******/
bool FundLawEnforcement::operator()(sf::Keyboard::Key key)
{
    int alter = 0;
    switch(key)
    {
        case sf::Keyboard::Key::F:
            alter = 1;
            break;
        case sf::Keyboard::Key::D:
            alter = -1;
            break;
        case sf::Keyboard::Key::N:
            alter = 0;
            break;
        default:
            return 0;
    }

    m_factions.find("Law Enforcement")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Law Enforcement")->second.IncreaseInfluenceLevel(alter);

    m_factions.find("Military")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Military")->second.IncreaseInfluenceLevel(alter);

    m_factions.find("General Public")->second.DecreaseAttitudeLevel(alter);

    m_factions.find("Treasury")->second.DecreaseAttitudeLevel(alter);

    return 1;
}

bool OpenNewDryDock::operator()(sf::Keyboard::Key key)
{
   int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::O:
            alter = 1;
            break;
        case sf::Keyboard::Key::C:
            alter = -1;
            break;
        case sf::Keyboard::Key::N:
            alter = 0;
            break;
        default:
            return 0;
    }
    
    m_factions.find("Fisheries")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Fisheries")->second.IncreaseInfluenceLevel(alter);

    m_factions.find("Merchant Guild")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Merchant Guild")->second.IncreaseInfluenceLevel(alter);

    m_factions.find("Farmers")->second.DecreaseAttitudeLevel(alter);
    m_factions.find("Farmers")->second.DecreaseInfluenceLevel(alter);

    return 1;
}

bool ExpandFishing::operator()(sf::Keyboard::Key key)
{
   int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::E:
            alter = 1;
            break;
        case sf::Keyboard::Key::D:
            alter = -1;
            break;
        case sf::Keyboard::Key::N:
            alter = 0;
            break;
        default:
            return 0;
    }

    m_factions.find("Fisheries")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Fisheries")->second.IncreaseInfluenceLevel(alter);

    m_factions.find("Merchant Guild")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Merchant Guild")->second.IncreaseInfluenceLevel(alter);

    //m_factions.find("Treasury")->second.IncreaseAttitudeLevel(alter);

    m_factions.find("General Public")->second.IncreaseAttitudeLevel(alter);

    m_factions.find("Farmers")->second.DecreaseAttitudeLevel(alter);
    m_factions.find("Farmers")->second.DecreaseInfluenceLevel(alter);

    return 1;
}

bool NewReligionArrives::operator()(sf::Keyboard::Key key)
{
   int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::A:
            alter = -1;
            break;
        case sf::Keyboard::Key::D:
            alter = -2;
            break;
        case sf::Keyboard::Key::T:
            alter = 1;
            break;
        default:
            return 0;
    }

    m_factions.find("Church")->second.IncreaseAttitudeLevel(alter);
    m_factions.find("Church")->second.IncreaseInfluenceLevel(alter);

    return 1;
}

bool FundingMilitary::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::Return:
            break;
        default:
            return 0;
    }

    return 1;
}

bool IncreaseTaxes::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::Return:
            break;
        default:
            return 0;
    }

    return 1;
}

bool ClearLand::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::Return:
            break;
        default:
            return 0;
    }
 
    return 1;
}

/*****FUNCTION DEFINITION******/
/*===Builders===*/
the_prince::Action* the_prince::BuildFLE(ActParams params)
{
    return new FundLawEnforcement(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildOND(ActParams params)
{
    return new OpenNewDryDock(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildExF(ActParams params)
{
    return new ExpandFishing(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildNRA(ActParams params)
{
    return new NewReligionArrives(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildFdM(ActParams params)
{
    return new FundingMilitary(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildInT(ActParams params)
{
    return new IncreaseTaxes(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildCLn(ActParams params)
{
    return new ClearLand(params.window, params.faction_map);
}