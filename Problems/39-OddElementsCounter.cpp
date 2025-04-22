#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Odd Elements In Array counter
    Description    : This program count only the odd numbers from a random array.
    Solution       :
        - Based on a basic input-handling and filtering task to separate odd elements.
        - User Input:
            * The user enters the number of elements for the array.
        - Random Numbers:
            * Numbers are randomly generated between 1 and 100 and stored in the original array.
        - The program filters odd numbers from the array and count them.
        - Both the Array and odd elements number displayed to the user.
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

// Fills an array with random numbers between 1 and 100
void FillArrayWithElements(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");

    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);
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
short CountOddElements(int Array[], short& ArrayLength)
{
    short Counter = 0;
    // Loop through each element of the original array
    for (int index = 0;index < ArrayLength;index++)
    {
        if (Array[index] % 2 != 0)	//if i want to count even elemnts change condition to (Array[index]%2 ==0)
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

    // Display both array and Odd Elements Number
    cout << "\nArray Elements       : ";
    PrintArrayElements(Array, ArrayLength);
    cout << "\nOdd Elements Number  = " << CountOddElements(Array, ArrayLength)<<" element.";

    cout << endl;
    return 0;
}
