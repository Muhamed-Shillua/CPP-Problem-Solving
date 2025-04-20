#include <iostream>   
#include <string>     
using namespace std;  

/*
    Program Name   : Inverted Letter Pattern
    Description    : This program prints an inverted pattern made of capital letters.
    Solution:
        - The user enters a positive number N.
        - The pattern has N rows.
        - Each row contains the same letter printed multiple times.
        - The first row uses the letter 'A' + (N - 1), printed N times.
        - Each next row uses the previous letter - 1, printed (N - current row + 1) times.
*/

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message; cin >> Number;       
    } while (Number <= 0);   // Keep looping if the input is not a positive number.

    return Number;           
}

// Prints the pattern where each row contains the same letter decreasing by one per row.
//           The number of letters in each row also decreases.
void PrintInvertedLetterPattern(int Number)
{
    // Outer loop for the number of rows (from Number down to 1)
    for (int i = Number; i >= 1; i--)
    {
        char Letter = char(i + 65 - 1); // Convert the row index to its corresponding uppercase ASCII letter

        // Inner loop to print the letter i times in the current row
        for (int j = 1; j <= i; j++)
        {
            cout << Letter;  // Print the current letter
        }

        cout << endl;        // Move to the next line after printing one row
    }
}

int main()
{
    // Step 1: Ask the user to enter a positive number
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    // Step 2: Print the inverted letter pattern based on the input
    PrintInvertedLetterPattern(Number);



    return 0;  
}
