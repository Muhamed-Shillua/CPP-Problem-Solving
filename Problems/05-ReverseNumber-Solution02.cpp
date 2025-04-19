#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Reverse Number Solution 02
    Description    : This program reads a positive integer from the user,
                     reverses the digits of the number, and prints the result.

    Example        : 12345 → 54321
                     98765 → 56789
*/

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0); // Ensure the user enters a positive number

    return Number;
}


void PrintReversedNumber(int Number)
{
    int Remainder = 0;

    // Continue looping while there are digits left in Number.
    while (Number > 0)
    {
        Remainder = Number % 10; // Extract the last digit of Number.
        Number = Number / 10;    // Remove the last digit from Number.
        cout << Remainder ;  // Print the extracted digit.
    }
}

int main()
{
    // Get user input, reverse it, and print the result
    PrintReversedNumber(ReadPositiveNumber("Plz Enter a Number: "));

    return 0;
}
