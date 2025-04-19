#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Digit Order Display
    Description    : This program takes a positive integer and prints its digits in the same order as entered.
    Solution:
        - Based on Problem #05:
          In Problem #05 we extract digits from a number using modulus and division.
        - In this version, we reverse the number first, so that when we extract and print each digit,
          it appears in the original order entered by the user.
*/

int ReadPositiveNumber(string Message)
{
    int Number = 0;

    // Keep asking the user until a valid positive number is entered
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

// Function to reverse a number (e.g., 123 becomes 321)
int ReverseNumber(int Number)
{
    int Remainder = 0, ReversedNumber = 0;

    // Loop through each digit of the number
    while (Number > 0)
    {
        Remainder = Number % 10; // Get the last digit
        Number = Number / 10;    // Remove the last digit
        ReversedNumber = (ReversedNumber * 10) + Remainder; // Build the reversed number
    }

    return ReversedNumber;
}

// Function to print each digit of the number in order
void PrintNumberInOrder(int ReversedNumber)
{
    int Remainder = 0;

    cout << "\n=====================================\n";
    cout << "Digits in order:\n";

    // Loop through the reversed number to print digits in original order
    while (ReversedNumber > 0)
    {
        Remainder = ReversedNumber % 10; // Get the last digit
        ReversedNumber /= 10;            // Remove the last digit
        cout << Remainder << endl;       // Print the digit
    }

    cout << "=====================================\n";
}

int main()
{
    // Step 1: Read number from user
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    // Step 2: Reverse the number and then print digits in original order
    PrintNumberInOrder(ReverseNumber(Number));

    return 0;
}
