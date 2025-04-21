#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Prime Elements Copier
    Description    : This program copies only the Prime numbers from a random array to a new array.
    Solution       :
        - Based on a basic input-handling and filtering task to separate odd elements.
        - User Input:
            * The user enters the number of elements for the array.
        - Random Numbers:
            * Numbers are randomly generated between 1 and 100 and stored in the original array.
        - The program filters Prime numbers from the original array and copies them to a second array.
        - Both arrays (original and Prime-numbered) are displayed to the user.
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
void ReadArrayElements(int Array[], short& ArrayLength)
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

// Increments array Length by 1 and assigns the new element to the last position
void AddElementToArray(int Element, int Array1[], short& Array1Length)
{
    Array1Length++;

    Array1[Array1Length - 1] = Element;
}

// Reused Function to Check if the Element is Prime
bool IsPrime(int Number)
{
    if (Number <= 1)
        return false;

    // Optimization: no need to check beyond square root of the number
    for (int i = 2; i <= sqrt(Number); i++)
    {
        if (Number % i == 0)
            return false; // If divisible by any number other than 1 and itself
    }
    return true;
}

// The length of Array1 (Array1Length) is updated by reference to track how many odd elements were added.
void CopyPrimeElements(int OriginalArray[], short OriginalArrayLength, int Array1[], short& Array1Length)
{
    // Loop through each element of the original array
    for (int index = 0;index < OriginalArrayLength;index++)
    {
        if (IsPrime(OriginalArray[index]))
        {
            // If Prime, assign it to the new array using the AddArrayElement function
            AddElementToArray(OriginalArray[index], Array1, Array1Length);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));    // Seed the random number generator with current time

    int OriginalArray[100], Array1[100];
    short OriginalArrayLength, Array1Length = 0;

    // Fill original array with random numbers
    ReadArrayElements(OriginalArray, OriginalArrayLength);

    // Copy original array to another
    CopyPrimeElements(OriginalArray, OriginalArrayLength, Array1, Array1Length);

    // Display both arrays to verify the copy
    cout << "\nOriginal Array Elements       : ";
    PrintArrayElements(OriginalArray, OriginalArrayLength);

    cout << "\nArray 1 Elements After Copying: ";
    PrintArrayElements(Array1, Array1Length);

    cout << endl;
    return 0;
}
