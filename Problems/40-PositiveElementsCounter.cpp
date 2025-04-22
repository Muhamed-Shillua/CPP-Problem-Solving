#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Positive Elements counter
    Description    : This program count only the Positive numbers from a random array.
    Solution       :
        - Based on a basic input-handling and filtering task to separate odd elements.
        - User Input:
            * The user enters the number of elements for the array.
        - Random Numbers:
            * Numbers are randomly generated between -100 and 100 and stored in the original array.
        - The program filters Positive numbers from the array and count them.
        - Both the Array and Positive elements number displayed to the user.
*/


int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);  // Repeat until a positive number is entered

    return Number;
}

int GenerateRandomNumber(int From, int To)
{
    return (rand() % (To - From + 1)) + From;
}

// Fills an array with random numbers between -100 and +100
void FillArrayWithElements(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");

    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(-100, 100);
    }
}

// Prints array elements in a formatted way
void PrintArrayElements(int Array[], short ArrayLength)
{
    cout << "[";
    for (int i = 0; i < ArrayLength; i++)
    {
        if (i > 0) cout << ", ";
        cout << Array[i];
    }
    cout << "]";
}

// The Counter is updated to track how many odd elements
short CountPositiveElements(int Array[], short& ArrayLength)
{
    short Counter = 0;
    // Loop through each element of the array
    for (int index = 0;index < ArrayLength;index++)
    {
        if (Array[index] > 0)
        {
            Counter++;
        }
    }
    return Counter;
}

int main()
{
    srand((unsigned)time(NULL));    // Seed the random number generator with current time

    int Array[100];
    short ArrayLength = 0;

    // Fill array with random numbers
    FillArrayWithElements(Array, ArrayLength);

    // Display both array and positive Elements Number
    cout << "\nArray Elements       : ";
    PrintArrayElements(Array, ArrayLength);
    cout << "\nPositive Elements Number  = " << CountPositiveElements(Array, ArrayLength)<<" element.";

    cout << endl;
    return 0;
}
