#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Random Array Generator and Sum Calculator
    Description    : Generates a random array of numbers and calculates the total sum.
    Solution       :
        - Based on problem number #22 that deals with arrays and basic arithmetic.
        - User Input: Number of array elements.
        - Fills the array with random numbers from 1 to 100.
        - Calculates and prints the total sum of all elements.
*/

int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0);  // Ensure the number is positive (greater than zero)

    return Number;   // Return the valid number
}

int GenerateRandomNumber(int From, int To)
{
    return (rand() % (To - From + 1)) + From;  // Generate a number in the range [From, To]
}

// Fill Array With Elements number from the user (in this case, fill them with randomly)
void FillArrayWithElements(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");  

    // Loop to add each element of the array randomly
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);  // Generate a random number between 1 and 100
    }
}

void PrintArrayElements(int Array[], short ArrayLength)
{
    cout << "Your Array = [ ";

    // Loop through and print each element in the array
    for (int i = 0; i < ArrayLength; i++)
    {
        // Print a comma if it's not the first element
        if (i > 0) cout << ", ";
        cout << Array[i];  // Print the current element
    }
    cout << " ]"; // End of array printout
}

void SumOfArrayElements(int Array[], short ArrayLength)
{
    int Sum = 0;  // Start with the first element as the max value

    // Loop through and get each element in the array
    for (int i = 0; i < ArrayLength; i++)  // Start from the second element
    {
        Sum += Array[i]; // Add each element to the sum
    }

    cout << "\nThe Sum of ";
    PrintArrayElements(Array, ArrayLength); // Print Sum and the array itself
    cout << " Elements = " << Sum << endl; //  To Calculate the average,Simply divide the sum by the array length
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator with current time

    int Array[100];
    short ArrayLength;

    FillArrayWithElements(Array, ArrayLength);

    // // Print Sum and the array itself
    SumOfArrayElements(Array, ArrayLength);

    return 0; 
}
