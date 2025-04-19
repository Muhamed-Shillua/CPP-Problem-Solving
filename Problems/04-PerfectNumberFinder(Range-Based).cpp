#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Perfect Numbers Finder (Range-Based)
    Description    : This program reads a positive integer from the user,
                     then iterates through all numbers from 1 to that integer,
                     and prints only the perfect numbers within that range.

                     This problem is based on the solution from Problem #03 
                     ("Perfect Number Finder") which checks if a single number
                     is perfect or not. In this version, we extend it by checking 
                     all numbers from 1 to the user-specified number.

    A perfect number is defined as a positive integer that is equal to 
    the sum of its proper positive divisors, excluding itself.

    Example        : 
                     Input: 10
                     Output: 6  (Perfect)

                     Input: 100
                     Output: 6, 28 (Perfect Numbers within 1 to 100)

*/


// Status codes used to label whether a number is Perfect or Not
enum enPerfectStatus
{
    Perfect = 1,
    NotPerfect = 2
};

// Function to check if the number is perfect by calculating the sum of its divisors
enPerfectStatus CheckNumberStatus(int Number)
{
    int Sum = 0;

    // Loop through all possible divisors up to half of the number
    for (int counter = 1; counter <= Number / 2; ++counter)
    {
        // If the counter divides the number with no remainder, it's a divisor
        if (Number % counter == 0)
        {
            Sum += counter;
        }
    }

    // Check if the sum of divisors equals the number itself
    return (Number == Sum) ? enPerfectStatus::Perfect : enPerfectStatus::NotPerfect;
}

// Loops through the range from 1 to the given number
// and prints only the numbers that are identified as Perfect.
void PrintNumberStatus(int Number)
{
    cout << "\n=========== Perfect Numbers ===========\n";

    for (int i = 1; i <= Number; i++)
    {
        if (CheckNumberStatus(i) == enPerfectStatus::Perfect)
        {
            cout << i << endl;
        }
    }

    cout << "=======================================\n";
}

// Function to read a positive number from the user, ensuring it's greater than 0
int ReadPositiveNumber(const string& Message)
{
    int Number;

    // Keep asking the user until a valid positive number is entered
    do
    {
        cout << Message;
        cin >> Number;
        if (Number <= 0)
            cout << "PlZ Enter a Positive Number Greater than zero.\n";
    } while (Number <= 0);

    return Number;
}

int main()
{
    // The program flow starts by reading a positive number from the user
    // and then passing that number to the printer function which filters perfect numbers.

    // Using 'auto' to let the compiler infer the type of 'number'
    // The type is automatically deduced based on the function's return type (which is 'int')
    const auto Number = ReadPositiveNumber("Plz Enter a Number: ");

    // Check and print all perfect numbers from 1 to the given number
    PrintNumberStatus(Number);

    return 0;
}
