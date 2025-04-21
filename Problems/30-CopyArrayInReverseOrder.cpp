#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Random Array Generator and Reverse Copy
    Description    : Generates a random array of numbers and creates a copy of the array in reverse order.
    Solution       :
        - Based on problem number #26 which deals with arrays and copying elements.
        - User Input: Number of array elements.
        - Fills the array with random numbers from 1 to 100.
        - Copies the array elements to a new array in reverse order.
        - Prints both the original and reversed arrays.
*/

int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);  // Ensure the number is positive (greater than zero)

    return Number;
}

int GenerateRandomNumber(int From, int To)
{
    return (rand() % (To - From + 1)) + From;  // Generate a number in the range [From, To]
}

// Fills an array with random integers between 1 and 100
void FillArrayWithRandomNumbers(int Array[], short ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100); 
    }
}

void PrintArray(int Array[], short ArrayLength)
{
    cout << "[";
    for (int i = 0; i < ArrayLength; i++)
    {
        if (i > 0) cout << ", ";   // Print a comma for all elements except the first one
        cout << Array[i];         // Print each element of the array
    }
    cout << "]\n";
}

// Copies content from Original Array into a new array in reverse order
void CopyArrayElements(int OriginalArray[], int Array1[], short ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array1[i] = OriginalArray[ArrayLength - i - 1];
    }
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator

    const int MAX_SIZE = 100;
    int Array[MAX_SIZE];
    short ArrayLength = ReadNumber("Enter Array Length: ");

    FillArrayWithRandomNumbers(Array, ArrayLength);

    cout << "\nOriginal Array : ";
    PrintArray(Array, ArrayLength);

    int Array1[MAX_SIZE];
    CopyArrayElements(Array,Array1, ArrayLength);

    cout << "Array After Copying : ";
    PrintArray(Array1, ArrayLength);

    return 0;
}
