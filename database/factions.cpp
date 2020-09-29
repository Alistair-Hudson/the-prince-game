/******************************************************************************
 *	Title:		Faction Database
 *	Authour:	Alistair Hudson
 *	Reviewer:	
 *	Version:	25.08.2020.0
 ******************************************************************************/
#include <iostream>

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
void the_prince::CreateFactionMap(std::map<the_prince::FACTION, Faction>& map)
{
    map.insert({MILITARY, Faction("Military")});
    map.insert({LAWENFORCEMENT, Faction("Law Enforcement")});
    map.insert({PUBLIC, Faction("General Public")});
    map.insert({TREASURY, Faction("Treasury")});
    map.insert({CHURCH, Faction("Church")});
    map.insert({MERCHANTS, Faction("Merchant Guild")});
    map.insert({ALCHEMISTS, Faction("Alchemist Guild")});
    map.insert({SHIPWRIGHTS, Faction("Ship Wrights")});
    map.insert({FARMERS, Faction("Farmers")});
    map.insert({FISHERIES, Faction("Fisheries")});
    
    //General Public has an influence level of 100 at all times
    map.find(PUBLIC)->second.IncreaseInfluenceLevel(100);
}