#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Distinct Elements Copier
    Description    : This program copies distinct (non-repeated) elements from the original array into a new array.
    Solution       :
        - User Input:
            * The original array is filled with predefined numbers.
        - The program checks for duplicates in the original array and copies only the unique elements to a new array.
        - Both arrays are displayed to the user to verify the results.
*/


void FillArray(int Array[], short& ArrayLength)
{
    ArrayLength = 10;  // Set the array length to 10 elements

    // Hard Coded values to the array
    Array[0] = 10;
    Array[1] = 10;
    Array[2] = 10;
    Array[3] = 50;
    Array[4] = 50;
    Array[5] = 70;
    Array[6] = 70;
    Array[7] = 70;
    Array[8] = 70;
    Array[9] = 90;
}

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
void AddElementToArray(int Element, int Array[], short& ArrayLength)
{
    ArrayLength++;

    Array[ArrayLength - 1] = Element;
}

// Returns true if the number is found in the array, meaning it is not distinct.
bool IsDistinct(int Number, int Array[], short ArrayLength)
{
    bool Found = false;  // Flag to track if the number is found

    // Loop to search the array for the number
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] == Number)
        {
            Found = true;  // Mark that the number was found
            break;         // Exit the loop as we found the number
        }
    }

    return !Found; // Return true if the number is not found, meaning it's distinct
}

// The length of Array1 (Array1Length) is updated by reference to track how many distinct elements were added.
void CopyDistinctElements(int OriginalArray[], short OriginalArrayLength, int Array1[], short& Array1Length)
{
    // Loop through each element of the original array
    for (int index = 0; index < OriginalArrayLength; index++)
    {
        // If the element is not present in Array1, add it
        if (IsDistinct(OriginalArray[index],Array1,Array1Length))
        {
            AddElementToArray(OriginalArray[index], Array1, Array1Length);
        }
    }
}

int main()
{
    int OriginalArray[100], Array1[100];
    short OriginalArrayLength = 0, Array1Length = 0;

    // Fill original array with values
    FillArray(OriginalArray, OriginalArrayLength);

    // Copy distinct elements from OriginalArray to Array1
    CopyDistinctElements(OriginalArray, OriginalArrayLength, Array1, Array1Length);

    // Display both arrays to verify the copy
    cout << "\nOriginal Array Elements: ";
    PrintArrayElements(OriginalArray, OriginalArrayLength);

    cout << "\nArray 1 After Copying  : ";
    PrintArrayElements(Array1, Array1Length);

    cout << endl;
    return 0;
}
