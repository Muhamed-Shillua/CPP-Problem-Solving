#include <iostream>   
#include <string>     
#include <cctype>  // For checking if a character is a letter
using namespace std;

/*
    Program Name   : TextEncryptDecrypt
    Description    : This program encrypts and decrypts a given text using a simple Caesar cipher.
    Solution       :
         The program first asks the user to enter a string of letters only. Then it encrypts the text by shifting
         each character's ASCII value by a fixed encryption key, and later decrypts it back using the same key.
         The result is shown for both encrypted and decrypted texts.
*/

string ReadText(string PromptMessage)
{
    string InputText = "";

    cout << PromptMessage;

    while (true)
    {
        cin >> InputText;

        bool IsValid = true;
        for (char Character : InputText)
        {
            if (!isalpha(Character))  // Ensure the input consists only of letters
            {
                IsValid = false;
                break;
            }
        }

        // If the input is valid (letters only), break out of the loop
        if (IsValid)
            break;
        else
            cout << "Invalid input! Please enter a valid text consisting of letters only: ";
    }

    return InputText;
}

string EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] + EncryptionKey);  // Shift the character by EncryptionKey positions
    }

    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < Text.length(); i++)
    {
        Text[i] = char((int)Text[i] - EncryptionKey);  // Reverse the shift by EncryptionKey positions
    }

    return Text;
}

int main()
{
    const short EncryptionKey = 2;  // Fixed encryption key (Caesar cipher shift value)

    // Encrypt the input text
    string EncryptedText = EncryptText(ReadText("Please enter a text to encrypt: "), EncryptionKey);

    // Decrypt the text
    string DecryptedText = DecryptText(EncryptedText, EncryptionKey);

    // Output the results
    cout << "\n==============================\n";
    cout << "Encrypted Text: " << EncryptedText << endl;
    cout << "Decrypted Text: " << DecryptedText << endl;

    return 0;
}
