#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Inverted Number Pattern
    Description    : This program reads a positive integer and prints an inverted number pattern.
    Solution:
        - The user enters a positive integer N.
        - We print N rows.
        - In each row, the same number is printed (starting from N and decreasing to 1).
        - The number of times each number is printed equals its value.
*/


int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message; cin >> Number;     
    } while (Number <= 0); // Repeat until a valid positive number is entered

    return Number; 
}


// This Procedure takes a number and prints the pattern as described
void PrintInvertedNumberPattern(int Number)
{
    // Loop through each row, starting from 'Number' and going down to 1
    for (int i = Number; i >= 1; i--)
    {
        // Loop to print the number 'i' exactly 'i' times in the current row
        for (int j = 1; j <= i; j++)
        {
            cout << i; // Print the current number 'i'
        }
        cout << endl; // Move to the next line after printing a row
    }
}

int main()
{
    // Step 1: Read a positive number from the user
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    // Step 2: Print the inverted number pattern
    PrintInvertedNumberPattern(Number);



    return 0; 
}
