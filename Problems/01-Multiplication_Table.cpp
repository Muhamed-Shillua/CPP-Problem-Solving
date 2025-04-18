#include <iostream>
using namespace std;

void PrintTableHeader()
{
    cout << "\n\n\t\t\t Multiplication Table From 1 to 10\n\n";
    
    //Print a tab to align the column headers correctly
    cout << "\t";

    // Loop from 1 to 10 to print the column numbers for the header
    for (int i = 1;i <= 10;i++)
    {
        cout << i << "\t";
    }

    cout << "\n___________________________________________________________________________________\n";


}

//Returns a string that acts as a separator between the row number and the multiplication values.
//The spacing is adjusted based on whether the row number is a single-digit (less than 10) or not.
string ColumSperator(int i)
{
    if (i < 10)
        return "   |";
    else
        return "  |";
}

void PrintMultiplicationTable()
{
    PrintTableHeader();

    // Loop through the rows of the multiplication table (from 1 to 10)
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumSperator(i) << "\t";

        // Inner loop to calculate and print the product for each column (from 1 to 10)
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        // After finishing one row, move to the next line
        cout << endl;
    }
}

int main()
{
    PrintMultiplicationTable();
	
	
	return 0;
}