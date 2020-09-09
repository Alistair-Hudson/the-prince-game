/******************************************************************************
 *	Title:		Actions Database
 *	Authour:	Alistair Hudson
 *	Reviewer:	
 *	Version:	30.08.2020.0
 ******************************************************************************/
#include <iostream>
#include <string>
#include <map>

#include "database.hpp"

// using namespace the_prince;

/******MACROS******/

/******TYPEDEFS*****/

/****** GLOBAL VARIABLES*****/

/*****STRUCTS*******/

/*****CLASSES******/

/*****FUNCTORS*****/

/******INTERNAL FUNCTION DECLARATION******/ 

/******CLASS METHODS*******/

/*****FUNCTION DEFINITION******/
int the_prince::ActionInitiliser(Factory<ActParams>&  factory, TextHandler& text_map)
{
    //sf::Text text;
    std::string font("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf");
    // text.setString("This has been intentially left blank");
    // text.setFont(font);
    // text.setCharacterSize(24);
    // text.setFillColor(sf::Color::White);

    int actions_added = 0;

    text_map.AddText("This has been intentially left blank", font);
    //Add Fund Law Enforcement
    factory.AddAction(++actions_added, BuildFLE);
    text_map.AddText("Lord, our Law Enforcement need more funds\nWhat shall we do?\nType F = Fund, D = Defund or N = Do Nothing\n", font);
    //Add Open New Drydock
    factory.AddAction(++actions_added, BuildOND);
    text_map.AddText("Lord, if we open a new drydock we could increase trade and fisheries\nWhat shall we do?\nType O = Open, C = Close or N = Do Nothing\n", font);
    //Add Expand Fisheries
    factory.AddAction(++actions_added, BuildExF);
    text_map.AddText("Lord, if we expand our fishing zones we can feed the populace more\nWhat shall we do?\nType E = Expand, D = Decrease or N = Do Nothing\n", font);
    //Add New Relgion Arrives
    factory.AddAction(++actions_added, BuildNRA);
    text_map.AddText("Lord, a group claiming to be the chosen have entered the city, and are requesting we allow them in\nWhat shall we do?\nType A = Allow them in, D = Allow in and adopt their faith or T = Turn them away\n", font);
    //Add Fund Military
    factory.AddAction(++actions_added, BuildFdM);
    text_map.AddText("", font);
    //Add Increase Taxes
    factory.AddAction(++actions_added, BuildInT);
    text_map.AddText("", font);
    //Add Clear Land
    factory.AddAction(++actions_added, BuildCLn);
    text_map.AddText("", font);

    return actions_added;
}
