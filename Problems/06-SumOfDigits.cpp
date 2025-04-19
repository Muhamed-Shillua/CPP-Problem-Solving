#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Sum Of Number Digits
    Description    : This program takes a positive integer input from the user and calculates the sum of its digits.
    Solution:
         We use a loop to extract each digit of the number and add it to the sum.
         The number is divided by 10 in each iteration to remove the last digit until the number becomes zero.
		 
	Based on Problem #05 - Reverse Number:
    The solution builds upon the logic used in Problem #05 (Reverse Number), 
    where we extract digits, but here we sum the digits instead of reversing them.


    Example        : 12345 → 1 + 2 + 3 + 4 + 5 = 15
                     98765 → 9 + 8 + 7 + 6 + 5 = 35
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


int SumOfDigits(int Number)
{
    int SumOfDigits = 0;

    // Continue looping while there are digits left in Number.
    while (Number > 0)
    {
        SumOfDigits = Number % 10; // Add the last digit of Number to Sum.
        Number = Number / 10;    // Remove the last digit from Number.

    }

    return SumOfDigits;
}

void PrintSumOfDigits(int SumOfDigits)
{
    cout << "\n=====================================\n";
    cout << "The Sum of Number Digits = " << SumOfDigits;
}

int main()
{
    // Get user input, reverse it, and print the result
    PrintSumOfDigits(SumOfDigits(ReadPositiveNumber("Plz Enter a Number: ")));

    return 0;
}
