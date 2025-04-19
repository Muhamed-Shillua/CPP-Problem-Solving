#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Reverse Number
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

int ReverseNumber(int Number)
{
    string ConvertedNumber = to_string(Number); // Convert number to string
    string ReversedNumber = "";

    // Reverse the string
    for (int c = ConvertedNumber.length() - 1; c >= 0; c--)
    {
        ReversedNumber += ConvertedNumber[c];
    }

    // Convert reversed string back to integer
    return stoi(ReversedNumber);
}

void PrintReversedNumber(int ReversedNumber)
{
    cout << "\nReversed Number = " << ReversedNumber << endl;
}

int main()
{
    // Get user input, reverse it, and print the result
    PrintReversedNumber(ReverseNumber(ReadPositiveNumber("Plz Enter a Number: ")));

    return 0;
}
