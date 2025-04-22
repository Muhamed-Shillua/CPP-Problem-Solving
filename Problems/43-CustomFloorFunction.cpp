#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Custom Floor Function
    Description    : Implements a manual version of the floor operation
                     by truncating the decimal part of a float number.
    Solution       :
        - Prompts the user to input a float number.
        - The number is truncated using type casting to an integer.
        - The result is equivalent to the floor for positive numbers.
*/

// Reads a float number from the user with a custom message
float ReadNumber(string Message)
{
    float Number = 0;

    cout << Message;
    cin >> Number;

    return Number;
}

// Manually calculates the floor of a float number, including negative values
int MyFloor(float Number)
{
    int IntPart = (int)Number;
    return (Number < 0 && Number != IntPart) ? IntPart - 1 : IntPart;
}

int main()
{
    float Number = ReadNumber("Please Enter a Number: ");

    cout << "My Floor Result = " << MyFloor(Number);

    cout << endl;
    return 0;
}
