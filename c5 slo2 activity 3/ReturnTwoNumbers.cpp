// C5 SLO 2 Activity 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jamie Gavina jgavina@cnm.edu
//main

#include "ReturnTwoNumbers.h"



int main()
{

    int num1;
    int num2;
    int bigone;
    int& a = num1;
    int& b = num2;
    Writeheader();
    AskForTwoNumbers( num1,  num2);
    FindBigOne(num1,num2, bigone);

    cout << "These numbers are using references for my integers \n";
    if (num1 > num2)
    {

        num1 = bigone;
        cout << "The larger number is: " << &a << endl;

    }
    else if (num2 > num1)
    {

        num2 = bigone;
        cout << "The larger nunber is: " << &b << endl;

    }
    else if (num1 == num2)
    {

        cout << "These numbers are equal \n";

    }
    else
    {

        cout << "Invalid entry please try again. \n";

    }
    GoAgain();

    return 0;
}


