#include <iostream>

#include "faction.hpp"

int main()
{
    the_prince::Faction test("test");

    while(!test.Rebelion())
    {
        std::cout << "Attitude level " << test.GetAttitudeLevel() << std::endl;
        std::cout << "Influence level " << test.GetInfluenceLevel() << std::endl;
        switch(rand()%4)
        {
            case 0:
                test.DecreaseAttitudeLevel(1);
                break;
            case 1:
                test.DecreaseInfluenceLevel(1);
                break;
            case 2:
                test.IncreaseAttitudeLevel(1);
                break;
            case 3:
                test.IncreaseInfluenceLevel(1);
                break;
            default:
                break;
        }
    }
    std::cout << "Reblion has occured\n";

    return 0;
}