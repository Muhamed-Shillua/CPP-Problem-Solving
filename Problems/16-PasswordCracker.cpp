#include <iostream>   
#include <string>     
#include <cctype>  // For checking if a character is a letter
using namespace std;

/*
    Program Name   : Password Cracker
    Description    : This program attempts to find the correct password by generating all combinations of three uppercase English letters from AAA to ZZZ.
    Solution       :
        Based On: Problem 15 - Brute Force Password Cracking (Finding a 3-letter password)
         The program uses three nested loops to generate and test all combinations of three uppercase letters.
         For each combination, the program prints the trial and checks if it matches the input password.
         Once the correct password is found, it reports the number of trials taken to find it.
*/

string ReadPassword(string PromptMessage)
{
    string InputPassword = "";

    // Display message to ask for the password
    cout << PromptMessage;

    while (true)
    {
        cin >> InputPassword;

        // Validate that the input is a valid password consisting only of letters
        bool IsValid = true;
        for (char Character : InputPassword)
        {
            if (!isalpha(Character))  // Check if all characters are letters
            {
                IsValid = false;
                break;
            }
        }

        // If the input is valid, break out of the loop, otherwise prompt again
        if (IsValid)
            break;
        else
            cout << "Invalid input! Please enter a valid password consisting of letters: ";
    }

    return InputPassword;
}

bool CheckPassword(string TargetPassword)
{
    string CurrentPassword = "";
    short TrialCount = 0;

    // Loop through the first letter (A-Z)
    for (int FirstLetter = 65; FirstLetter <= 90; FirstLetter++)
    {
        // Loop through the second letter (A-Z)
        for (int SecondLetter = 65; SecondLetter <= 90; SecondLetter++)
        {
            // Loop through the third letter (A-Z)
            for (int ThirdLetter = 65; ThirdLetter <= 90; ThirdLetter++)
            {
                // Create the password by concatenating the three letters
                CurrentPassword = char(FirstLetter) + char(SecondLetter) + char(ThirdLetter);
                TrialCount++;

                // Display the current trial
                cout << "Trial [" << TrialCount << "] : " << CurrentPassword << endl;

                // Check if the generated password matches the input password
                if (CurrentPassword == TargetPassword)
                {
                    cout << "\nPassword is " << CurrentPassword << "\n";
                    cout << "Found after " << TrialCount << " Trial(s)\n";
                    return true;  // Return true indicating the password was found.
                }
            }
        }
    }

    // Return false if the password is not found (though it should always be found in this case)
    return false;
}

int main()
{
    string UserPassword = ReadPositivePassword("Enter the password to be cracked: ");

    // Attempt to check the password using the brute-force method
    bool Result = CheckPassword(UserPassword);

    // If the password is found, it will print the trial count and password, otherwise, return false.
    if (!Result)
    {
        cout << "Password not found.\n";
    }

    return 0;
}
