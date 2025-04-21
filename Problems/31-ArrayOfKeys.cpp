#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : Array Of Keys
    Description    : Generates a set of random keys consisting of uppercase letters, and assembles them into formatted keys.
    Solution       :
        - Based on problem number #20 which deals with generating random keys.
        - User Input: Number of keys to generate.
        - Each key consists of 4 slots, with each slot containing 4 random uppercase letters.
        - The keys are printed in a readable format (Key 1: XXXX-XXXX-XXXX-XXXX).
*/


// Enumeration for different character types
enum enCharType
{
    Capital = 1,     // Represents uppercase letters (A-Z)
    Small   = 2,     // Represents lowercase letters (a-z)
    Special = 3,     // Represents special characters (e.g., !, @, #)
    Digit   = 4      // Represents digits (0-9)
};

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

// Returns a random character depending on the CharType specified
char GetRandomCharacter(enCharType CharType)
{
    /*
        Note: We’re using enum values directly (e.g., Capital) because
        they're accessible globally after defining the enum.
        - This modular structure allows easy extension in the future (e.g., allow Small, Digit, etc.).
    */
    switch (CharType)
    {
    case Capital:  return char(GenerateRandomNumber(65, 90));    // A-Z
    case Small:    return char(GenerateRandomNumber(97, 122));   // a-z
    case Special:  return char(GenerateRandomNumber(33, 47));    // Special characters
    case Digit:    return char(GenerateRandomNumber(48, 57));    // 0-9
    default:       return char(GenerateRandomNumber(65, 90));    // Default to Capital
    }
}

// Builds a single slot of a key (e.g., "ABCD")
string GenerateKeySlot(enCharType CharType, short SlotLength)
{
    string KeySlot = "";

    for (int i = 0; i < SlotLength; i++)
    {
        KeySlot += GetRandomCharacter(CharType);     // Add random character to the slot
    }

    return KeySlot;
}

// Assembles the full key by joining multiple slots with '-'
string GenerateKey(short SlotsNumber, short SlotLength)
{
    string FullKey = "";

    for (int i = 0; i < SlotsNumber; i++)
    {
        if (i > 0) FullKey += "-"; // Add dash between slots
        FullKey += GenerateKeySlot(Capital, SlotLength); // Generate key slot and append
    }

    return FullKey;
}

void FillArrayWithKeys(string Array[], short ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        Array[i] = GenerateKey(4, 4);  // Generate a key with 4 slots, each containing 4 characters
    }
}

void PrintArray(string Array[], short ArrayLength)
{
    for (int i = 0; i < ArrayLength; i++)
    {
        cout << "\tKey [" << i + 1 << "]: " << Array[i] << endl;// Print each key in the array         // Print each Key of the array
    }
}

int main()
{
    srand((unsigned)time(NULL));  // Seed the random number generator

    const int MAX_SIZE = 100;
    string Array[MAX_SIZE];
    short ArrayLength = ReadNumber("Enter Number Of Keys: ");

    FillArrayWithKeys(Array, ArrayLength);// Fill the array with generated keys

    cout << "\nkeys : \n";
    PrintArray(Array, ArrayLength);// Print all generated keys


    return 0;
}
