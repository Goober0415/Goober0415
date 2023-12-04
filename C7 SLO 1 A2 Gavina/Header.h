#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace std;

struct Distance
{
	int feet{ 0 };
	int inches{ 0 };
};

void WriteHeader();
void Goodbye();
bool DoAgain();
void AskForDistances(Distance& d1, Distance& d2);
Distance CalcTotalDistance(Distance d1, Distance d2);

#endif