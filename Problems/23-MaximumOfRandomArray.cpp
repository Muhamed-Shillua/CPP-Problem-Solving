#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Random Array Generator and Maximum Finer
    Description    : This program generates a random array of numbers based on user input.
                     The user is prompted to enter the number of elements in the array,
                     and each element is filled with a random number between 1 and 100.
                     The program then finds and prints the maximum number from the array.
    Solution       :
        - Based on problem number #22 which involved working with arrays, random numbers,
          and finding maximum values.
        - User Input: The user is asked to input the number of elements they want in the array.
        - The program generates a random number for each element in the array (between 1 and 100).
        - The program prints the array of random numbers and also identifies the maximum value
          in the array and displays it.
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

// Function to read array elements number from the user (in this case, fill them with randomly)
void ReadArrayElements(int Array[], short& ArrayLength)
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

void MaxOfArray(int Array[], short ArrayLength)
{
    int MaxNumber = Array[0];  // Start with the first element as the max value

    // Loop through the array to find the maximum value
    for (int i = 1; i < ArrayLength; i++)  // Start from the second element
    {
        if (Array[i] > MaxNumber)
        {
            MaxNumber = Array[i];  // Update max if current element is greater
        }
    }

    cout << "\nThe Maximum Number In ";
    PrintArrayElements(Array, ArrayLength);
    cout << " is: " << MaxNumber << endl;
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator with current time

    int Array[100];
    short ArrayLength;

    // Read the array elements
    ReadArrayElements(Array, ArrayLength);

    // Find and print the maximum value in the array
    MaxOfArray(Array, ArrayLength);

    return 0; 
}
