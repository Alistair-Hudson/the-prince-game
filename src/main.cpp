#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "SFML/Graphics.hpp"

#include "database.hpp"

#define YEARS   (30)
#define MONTHS  (12*YEARS)

struct DisplayParams
{
    sf::RenderWindow* window;
    the_prince::SpriteHandler sprites;
    the_prince::TextHandler texts;
    sf::Text game_over;
    sf::Font font;
    int action;
    int months_remaining;
    bool title_screen;
    bool rebelion;

};

void Display(DisplayParams display);

void Foo(the_prince::SpriteHandler& v)
{
    v.AddSprite("./textures/pikachu.png");
}


int main()
{
    DisplayParams display;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "The Prince");
    the_prince::Factory<the_prince::ActParams > action_factory;
    the_prince::SpriteHandler sprites;
    std::map<std::string, the_prince::Faction> faction_map;

    display.window = &window;
    display.action = 0;
    display.title_screen = 1;
    display.rebelion = 0;
    display.months_remaining = MONTHS;

    int total_actions = ActionInitiliser(action_factory, display.texts);
    CreateFactionMap(faction_map);

    display.font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf");
    display.game_over.setString("GAME OVER");
    display.game_over.setFont(display.font);
    display.game_over.setCharacterSize(24);
    display.game_over.setFillColor(sf::Color::White);

    the_prince::ActParams params = {faction_map, window};

    while (window.isOpen())
    {
        sf::Event event;
        Display(display);
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (display.title_screen)
                    {
                        display.title_screen = 0;
                        display.action = (rand()%total_actions) +1;
                    }
                    else
                    {
                        if((*action_factory.CreateAction(display.action, params))(event.key.code))
                        {
                            display.action = (rand()%total_actions) +1;
                            std::map<std::string, the_prince::Faction>::iterator iter = faction_map.begin();
                            while (iter != faction_map.end())
                            {
                                display.rebelion |= iter->second.Rebelion();
                                iter = next(iter);
                            }
                            --display.months_remaining;
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

void Display(DisplayParams display)
{
        display.window->clear();
        if (display.rebelion)
        {
            display.window->draw(display.game_over);
        }
        else if (0 >= display.months_remaining)
        {
            display.game_over.setString("You have lived a good life\nYour heir has succeed you");
            display.window->draw(display.game_over);
        }
        else
        {   
            //window.draw(sprites[action]);
            display.window->draw(display.texts[display.action]);
        }
        display.window->display();
}