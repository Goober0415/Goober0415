#include "Header.h"

void WriteHeader()
{
	cout << "Program Title: Distance Calculator" << endl;
	cout << "Program Objective: This program calculates the sum of two distances." << endl;
}

void Goodbye()
{
	cout << "Goodbye!" << endl;
}

bool DoAgain()
{
	char response;
	cout << "Do you want to do another calculation? (y/n): ";
	cin >> response;
	cin.ignore();
	return response == 'y' || response == 'Y';
}

void AskForDistances(Distance& d1, Distance& d2)
{
	cout << "Enter the first distance in feet: ";
	cin >> d1.feet;
	cout << "Enter the first distance in inches: ";
	cin >> d1.inches;
	cout << "Enter the second distance in feet: ";
	cin >> d2.feet;
	cout << "Enter the second distance in inches: ";
	cin >> d2.inches;
}

Distance CalcTotalDistance(Distance d1, Distance d2)
{
	Distance totalD;
	totalD.feet = d1.feet + d2.feet;
	totalD.inches = d1.inches + d2.inches;
	if (totalD.inches >= 12) {
		totalD.feet += totalD.inches / 12;
		totalD.inches %= 12;
	}
	return totalD;
}
