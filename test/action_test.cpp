#include "database.hpp"

int main()
{
    the_prince::TextHandler texts;
    the_prince::Factory<the_prince::ActParams> factory;
    std::map<std::string, the_prince::Faction> factions;
    sf::RenderWindow window;
    the_prince::ActParams params = {factions, window};

    int total = the_prince::ActionInitiliser(factory, texts);
    int i = 1;
    while(1)
    {   
        std::cout << i << std::endl;
        factory.CreateAction(i, params);
        texts[i];
        ++i;
    }
    
    return 0;
}