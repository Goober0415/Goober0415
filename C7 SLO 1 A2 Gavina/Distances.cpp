// Distances.cpp : This file contains the 'main' function. Program execution begins and ends there.
//jgavina@cnm.edu Jamie Gavina

#include "Header.h"

int main()
{
    Distance d1, d2, totalD;

    WriteHeader();

    do
    {
        AskForDistances(d1, d2);
        totalD = CalcTotalDistance(d1, d2);

        std::cout << "The total distance is " << totalD.feet << " feet and " << totalD.inches << " inches." << std::endl;
    } while (DoAgain());

    Goodbye();

    return 0;
}
