#include "ReturnTwoNumbers.h"


void Writeheader()
{

    cout << "Hello my name is Jamie \n";
    cout << "This program asks for two numbers and tells you which one is bigger then the other \n";

}

int AskForTwoNumbers(int num1, int num2)
{

    cout << "Please enter two integers not including zeros separated by a comma :) \n";
    cin >> num1, num2;
    cout << "You entered: " << num1 << "and " << num2 << endl;

    return (num1, num2);

}

int FindBigOne(int num1, int num2, int bigone)
{
   
    if (num1 > num2) 
    {
       
        num1 = bigone;
        cout << "The larger number is: " << bigone << endl;

    }
    else if (num2 > num1)
    {
        
        num2 = bigone;
        cout << "The larger nunber is: " << bigone << endl;

    }
    else if (num1 == num2)
    {

        cout << "These numbers are equal \n";

    }
    else
    {

        cout << "Invalid entry please try again. \n";

    }
    
    
    return 0;
}

string GoAgain()
{
    string answer;
    cout  << "Would you like to try another set of numbers? yes or no? \n";
    getline(cin, answer);
    if (answer == "yes")
    {
        int num1;
        int num2;
        int bigone;
        AskForTwoNumbers(num1, num2);
        FindBigOne(num1, num2, bigone);
        GoAgain();
    }
    else
    {
        cout << "Thank you for using our program, see you next time! :) \n";
    }
    return answer;
}
