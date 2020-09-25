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
    text_map.AddText("Lord, The military is short on funds.\nIf you were to allocate us more funds we could better defend the city.\n What shall we do\nF = Fund, D = Defund or N = Do Nothing\n", font);
    //Add Increase Taxes
    factory.AddAction(++actions_added, BuildInT);
    text_map.AddText("Lord, our coffers are looking a bit bare.\nI suggest we increase taxes to generate more revenue.\nWhat shall we do?\nI = Increase Taxes, D = Decrease Taxes or N = Do Nothing", font);
    //Add Clear Land
    factory.AddAction(++actions_added, BuildCLn);
    text_map.AddText("Lord, I suggeest we clear some more land so we may expand our farming.\nWhat shall we do?.\nC = Clear Land, D= Close Down Farms or N =Do Nothing.\n", font);
    //Add Crusade
    factory.AddAction(++actions_added, BuildCAF);
    text_map.AddText("Lord, we have been called to defend the Faith against the heathens\nWhat shall we do?\nC = Embark on a Crusade or N = Do Nothing", font);
    //Add Invade
    factory.AddAction(++actions_added, BuildINT);
    text_map.AddText("Lord, we should expand our domain.\nDoing so we could increase our resources and our influence.\nWhat shall we do?\nI = Invade Neighbouring territory or N = Do nothing", font);
    //Add Trade
    factory.AddAction(++actions_added, BuildTNN);
    text_map.AddText("Lord, I suggest we open a new trade route.\nWhat shall we do?\nO = Open new trade rout, C = Close a trade route or N = Do nothing.", font);
    //Add Festival
    factory.AddAction(++actions_added, BuildHdF);
    text_map.AddText("Lord, I suggest we hold a festival to boost everyone's morale.\nH = Hold festival or N = Do nothing.", font);
    
    //Add a period of no requests
    factory.AddAction(++actions_added, BuildNoReq);
    text_map.AddText("It is a quiet three months of no request.\nPress any key to continue", font);

    return actions_added;
}
