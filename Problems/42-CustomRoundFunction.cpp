#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Custom Round Function
    Description    : Implements manual rounding of a floating-point number to the nearest integer
                     without using built-in round functions.
    Solution       :
        - User is prompted to enter a float number.
        - The number is split into its integer and fractional parts.
        - If the fractional part is greater than or equal to 0.5, the integer is incremented.
        - Otherwise, the integer part is returned as is.
*/

// Reads a float number from the user with a custom message
float ReadNumber(string Message)
{
    float Number = 0;

    cout << Message;
    cin >> Number;

    return Number;
}

// Extracts and returns the fractional part of a float number
float GetFractionPart(float Number)
{
    return Number - (int)Number;
}

// Manually rounds a float number based on its fractional part
int MyRound(float Number)
{
    float FractionPart = GetFractionPart(Number);
    int IntPart = (int)Number;

    return (FractionPart >= 0.5) ? IntPart + 1 : IntPart;
}

int main()
{
    float Number = ReadNumber("Please Enter a Number: ");

    cout << "My Round Result = " << MyRound(Number);

    cout << endl;
    return 0;
}
