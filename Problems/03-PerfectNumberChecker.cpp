#include <iostream>
#include <string>
using namespace std;

// Enum to represent the status of a perfect number
enum enPerfectStatus
{
    Perfect = 1,   
    NotPerfect = 2 
};

// Function to check if the number is perfect by calculating the sum of its divisors
enPerfectStatus CheckNumberStatus(int Number)
{
    int Sum = 0;

    // Loop through all possible divisors up to half of the number
    for (int counter = 1; counter <= Number / 2; ++counter)
    {
        // If the counter divides the number with no remainder, it's a divisor
        if (Number % counter == 0)
        {
            Sum += counter; 
        }
    }

    // Check if the sum of divisors equals the number itself
    return (Number == Sum) ? enPerfectStatus::Perfect : enPerfectStatus::NotPerfect;
}

// Function to display the status of the number (Perfect or Not Perfect)
void PrintNumberStatus(enPerfectStatus status)
{
    cout << "\n====================================\n";

    // Display the appropriate message based on the number's status
    cout << (status == enPerfectStatus::Perfect ? "The Number Is Perfect." : "The Number Is Not Perfect.");

    cout << "\n====================================\n";
}

// Function to read a positive number from the user, ensuring it's greater than 0
int ReadPositiveNumber(const string& Message)
{
    int Number;

    // Keep asking the user until a valid positive number is entered
    do
    {
        cout << Message;
        cin >> Number;
        if (Number <= 0)
            cout << "PlZ Enter a Positive Number Greater than zero.\n";
    } while (Number <= 0);

    return Number;
}

int main()
{
    // Using 'auto' to let the compiler infer the type of 'number'
    // The type is automatically deduced based on the function's return type (which is 'int')
    const auto Number = ReadPositiveNumber("Plz Enter a Number: ");

    // Check if the number is perfect and print the result
    PrintNumberStatus(CheckNumberStatus(Number));
	
	
	

    return 0;
}
