/*
    Program Name   : Absolute Value Calculator
    Description    : Computes the absolute value of a given integer using a custom function.
    Solution       :
        - Prompts the user to input an integer number.
        - Implements a custom function `MyABS` using a ternary operator:
            - Returns the number itself if it's non-negative.
            - Returns the negation if it's negative.
        - Displays the result to the user.
*/

#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string Message)
{
    int Number = 0;
    cout << Message;
    cin >> Number;
    return Number;
}

// Returns the absolute value of the input number using a ternary operator
int MyABS(int Number)
{
    return (Number < 0) ? -Number : Number;
}

int main()
{
    int Number = ReadNumber("Plz Enter a Number: ");
    cout << "My Abs Result = " << MyABS(Number) << endl;
    return 0;
}
