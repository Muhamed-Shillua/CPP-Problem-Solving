#include <iostream>
#include <string>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

/*
    Program Name   : RandomCharacterByType
    Description    : This program generates random characters of different types (Capital, Small, Digit, Special).
    Based On       : Problem #18 Random Number Generator
    Solution	   :
         - The program defines an enum to represent character types.
         - The function RandomNumber generates a number between two bounds.
         - The function GetRandomCharacter receives a character type and returns a random character based on it.
         - The program uses ASCII ranges to determine which character to return.
*/

enum enCharType
{
    Capital = 1,
    Small   = 2,
    Special = 3,
    Digit   = 4
};

int RandomNumber(int From, int To)
{
    return (rand() % (To - From + 1)) + From;
}

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
		// Note: We use "Capital" instead of "enCharType::Capital" because the enum is declared globally,
			// so its values are accessible directly in this scope.
        case Capital:
            return char(RandomNumber(65, 90));   // A-Z
        case Small:
            return char(RandomNumber(97, 122));  // a-z
        case Special:
            return char(RandomNumber(33, 47));   // Special characters like ! " # $
        case Digit:
            return char(RandomNumber(48, 57));   // 0-9
        default:
            return char(RandomNumber(65, 90));   // Default to capital
    }
}

int main()
{
    srand((unsigned)time(NULL));  // Seed random once

    cout << GetRandomCharacter(Capital) << endl;
    cout << GetRandomCharacter(Small) << endl;
    cout << GetRandomCharacter(Special) << endl;
    cout << GetRandomCharacter(Digit) << endl;

    return 0;
}
