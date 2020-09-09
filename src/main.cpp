#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "SFML/Graphics.hpp"

#include "database.hpp"

void Foo(the_prince::SpriteHandler& v)
{
    v.AddSprite("./textures/pikachu.png");
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "The Prince");
    the_prince::SpriteHandler sprites;
    std::map<std::string, the_prince::Faction> faction_map;
    the_prince::Factory<the_prince::ActParams > action_factory;
    the_prince::TextHandler texts;
    sf::Text game_over;
    sf::Font font;
    int action = 0;
    bool title_screen = 1;
    bool rebelion = 0;



    int total_actions = ActionInitiliser(action_factory, texts);
    CreateFactionMap(faction_map);

    font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf");
    game_over.setString("GAME OVER");
    game_over.setFont(font);
    game_over.setCharacterSize(24);
    game_over.setFillColor(sf::Color::White);

    the_prince::ActParams params = {faction_map, window};

    while (window.isOpen())
    {
        sf::Event event;
        window.clear();
        if (rebelion)
        {
            window.draw(game_over);
        }
        else
        {   
            //window.draw(sprites[action]);
            window.draw(texts[action]);
        }
        window.display();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (title_screen)
                    {
                        title_screen = 0;
                        action = (rand()%total_actions) +1;
                    }
                    else
                    {
                        if((*action_factory.CreateAction(action, params))(event.key.code))
                        {
                            action = (rand()%total_actions) +1;
                            std::map<std::string, the_prince::Faction>::iterator iter = faction_map.begin();
                            while (iter != faction_map.end())
                            {
                                rebelion |= iter->second.Rebelion();
                                iter = next(iter);
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        
    }

    return 0;
}