#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Digit Frequency Counter
    Description    : This program takes a positive integer and a digit to check, then counts how many times the digit appears in the number.
    Solution       :
         We use a loop to check each digit of the number. The last digit of the number is compared with the digit to check.
         If they match, we increase the counter. The number is divided by 10 to remove the last digit until the number becomes zero.

    Based on Problem #05 - Reverse Number:
    The solution builds upon the logic used in Problem #05 (Reverse Number),
    where we extract digits, but here we count how many times the digit appears in the number instead of reversing them.

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

void PrintDigitsFrequency(short Counter, int DigittoCheck)
{
    cout << "\n=====================================\n";
    cout << "The digit " << DigittoCheck << " appears " << Counter << " time(s) in the number.\n";
}

int main()
{
    int Number = ReadPositiveNumber("Plz Enter a Number: ");
    int DigittoCheck = ReadPositiveNumber("Plz Enter a Digit (1-9): ");

    // Call the function to count the digit frequency and print the result
    PrintDigitsFrequency(CountDigitsFrequency(Number, DigittoCheck), DigittoCheck);
    

    return 0;
}
