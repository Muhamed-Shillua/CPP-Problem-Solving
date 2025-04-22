#include <iostream>
#include <string>
#include <cmath>      // Include cmath for mathematical functions like sqrt and pow.
using namespace std;

/*
    Program Name   : Custom Square Root Function
    Description    : This program reads a number from the user and calculates its square root using the custom function MySqrt.
    Solution       :
        - The program uses the pow function from the cmath library to calculate the square root of the input number.
        - User input is prompted through the ReadNumber function.
        - The result of the square root calculation is displayed to the user.
        - The program ends after displaying the result.
    Input          : A floating-point number entered by the user.
    Output         : The square root of the entered number.
*/

float ReadNumber(string Message)
{
    float Number = 0;

    // Display the message and read the user input
    cout << Message;
    cin >> Number;

    return Number;  // Return the number entered by the user
}

// It uses the pow function to raise the number to the power of 0.5, which is equivalent to sqrt
float MySqrt(float Number)
{
    return pow(Number, 0.5);  // Calculate and return the square root using pow
}

int main()
{
    // Prompt the user to enter a number
    float Number = ReadNumber("Please Enter a Number: ");

    // Output the result of calculating the square root
    cout << "My Sqrt Result = " << MySqrt(Number);

    // End the program
    cout << endl;
    return 0;
}
