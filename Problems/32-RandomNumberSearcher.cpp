#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Random Number Searcher
    Description    : Generates an array of random numbers and allows the user to search for a specific number in the array.
    Solution       :
        - User Input: Number of elements in the array and a number to search for.
        - The program generates random numbers between 1 and 100 and fills an array.
        - The program searches the array for the specified number and prints the index/position where it is found.
        - If the number is not found, the program informs the user.
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

void FillArrayWithNumbers(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");  // Ask user for the number of elements

    // Loop to add each element of the array randomly
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);  // Generate a random number between 1 and 100
    }
}

void PrintArray(int Array[], short ArrayLength)
{
    cout << "\nThe Random Array: [";

    // Loop through and print each element in the array
    for (int i = 0; i < ArrayLength; i++)
    {
        // Print a comma if it's not the first element
        if (i > 0) cout << ", ";
        cout << Array[i];  // Print the current element
    }
    cout << "]\n\n"; // End of array printout
}

void GetNumberIndex(int Array[], short ArrayLength)
{
    int Number = ReadNumber("Enter a Number to search for: ");
    bool Found = false;  // Flag to track if the number is found

    cout << "\nSearching for the number " << Number << "...\n";

    // Loop to search the array for the number
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] == Number)
        {
            if (!Found)  // If it's the first occurrence, print a header
                cout << "The number " << Number << " is found at the following positions: \n";

            // Print the position where the number is found
            cout << "Index: " << i << " (Order: " << i + 1 << ")\n";
            Found = true;  // Mark that the number was found
        }
    }

    if (!Found)  // If the number was not found, print this message
    {
        cout << "\nSorry, the number " << Number << " was not found in the array.\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator

    const int MAX_SIZE = 100;
    int Array1[MAX_SIZE];
    short ArrayLength;

    FillArrayWithNumbers(Array1, ArrayLength);  // Fill the array with generated Numbers

    // Print the generated random array
    PrintArray(Array1, ArrayLength);

    // Search for a number in the array
    GetNumberIndex(Array1, ArrayLength);

    return 0;
}
