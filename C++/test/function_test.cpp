#include "database.hpp"

using namespace the_prince;

int main()
{

    int total_actions = 0;
    int i = 10;
    std::map<std::string, Faction> faction_map;
    Factory<std::map<std::string, Faction> > action_factory;


    CreateFactionMap(faction_map);
    total_actions = ActionInitiliser(action_factory);

    while (i > 0)
    {
        int key = rand() % total_actions +1;
        (*(action_factory.CreateAction(key, faction_map)))();

        --i;
    }

    return 0;
}