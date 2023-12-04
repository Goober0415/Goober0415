//Typo was indicated with the extra _ 
#ifndef MORTCALC_H
#define MORTCALC_H

//MortCalc.h

//Function prototypes
#include <sstream>//added
#include <iostream>//added
#include <string>


using namespace std;

void Header();
double AskPrin();
double AskInterest();
int AskYears();
bool Validate(double prin, double interest, int years);


string MortCalc(int years, double principle, double interest);
void Goodbye();
bool DoAgain();

#endif
