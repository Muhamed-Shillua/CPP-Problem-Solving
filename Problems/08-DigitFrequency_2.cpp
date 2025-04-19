#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Digit Frequency Counter
    Description    : This program takes a positive integer and a digit to check, then counts how many times the digit appears in the number.
    Solution       :
                     Based on Problem #05 and Problem #07:
                     The solution builds upon the logic used in Problem #05 and Problem #07,where we extract digits.
                     In those problems, we extracted digits from a number
                     but Here, we go further by checking the frequency of each digit from 0 to 9** in the given number.
                     For each digit, we use a helper function that loops through the number to count how many times that digit appears.
*/

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0); // Repeat until a positive number is entered

    return Number;
}

short CountDigitsFrequency(int Number,int DigittoCheck)
{
    short Counter= 0;

    // Continue looping while there are digits left in Number.
    while (Number > 0)
    {
        // Check if the last digit of the number matches the digit to check
        if (DigittoCheck == Number % 10)
        {
            Counter++;
        }
        Number = Number / 10;    // Remove the last digit by dividing the number by 10

    }

    return Counter;
}

void PrintAllDigitsFrequency(int Number)
{
    cout << "\n=====================================\n";

    // Loop through digits 0 to 9 and print frequency
    for (int i = 0;i <= 9;i++)
    {
        short DigitsFrequency = 0;
        DigitsFrequency = CountDigitsFrequency(Number, i);

        // Only print digits that actually appear at least once
        if (DigitsFrequency > 0)
        cout << "The digit " << i << " appears " << DigitsFrequency << " time(s) in the number.\n";
    }
    cout << "\n=====================================\n";
    
}

int main()
{
    int Number = ReadPositiveNumber("Plz Enter a Number: ");

    // Call the function to count the digit frequency and print the result
    PrintAllDigitsFrequency(Number);
    

    return 0;
}
