#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Fisher-Yates Shuffle
    Description    : Randomly shuffles the elements of an array using the Fisher-Yates algorithm.
    Solution       :
        - User Input: Number of elements to generate.
        - The array is filled with random integers between 1 and 100.
        - The Fisher-Yates shuffle algorithm is used to reorder the array elements randomly.
        - This method ensures uniform randomness without repetition or data loss.
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
void FillArrayWithRandomNumbers(int Array[], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        Array[i] = GenerateRandomNumber(1, 100);
    }
}

// Fisher-Yates Shuffle Algorithm: In-place randomization of array elements
void FisherYatesShuffle(int Array[], int Length)
{
    for (int i = Length - 1; i > 0; i--)
    {
        int j = GenerateRandomNumber(0, i); // Pick random index from 0 to i
        swap(Array[i], Array[j]); // Swap current element with the random one
    }
}

void PrintArray(int Array[], int Length)
{
    cout << "[";
    for (int i = 0; i < Length; i++)
    {
        if (i > 0) cout << ", ";
        cout << Array[i];
    }
    cout << "]\n";
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator

    const int MAX_SIZE = 100;
    int Array[MAX_SIZE];
    int Length = ReadNumber("Enter Array Length: ");
	
    FillArrayWithRandomNumbers(Array, Length);

    cout << "\nOriginal Array : ";
    PrintArray(Array, Length);

    FisherYatesShuffle(Array, Length);

    cout << "Shuffled Array : ";
    PrintArray(Array, Length);

    return 0;
}
