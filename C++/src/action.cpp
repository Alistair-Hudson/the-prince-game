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
                        std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                    m_window(window)
    {}
    ~FundLawEnforcement(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class OpenNewDryDock: public Action
{
public:
    OpenNewDryDock( sf::RenderWindow& window, 
                    std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~OpenNewDryDock(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class ExpandFishing:public Action
{
public:
    ExpandFishing(  sf::RenderWindow& window, 
                    std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~ExpandFishing(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class NewReligionArrives: public Action
{
public:
    NewReligionArrives( sf::RenderWindow& window, 
                        std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                    m_window(window)
    {}
    ~NewReligionArrives(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class FundingMilitary: public Action
{
public:
    FundingMilitary(    sf::RenderWindow& window, 
                        std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                    m_window(window)
    {}
    ~FundingMilitary(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class IncreaseTaxes: public Action
{
public:
    IncreaseTaxes(  sf::RenderWindow& window, 
                    std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~IncreaseTaxes(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class ClearLand: public Action
{
public:
    ClearLand(  sf::RenderWindow& window, 
                std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                            m_window(window)
    {}
    ~ClearLand(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class CrusadeAgainstFaithless: public Action
{
public:
    CrusadeAgainstFaithless(sf::RenderWindow& window, 
                            std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                        m_window(window)
    {}
    ~CrusadeAgainstFaithless(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class InvadeNeighbour: public Action
{
public:
    InvadeNeighbour(sf::RenderWindow& window, 
                    std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~InvadeNeighbour(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class TradeWithNation: public Action
{
public:
    TradeWithNation(sf::RenderWindow& window, 
                    std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~TradeWithNation(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class HoldFestival: public Action
{
public:
    HoldFestival(   sf::RenderWindow& window, 
                    std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                                m_window(window)
    {}
    ~HoldFestival(){}
    bool operator()(sf::Keyboard::Key key);
private:
    std::map<FACTION, Faction> m_factions;
    sf::RenderWindow& m_window;
};

class NoRequests: public Action
{
public:
    NoRequests( sf::RenderWindow& window,
                std::map<FACTION, Faction> faction_map):    m_factions(faction_map),
                                                            m_window(window)
    {}
    ~NoRequests(){}
    bool operator()(sf::Keyboard::Key key)
    {
        return 1;
    }
private:
    std::map<FACTION, Faction> m_factions;
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
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }

    m_factions.find(LAWENFORCEMENT)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(LAWENFORCEMENT)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MILITARY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MILITARY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.DecreaseAttitudeLevel(alter+1);

    m_factions.find(TREASURY)->second.DecreaseAttitudeLevel(alter+1);

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
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }
    
    m_factions.find(FISHERIES)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FISHERIES)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MERCHANTS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MERCHANTS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(FARMERS)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(FARMERS)->second.DecreaseInfluenceLevel(alter+1);

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
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }

    m_factions.find(FISHERIES)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FISHERIES)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MERCHANTS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MERCHANTS)->second.IncreaseInfluenceLevel(alter);

    //m_factions.find("Treasury")->second.IncreaseAttitudeLevel(alter);

    m_factions.find(PUBLIC)->second.IncreaseAttitudeLevel(alter);

    m_factions.find(FARMERS)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(FARMERS)->second.DecreaseInfluenceLevel(alter+1);

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

    m_factions.find(CHURCH)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(CHURCH)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MERCHANTS)->second.DecreaseAttitudeLevel(alter);

    return 1;
}

bool FundingMilitary::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::F:
            alter = 1;
            break;
        case sf::Keyboard::Key::D:
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }

    m_factions.find(MILITARY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MILITARY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(TREASURY)->second.DecreaseAttitudeLevel(alter+1);
    return 1;
}

bool IncreaseTaxes::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::I:
            alter = 1;
            break;
        case sf::Keyboard::Key::D:
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }

    m_factions.find(TREASURY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(TREASURY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.DecreaseAttitudeLevel(alter+1);
    
    m_factions.find(MERCHANTS)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(MERCHANTS)->second.DecreaseInfluenceLevel(alter+1);

    return 1;
}

bool ClearLand::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::C:
            alter = 1;
            break;
        case sf::Keyboard::Key::D:
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }
    m_factions.find(FARMERS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FARMERS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MERCHANTS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MERCHANTS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.IncreaseAttitudeLevel(alter);

    m_factions.find(FISHERIES)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(FISHERIES)->second.DecreaseInfluenceLevel(alter+1);

    return 1;
}

bool CrusadeAgainstFaithless::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::C:
            alter = 1;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }
    m_factions.find(CHURCH)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(CHURCH)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MILITARY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MILITARY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.IncreaseAttitudeLevel(alter);

    return 1;
}

bool InvadeNeighbour::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::I:
            alter = 1;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }
    m_factions.find(CHURCH)->second.DecreaseAttitudeLevel(alter);
    m_factions.find(CHURCH)->second.DecreaseInfluenceLevel(alter);

    m_factions.find(MILITARY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MILITARY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.IncreaseAttitudeLevel(alter);

    return 1;
}

bool TradeWithNation::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::O:
            alter = 1;
            break;
        case sf::Keyboard::Key::C:
            alter = -2;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }
    m_factions.find(FARMERS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FARMERS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(FISHERIES)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FISHERIES)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MERCHANTS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MERCHANTS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(TREASURY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(TREASURY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.IncreaseAttitudeLevel(alter);

    m_factions.find(MILITARY)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(MILITARY)->second.DecreaseInfluenceLevel(alter+1);

    return 1;
}

bool HoldFestival::operator()(sf::Keyboard::Key key)
{
    int alter = 0;

    switch(key)
    {
        case sf::Keyboard::Key::H:
            alter = 1;
            break;
        case sf::Keyboard::Key::N:
            alter = -1;
            break;
        default:
            return 0;
    }
    
    m_factions.find(FARMERS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FARMERS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(FISHERIES)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(FISHERIES)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MERCHANTS)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MERCHANTS)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(MILITARY)->second.IncreaseAttitudeLevel(alter);
    m_factions.find(MILITARY)->second.IncreaseInfluenceLevel(alter);

    m_factions.find(PUBLIC)->second.IncreaseAttitudeLevel(alter);

    m_factions.find(TREASURY)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(TREASURY)->second.DecreaseInfluenceLevel(alter+1);

    m_factions.find(LAWENFORCEMENT)->second.DecreaseAttitudeLevel(alter+1);
    m_factions.find(LAWENFORCEMENT)->second.DecreaseInfluenceLevel(alter+1);

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

the_prince::Action* the_prince::BuildCAF(ActParams params)
{
    return new CrusadeAgainstFaithless(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildINT(ActParams params)
{
    return new InvadeNeighbour(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildTNN(ActParams params)
{
    return new TradeWithNation(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildHdF(ActParams params)
{
    return new HoldFestival(params.window, params.faction_map);
}

the_prince::Action* the_prince::BuildNoReq(ActParams params)
{
    return new NoRequests(params.window, params.faction_map);
}