#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Custom Ceil Function
    Description    : Computes the ceil (smallest integer greater than or equal) of a float number manually.
    Solution       :
        - Prompts the user to input a float number.
        - Implements a custom `MyCeil` function to calculate the ceil of the number.
        - Handles both positive and negative numbers appropriately.
        - Displays the result to the user.
*/

// Reads a float number from the user with a custom message
float ReadNumber(string Message)
{
    float Number = 0;
    cout << Message;
    cin >> Number;
    return Number;
}

// Manually calculates the ceil of a float number, handling both positive and negative values
int MyCeil(float Number)
{
    int IntPart = (int)Number;  // Get the integer part of the number

    // If the number is positive and has a fractional part, increase the integer part by 1
    // If the number is negative and has a fractional part, ceil it by moving towards zero
    return (Number > IntPart && Number > 0) || (Number < IntPart && Number < 0) ? IntPart + 1 : IntPart;
}

int main()
{
    float Number = ReadNumber("Please Enter a Number: ");
    cout << "My Ceil Result = " << MyCeil(Number) << endl;
    return 0;
}
