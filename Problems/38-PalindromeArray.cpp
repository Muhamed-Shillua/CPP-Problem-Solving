#include <iostream>
using namespace std;

/*
    Program Name   : Palindrome Array Check
    Description    : Checks if a given array is a palindrome (reads the same forward and backward).
    Solution       :
        - The array is hardcoded with symmetric values for testing purposes.
        - The program prints the array elements.
        - It then compares each element with its corresponding element from the opposite end.
        - If all such pairs match, the array is identified as a palindrome.
        - The result is printed to the user.
*/


void HardCodedArray(int Array[], short& ArrayLength)
{
    ArrayLength = 8;  // Set the array length to 8 elements

    // Hard-coded values to the array (mirrored from both ends)
    Array[0] = 10;
    Array[1] = 20;
    Array[2] = 30;
    Array[3] = 40;
    Array[4] = 40;
    Array[5] = 30;
    Array[6] = 20;
    Array[7] = 10;
}

// Displays all elements of an array in a readable format.
void PrintArrayElements(int Array[], short ArrayLength)
{
    cout << "[ ";
    for (int i = 0; i < ArrayLength; i++)
    {
        if (i > 0) cout << ", ";
        cout << Array[i];
    }
    cout << " ]\n";
}

// Checks if the array is a palindrome.
bool IsPalindrome(int Array[], short ArrayLength)
{
    for (int i = 0; i < ArrayLength / 2; i++)
    {
        // Compare mirrored elements
        if (Array[i] != Array[ArrayLength - 1 - i])
            return false;
    }
    return true;
}

// Prints the array and whether it is a palindrome.
void PrintResult(int Array[], short& ArrayLength)
{
    // Print the array first
    PrintArrayElements(Array, ArrayLength);

    // Check if it's a palindrome and print the result
    if (IsPalindrome(Array, ArrayLength))
    {
        cout << "Array is Palindrome." << endl;
    }
    else
    {
        cout << "Array is not Palindrome." << endl;
    }
}

int main()
{
    int OriginalArray[100];           // Declare an array with enough space
    short OriginalArrayLength = 0;    // To hold the actual used length

    // Fill the array with hardcoded values
    HardCodedArray(OriginalArray, OriginalArrayLength);

    // Display result after checking if array is a palindrome
    PrintResult(OriginalArray, OriginalArrayLength);

    cout << endl;
    return 0;
}
