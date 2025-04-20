#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    Program Name   : Generate License-Style Keys
    Description    : Generates a number of random keys with specified format (slots of characters separated by '-').
    Solution       :
        - Built on Problem #19 which introduced generating random characters of specific types.
        - Prompts the user to enter:
            * Number of keys to generate
            * Number of slots per key
            * Number of characters per slot
        - Uses helper functions to:
            * Read input
            * Generate random characters (only capital letters used here)
            * Build each slot and assemble the full key
        - Keys follow a format like: ABCD-EFGH-IJKL
*/

// Enumeration for different character types
enum enCharType
{
    Capital = 1,
    Small = 2,
    Special = 3,
    Digit = 4
};

// Reads a positive integer with validation
int ReadNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message; cin >> Number;
    } while (Number <= 0); // Ensure number is positive

    return Number;
}

// Returns a random integer between From and To (inclusive)
int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
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
    case Capital:  return char(RandomNumber(65, 90));    // A-Z
    case Small:    return char(RandomNumber(97, 122));   // a-z
    case Special:  return char(RandomNumber(33, 47));    // Special characters
    case Digit:    return char(RandomNumber(48, 57));    // 0-9
    default:       return char(RandomNumber(65, 90));    // Default to Capital
    }
}

// Builds a single slot of a key (e.g., "ABCD")
string GenerateKeySlot(enCharType CharType, short SlotLength)
{
    string KeySlot = "";

    for (int i = 0; i < SlotLength; i++)
    {
        KeySlot += GetRandomCharacter(CharType);
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
        FullKey += GenerateKeySlot(Capital, SlotLength);
    }

    return FullKey;
}

void PrintKeys(short NumberOfKeys, short SlotsNumber, short SlotLength)
{
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        cout << "Key [" << i << "]: " << GenerateKey(SlotsNumber, SlotLength) << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL)); // Initialize random seed

    short NumberOfKeys = ReadNumber("Please enter number of keys: ");
    short SlotsNumber  = ReadNumber("Please enter number of slots per key: ");
    short SlotLength   = ReadNumber("Please enter number of characters per slot: ");

    PrintKeys(NumberOfKeys, SlotsNumber, SlotLength);

    return 0;
}
