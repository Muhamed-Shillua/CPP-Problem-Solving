#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Prime Number Finder
    Description    : This program reads a positive integer from the user,
                     then iterates through all numbers from 1 to that integer,
                     and prints only the prime numbers.

    A prime number is defined as a positive integer greater than 1
    that is only divisible by 1 and itself.

    Example        : 7 -> Prime
                     4 -> Not Prime
                     13 -> Prime
*/


enum enPrimeStatus
{
    Prime = 1,
    NotPrime = 2
};

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message ; cin >> Number;
    } while (Number <= 0);

    return Number;
}

enPrimeStatus CheckNumberType(int Number)
{
    // Why up to half (Number / 2)? Because any number greater than half 
    // cannot divide the number (except the number itself), 
    // // and we already exclude that case.
    if (Number == 1)
    {
        return enPrimeStatus::NotPrime;
    }

    for (int counter = 2;counter <= Number / 2;counter++)
    {
        if (Number % counter == 0)
            return enPrimeStatus::NotPrime;
    }

    return enPrimeStatus::Prime;
}

void PrintPrimeNumbersFrom_1_to_N(int Number)
{
    cout << "\n====================================\n";
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;

    // Loop through all numbers from 1 to Number and Print the Prime one
    for (int i = 1;i <= Number;i++)
    {
        if (CheckNumberType(i) == enPrimeStatus::Prime)
        {
            cout << i << endl;
        }
    }

    cout << "\n====================================\n";
}


int main()
{
    PrintPrimeNumbersFrom_1_to_N(ReadPositiveNumber("Plz Enter a positive Number: "));

    return 0;
}