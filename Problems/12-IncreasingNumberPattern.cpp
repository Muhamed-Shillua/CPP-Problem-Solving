#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Increasing Number Pattern
    Description    : This program reads a positive integer and prints an increasing number pattern.
    Solution:
        - The user enters a positive integer N.
        - We print N rows.
        - In each row i, the number i is printed i times.
        - Example: if N = 5, the output is:
            1
            22
            333
            4444
            55555
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

// This procedure prints an increasing number pattern
void PrintIncreasingNumberPattern(int Number)
{
    // Loop through each row from 1 to Number
    for (int i = 1; i <= Number; i++)
    {
        // Print the number 'i' exactly 'i' times
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl; // Move to the next line after each row
    }
}

int main()
{
    // Step 1: Read a positive number from the user
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    // Step 2: Print the increasing number pattern
    PrintIncreasingNumberPattern(Number);

    return 0;
}
