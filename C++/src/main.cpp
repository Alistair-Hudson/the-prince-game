/******************************************************************************
 *	Title:		Main
 *	Authour:	Alistair Hudson
 *	Reviewer:	
 *	Version:	30.08.2020.0
 ******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "SFML/Graphics.hpp"

#include "database.hpp"

/******MACROS******/
#define YEARS   (30)
#define MONTHS  (12*YEARS)

/******TYPEDEFS*****/

/****** GLOBAL VARIABLES*****/

/*****STRUCTS*******/
struct DisplayParams
{
    sf::RenderWindow* window;
    the_prince::SpriteHandler sprites;
    the_prince::TextHandler texts;
    sf::Text non_playable_screen;
    sf::Font font;
    int action;
    int months_remaining;
    bool title_screen;
    bool rebelion;

};

/*****CLASSES******/

/*****FUNCTORS*****/

/******INTERNAL FUNCTION DECLARATION******/ 
static void Display(DisplayParams display);

/******CLASS METHODS*******/

/*****FUNCTION DEFINITION******/
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
    std::map<the_prince::FACTION, the_prince::Faction> faction_map;

    display.window = &window;
    display.action = 0;
    display.title_screen = 1;
    display.rebelion = 0;
    display.months_remaining = MONTHS;

    int total_actions = ActionInitiliser(action_factory, display.texts)-1;
    CreateFactionMap(faction_map);

    display.font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf");
    display.non_playable_screen.setString("Press Any Key to Continue");
    display.non_playable_screen.setFont(display.font);
    display.non_playable_screen.setCharacterSize(24);
    display.non_playable_screen.setFillColor(sf::Color::White);
    display.non_playable_screen.setPosition(sf::Vector2f(300, 500));

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
                            std::map<the_prince::FACTION, the_prince::Faction>::iterator iter = faction_map.begin();
                            while (iter != faction_map.end())
                            {
                                display.rebelion |= iter->second.Rebelion();
                                iter = next(iter);
                            }
                            std::cout << display.action << std::endl;
                            display.months_remaining -= 3;
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

static void Display(DisplayParams display)
{
        display.window->clear();
        if (display.title_screen) 
        {
            display.window->draw(display.non_playable_screen);
        }
        else if (display.rebelion)
        {
            display.non_playable_screen.setString("A rebelion has been incited and you have been over thrown\nGAME OVER");
            display.window->draw(display.non_playable_screen);
        }
        else if (0 >= display.months_remaining)
        {
            display.non_playable_screen.setString("You have lived a good life\nYour heir has succeed you");
            display.window->draw(display.non_playable_screen);
        }
        else
        {   
            sf::RectangleShape text_box(sf::Vector2f(1000, 200));
            text_box.setFillColor(sf::Color::White);
            text_box.setPosition(sf::Vector2f(TEXT_BOX_X, TEXT_BOX_Y));
            //window.draw(sprites[action]);
            display.window->draw(text_box);
            display.window->draw(display.texts[display.action]);
        }
        display.window->display();
}