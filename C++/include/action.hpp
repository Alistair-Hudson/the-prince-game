#ifndef __THE_PRINCE_ACTION_HPP__
#define __THE_PRINCE_ACTION_HPP__
/*****************************************************************************
 * ACTION API
 * Alistair Hudson
 * version 23.08.2020.0
******************************************************************************/

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Main.hpp"

#include "faction.hpp"



namespace the_prince
{

struct ActParams
{
    std::map<FACTION, Faction>& faction_map;
    sf::RenderWindow& window;
};

class Action
{
public:
    Action(){}
    virtual ~Action(){};
    virtual bool operator()(sf::Keyboard::Key key) = 0;

private:

};

void InitGolbals();

//BUILDERS
Action* BuildFLE(ActParams params);
Action* BuildOND(ActParams params);
Action* BuildExF(ActParams params);
Action* BuildNRA(ActParams params);
Action* BuildFdM(ActParams params);
Action* BuildInT(ActParams params);
Action* BuildCLn(ActParams params);
Action* BuildCAF(ActParams params);
Action* BuildINT(ActParams params);
Action* BuildTNN(ActParams params);
Action* BuildHdF(ActParams params);
Action* BuildNoReq(ActParams params);


} // namespace the_prince

#endif // __THE_PRINCE_ACTION_FACTORY_HPP__