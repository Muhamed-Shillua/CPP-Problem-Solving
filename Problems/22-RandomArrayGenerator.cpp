#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Random Array Generator
    Description    : This program generates a random array of numbers based on user input.
                     The user is prompted to enter the number of elements in the array,
                     and each element is filled with a random number between 1 and 100.
    Solution       :
        - Based on problem number #18 which involved working with arrays and random numbers
        - User Input: The user is asked to input the number of elements they want in the array
        - Generates a random number for each element in the array (between 1 and 100)
        - Prints the array of random numbers in a clean format
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

// Fill array elements from the user (in this case, fill them with random numbers)
void FillArrayWithElements(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");  // Ask user for the number of elements

    // Loop to add each element of the array randomly
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);  // Generate a random number between 1 and 100
    }
}

void PrintArrayElements(int Array[], short ArrayLength)
{
    cout << "\nYour Array = [ ";

    // Loop through and print each element in the array
    for (int i = 0; i < ArrayLength; i++)
    {
        // Print a comma if it's not the first element
        if (i > 0) cout << ", ";
        cout << Array[i];  // Print the current element
    }
    cout << " ]\n"; // End of array printout
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator with current time

    int Array[100];  
    short ArrayLength, NumberToCheck;

    FillArrayWithElements(Array, ArrayLength);  
    PrintArrayElements(Array, ArrayLength); 

    return 0;  // End of the program
}
