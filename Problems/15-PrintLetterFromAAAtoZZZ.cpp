#include <iostream>   
#include <string>     
using namespace std;

/*
    Program Name   : Print Letter From AAA to ZZZ
    Description    : This program prints all possible combinations of three uppercase English letters from AAA to ZZZ.
    Solution:
         The program uses three nested loops to iterate through the ASCII values of the uppercase letters (65 to 90).
         It then prints each combination of three letters (AAA, AAB, AAC, ..., ZZZ).
         Each combination is printed on a new line.
*/

void PrintLetterFromAAAtoZZZ()
{
    // Loop through the first letter (A-Z)
    for (int i = 65; i <= 90; i++)
    {
        // Loop through the second letter (A-Z)
        for (int j = 65; j <= 90; j++)
        {
            // Loop through the third letter (A-Z)
            for (int y = 65; y <= 90; y++)
            {
                // Print the combination of letters
                cout << char(i) << char(j) << char(y) << endl;
            }
        }
        // Add a blank line after each set of combinations for the first letter
        cout << endl;
    }
}

int main()
{
    PrintLetterFromAAAtoZZZ();



    return 0;
}
