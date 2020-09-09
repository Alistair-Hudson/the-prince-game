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
void the_prince::CreateFactionMap(std::map<std::string, Faction>& map)
{
    map.insert({"Military", Faction("Military")});
    map.insert({"Law Enforcement", Faction("Law Enforcement")});
    map.insert({"General Public", Faction("General Public")});
    map.insert({"Treasury", Faction("Treasury")});
    map.insert({"Church", Faction("Church")});
    map.insert({"Merchant Guild", Faction("Merchant Guild")});
    map.insert({"Alchemist Guild", Faction("Alchemist Guild")});
    map.insert({"Ship Wrights", Faction("Ship Wrights")});
    map.insert({"Farmers", Faction("Farmers")});
    map.insert({"Fisheries", Faction("Fisheries")});
    

}