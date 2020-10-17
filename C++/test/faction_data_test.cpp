#include <iostream>
#include <iterator>
#include <map>

#include "action.hpp"
#include "action_factory.hpp"
#include "faction.hpp"

using namespace the_prince;

int main()
{
    std::map<std::string, Faction> map;
    
    CreateFactionMap(map);

    std::cout << map.find("Military")->second.GetName() << std::endl;

    return 0;
}