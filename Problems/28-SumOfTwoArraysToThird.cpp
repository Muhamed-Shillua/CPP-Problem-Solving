#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

using namespace std;

/*
    Program Name   : Random Array Generator and Sum Calculator
    Description    : Generates two random arrays of integers, sums corresponding elements, 
                     and stores the result in a third array.
    Solution       :
        - Based on problem number #22 that deals with arrays and basic arithmetic.
        - User Input: Number of elements to generate in each array.
        - Fills Array1 and Array2 with random numbers in range [1, 100].
        - Array3[i] = Array1[i] + Array2[i].
        - Displays all three arrays.
*/

int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);  // Ensures user enters a value > 0

    return Number;
}

// Generates a random integer within the given inclusive range [From, To]
int GenerateRandomNumber(int From, int To)
{
    return (rand() % (To - From + 1)) + From;
}

// Fills the given array with random integers between 1 and 100
void FillArrayWithElements(int Array[], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);
    }
}

// Displays the elements of an array in a formatted line
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

// Sums the corresponding elements of Array1 and Array2 and stores the result in Array3
void SumInNewArray(int Array1[], int Array2[], int Array3[], int ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array3[i] = Array1[i] + Array2[i];  // Element-wise sum
    }
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator using system time

    int Array1[100], Array2[100], Array3[100];
    short ArrayLength = ReadNumber("Enter Array Length: ");

    // Step 1: Generate two random arrays
    ReadArrayElements(Array1, ArrayLength);
    ReadArrayElements(Array2, ArrayLength);

    // Step 2: Display both arrays
    cout << "\nArray 1 Elements = ";
    PrintArrayElements(Array1, ArrayLength);

    cout << "\nArray 2 Elements = ";
    PrintArrayElements(Array2, ArrayLength);

    // Step 3: Compute element-wise sum of Array1 and Array2 into Array3
    SumInNewArray(Array1, Array2, Array3, ArrayLength);

    // Step 4: Display the resulting array
    cout << "\nArray 3 Elements (Sum of A1 + A2) = ";
    PrintArrayElements(Array3, ArrayLength);

    cout << endl;
    return 0;
}
