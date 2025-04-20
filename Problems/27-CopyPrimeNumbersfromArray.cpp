#include <iostream>
#include <string>
#include <cmath>     // For sqrt() function used in prime number checking
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time() to seed randomness

using namespace std;

/*
    Program Name   : Copy Prime Numbers from Array
    Description    : Generates random integers, stores them in an array,
                     then extracts only the prime numbers into a second array.
    Solution       :
        - Based on identifying prime numbers in an array of random values.
        - User inputs how many elements to generate.
        - Program fills array with random numbers from 1 to 100.
        - It then filters out prime numbers and stores them in a new array.
        - Both arrays are displayed to the user.
*/

int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0); // Ensures the number is greater than 0
    return Number;
}

// Generates a random integer between 'From' and 'To' (inclusive)
int GenerateRandomNumber(int From, int To)
{
    // Using modulus to constrain the range, then offset by 'From'
    return (rand() % (To - From + 1)) + From;
}

// Populates the array with random integers between 1 and 100
void ReadArrayElements(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");

    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);
    }
}

// Prints the elements of the array in a clean, formatted style
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

// Copies only the prime numbers from 'OriginalArray' to 'Array1'
void CopyPrimeElements(int OriginalArray[], int Array1[], short OriginalArrayLength, short& Array1Length)
{
    Array1Length = 0; // Start the copied array length from 0

    for (int i = 0; i < OriginalArrayLength; i++)
    {
        if (IsPrime(OriginalArray[i]))
        {
            Array1[Array1Length] = OriginalArray[i]; // Copy the prime number
            Array1Length++; // Move to the next index in the copied array
        }
    }
}

int main()
{
    // Seed the random number generator using current time
    srand((unsigned)time(NULL));

    int OriginalArray[100];
    short OriginalArrayLength;

    // Step 1: Fill original array with random values
    ReadArrayElements(OriginalArray, OriginalArrayLength);

    int Array1[100];
    short Array1Length = 0;

    // Step 2: Copy only prime numbers to Array1
    CopyPrimeElements(OriginalArray, Array1, OriginalArrayLength, Array1Length);

    // Step 3: Display both arrays
    cout << "\nOriginal Array Elements       : ";
    PrintArrayElements(OriginalArray, OriginalArrayLength);

    cout << "\nArray 1 Elements After Copying: ";
    PrintArrayElements(Array1, Array1Length);
    cout << endl;

    return 0;
}
