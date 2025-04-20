#include <iostream>
#include <string>
using namespace std;

/*
    Program Name   : Number Frequency in Array
    Description    : This program focuses on array manipulation and counting specific elements.
    Solution       :
        - The program calculates and prints the frequency of the specified number in the array.
        - Uses helper functions to:
            * Read the array length and elements.
            * Count occurrences of a number in the array.
        - The result is printed as: "The Number [number] appeared [count] time(s)."
*/

int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message;
        cin >> Number;
    } while (Number <= 0); // Ensure the number is positive (greater than zero)

    return Number;
}

void ReadArrayElements(int Array[], short& ArrayLength)
{
    ArrayLength = ReadNumber("Enter Number Of Array Elements: ");

    cout << "\nEnter Array Elements:\n";

    // Loop to read each element of the array from the user
    for (int i = 0; i < ArrayLength; i++)
    {
        // Prompt user for each element
        cout << "Element [" << i + 1 << "]: ";
        cin >> Array[i];
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
        cout << Array[i];
    }
    cout << " ]\n"; // End of array printout
}

short CountNumberFrequency(int Array[], short ArrayLength, short& NumberToCheck)
{
    cout << "\n=======================\n";

    NumberToCheck = ReadNumber("Enter Number to Check: ");

    short Counter = 0; 

    // Loop through the array and count the occurrences of the number
    for (int i = 0; i < ArrayLength; i++)
    {
        if (Array[i] == NumberToCheck)
            Counter++; 
    }

    return Counter; 
}

int main()
{
    int Array[100];
    short ArrayLength, NumberToCheck;

    ReadArrayElements(Array, ArrayLength);

    PrintArrayElements(Array, ArrayLength);

    // Call the function to count how many times the user-specified number appears in the array
    short Frequency = CountNumberFrequency(Array, ArrayLength, NumberToCheck);

    // Print the frequency of the specified number
    cout << "\nThe Number " << NumberToCheck << " appeared "
        << Frequency << " time(s).\n";



    return 0; 
}
