//Ivonne Nelson
//inelson1@cnm.edu

//Driver.cpp

//This program calculates monthly payment and total interest
//given a principal, interest rate, and time period.

//These lines removed, they are repeated
//#include <string> 
//using namespace std;
//Must include header file
#include "mortcalc.h"

int main()
{
	int years{ 0 };
	double prin{ 0.0 }, interest{ 0.0 };

	string result;
	string again{ "yes" };

	bool bvalid{ true };

	Header();

	do
	{
		prin = AskPrin();
		interest = AskInterest();
		years = AskYears();
		//typo the V should be lowercase in bValid
		bvalid = Validate(prin, interest, years);
		//typo the V should be lowercase in bValid
		if (bvalid)
		{
			result = MortCalc(years, prin, interest);
			cout << result;
		}
		else
			cout << "\n\n You input was not valid.  Try again.\n";

	//missing closing )
	} while (DoAgain());


	return 0;
}
