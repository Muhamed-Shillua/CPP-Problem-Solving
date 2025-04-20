#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Random Number Generator
    Description    : This program generates random numbers within a specified range using rand().
    Solution:
         - The program seeds the random number generator using the current time.
         - It then generates random numbers between From and To using:
               RandomNumber = (rand() % (To - From + 1)) + From;
         - This ensures the number is always within the desired range [From, To].
*/

int GenerateRandomNumber(int From, int To)
{
    return (rand() % (To - From + 1)) + From; 
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random generator once

    cout << GenerateRandomNumber(1, 10) << endl;
    cout << GenerateRandomNumber(1, 10) << endl;
    cout << GenerateRandomNumber(1, 10) << endl;
    cout << GenerateRandomNumber(1, 10) << endl;

    return 0;
}
