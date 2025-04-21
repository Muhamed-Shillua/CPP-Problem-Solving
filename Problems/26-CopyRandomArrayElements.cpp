#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Copy Random Array Elements
    Description    : Generates a random array and copies its content into another array.
    Solution       :
        - Based on Problem #22 related to arrays and copying techniques.
        - Prompts the user for number of elements.
        - Fills the original array with random numbers between 1 and 100.
        - Copies all elements to a new array.
        - Displays both arrays to confirm the copy.
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
    cout << "[ ";
    for (int i = 0; i < ArrayLength; i++)
    {
        if (i > 0) cout << ", ";
        cout << Array[i];
    }
    cout << " ]";
}

// Copies content from Origina lArray into anther one
void CopyArrayElements(int OriginalArray[], int CopiedArray[], short ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        CopiedArray[i] = OriginalArray[i];
    }
}

int main()
{
    srand((unsigned)time(NULL));    // Seed the random number generator with current time

    int OriginalArray[100], Array1[100];
    short ArrayLength;

    // Fill original array with random numbers
    FillArrayWithElements(OriginalArray, ArrayLength);

    // Copy original array to another
    CopyArrayElements(OriginalArray, Array1, ArrayLength);

    // Display both arrays to verify the copy
    cout << "\nOriginal Array Elements       : ";
    PrintArrayElements(OriginalArray, ArrayLength);

    cout << "\nArray 1 Elements After Copying: ";
    PrintArrayElements(Array1, ArrayLength);

    cout << endl;
    return 0;
}
