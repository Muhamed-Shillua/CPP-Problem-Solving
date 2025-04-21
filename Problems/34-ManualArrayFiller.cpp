#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Manual Array Filler
    Description    : Allows the user to fill an array manually with integers until they choose to stop or the array reaches its maximum size.
    Solution       :
       - User Input:
            * The user enters one number at a time.
            * After each entry, the user is asked whether they want to continue.
        - The program stores the values in an array (up to 100 elements max).
        - Once input is complete, the array content is displayed in a clean format.
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

// Asks the user whether they want to continue entering more numbers
// Returns true if the user chooses to continue, false otherwise
bool CheckUserDecision()
{
    bool Response;
    cout << "Do you want to add more numbers? [1]: Yes, [0]: No\n";
    cin >> Response;

    // Validates input implicitly: any value other than 1 is treated as "No"
    return Response == 1;     
}

// Fills the array with user-provided numbers until the user decides to stop or the array is full
void FillArrayWithNumbers(int Array[], short& ArrayLength)
{
    int Number = 0;
    ArrayLength = 0; // Initialize the array length counter

    do
    {
        // Prevent overflow: stop if the array has reached its maximum allowed size
        if (ArrayLength >= 100)
        {
            cout << "Array is full!\n";
            break;
        }

        // Prompt the user to enter a number
        Number = ReadNumber("Enter a number: ");

        // Store the number in the array at the current index
        Array[ArrayLength] = Number;

        // Increment the length counter
        ArrayLength++;

    } while (CheckUserDecision()); // Loop continues as long as the user inputs '1' (yes)
}

void PrintArrayInfo(int Array[], short ArrayLength)
{
    cout << "\nThe Array = [";

    // Loop through and print each element in the array
    for (int i = 0; i < ArrayLength; i++)
    {
        // Print a comma if it's not the first element
        if (i > 0) cout << ", ";
        cout << Array[i];  // Print the current element
    }
    cout << "]\n\n"; // End of array printout
}

int main()
{
    const int MAX_SIZE = 100;
    int Array1[MAX_SIZE];
    short ArrayLength = 0;

    FillArrayWithNumbers(Array1, ArrayLength);  // Fill the array with Numbers from user

    PrintArrayInfo(Array1, ArrayLength);


    return 0;
}
