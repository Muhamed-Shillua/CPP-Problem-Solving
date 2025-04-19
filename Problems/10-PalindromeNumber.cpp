#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Palindrome Number Checker
    Description    : This program checks whether a given positive integer is a palindrome or not.
    Solution:
        - Based on Problem #05:
        - In Problem #05 we extract digits from a number using modulus and division.
        - In this version, we reverse the number first, then compare it with the original.
          If both are equal, the number is a palindrome.
*/

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0); // Repeat until a valid positive number is entered

    return Number;
}

// Reverses the digits of a number (e.g., 123 becomes 321)
int ReverseNumber(int Number)
{
    int Remainder = 0, ReversedNumber = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;                   // Extract the last digit
        Number = Number / 10;                      // Remove the last digit
        ReversedNumber = ReversedNumber * 10 + Remainder; // Append to reversed number
    }

    return ReversedNumber;
}

// Checks if a number is a palindrome and prints the result
void PrintNumberStatus(int Number)
{
    cout << "\n=====================================\n";
    cout << "Original Number: " << Number << endl;
    cout << "Reversed Number: " << ReverseNumber(Number) << endl;

    if (Number == ReverseNumber(Number))
    {
        cout << "Result         : Yes, the number is a palindrome.\n";
    }
    else
    {
        cout << "Result         : No, the number is not a palindrome.\n";
    }
    cout << "=====================================\n";
}

int main()
{
    // Step 1: Get input from user
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    // Step 2: Check if it's a palindrome and show the result
    PrintNumberStatus(Number);

    return 0;
}
