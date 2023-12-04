//Ivonne Nelson
//inelson1@cnm.edu

//MortCalc.cpp

//#include <sstream> Moved this line to the header file
//using namespace std; removed this as it is repeated
//must include the header file
#include "mortcalc.h"

void Header()
{
	//Need to delete the semi-colon because it finishes the statement
	cout << "The Mortgage Calculator"
		<< "\n\n This program calculates monthly payment and total interest"
		<< "\n given a principal, interest rate, and time period." << endl;

}

double AskPrin()
{
	double prin{ 0.0 };
	cout << "\n\nWhat is the principle amount of the loan? (digits only, no commas): ";
	cin >> prin;

	return prin;
}
double AskInterest()
{
	double interest{ 0.0 };
	cout << "\nWhat is the interest rate of the loan? (i.e., 5.5%): ";
	cin >> interest;

	return interest;
}
int AskYears()
{
	//typo - needs to be years
	int years { 0 };
	cout << "\nWhat is the duration of the loan in years?: ";
	cin >> years;

	return years;
}

bool Validate(double prin, double interest, int years)
{
	//The choice is that the duration of the loan can be 15, 25 or 30 years.  Not anything else.
	//principle can not be greater that 500000 or less than 0
	//interest can't be less than 0 or greater than 10

	bool valid{ true };
	//Delete the ; because it ends the if statement before it is done.
	if (prin > 500000 || prin <= 0)//;
		valid = false;
	if (interest <= 0 || interest > 10)
		valid = false;
	//Change second 15 to 25 years, because that is the correct number
	if (!(years == 15 || years == 25 || years == 30))
		valid = false;

	return valid;
}
//Calculation of monthly payment
string MortCalc(int years, double prin, double interest)
{

	stringstream ss;
	double monPay{ 0.0 };
	double totInt{ 0.0 };

	double totalLoan{ 0.0 };
	int q{ 12 };           //payments per year
	double x{ 0.0 }, y{ 0.0 }, z{ 0.0 };
	interest = interest / 100.0;

	x = -(years * q);             //exponent
	y = 1 + (interest / q);
	z = pow(y, x);


	//Monthly payment calculation	
	monPay = (prin * interest) / (q * (1 - z));



	//Total loan calculation
	totalLoan = monPay * years * q;

	//Total interest calculation
	totInt = totalLoan - prin;


	ss.precision(2);
	ss.setf(ios::fixed);

	ss << "\n Results: \n To borrow $" << prin << " for " << years << " years at "
		<< interest * 100 << "% interest,\n You will have a monthly payment of $"
		<< monPay << "\n You will pay $" << totInt << " in interest"
		<< "\n and $" << totalLoan << " over the length of the loan";

	//convert the string
	return ss.str();

}

void Goodbye()
{
	cout << "\n Thanks for your \"interest\". \n\n";
}

bool DoAgain()
{
	string doAgain;
	cout << "\n\n Do you want to calculate another Wind Chill? yes/no    ";
	getline(cin, doAgain);
	if (doAgain == "yes")
	{
		return true;
	}
	return false;
}
