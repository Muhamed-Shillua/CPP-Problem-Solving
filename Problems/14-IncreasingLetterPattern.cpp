#include <iostream>   
#include <string>     
using namespace std;  

/*
    Program Name   : Increasing Letter Pattern
    Description    : This program prints a pattern of increasing letters.
                      The outer loop structure differs from problem #13.
    Solution:
        - The user enters a positive number N.
        - The pattern prints N rows, each row containing a letter printed multiple times.
        - The first row uses 'A', the second 'B', and so on.
*/

int ReadPositiveNumber(string Message)
{
    int Number = 0; 

    do
    {
        cout << Message;    
        cin >> Number;      
    } while (Number <= 0);  // Keep looping if the input is not a positive number.

    return Number; 
}

// Prints a pattern of increasing letters, where each letter is printed multiple times
//           depending on the row number.
void PrintIncreasingLetterPattern(int Number)
{
    for (int i = 1; i <= Number; i++)
    {
        // Calculate the character to print (e.g., A for i=1, B for i=2, ...)
        char Letter = char('A' + i - 1);

        for (int j = 1; j <= i; j++)
        {
            cout << Letter;
        }
        cout << endl;
    }
}

int main()
{
    int Number = ReadPositiveNumber("Please enter a positive number: ");

    PrintIncreasingLetterPattern(Number);

    return 0;
}
