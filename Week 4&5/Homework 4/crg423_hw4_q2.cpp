//  Reads a decimal number inputted by the user
// Prints the number's representation as a simplified Roman numeral

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int input, decimal;
    string symbol;
    string Roman;
    
    cout << "Enter decimal number: \n";
    cin >> input;
    decimal = input;

    while (decimal >= 1000)
    {
        decimal = decimal - 1000;
        symbol = "M";
        Roman = Roman + symbol;
    }

    while (decimal >= 500)
    {
        decimal = decimal - 500;
        symbol = "D";
        Roman = Roman + symbol;
    }

    while (decimal >= 100)
    {
        decimal = decimal - 100;
        symbol = "C";
        Roman = Roman + symbol;
    }

    while (decimal >= 50)
    {
        decimal = decimal - 50;
        symbol = "L";
        Roman = Roman + symbol;
    }

    while (decimal >= 10)
    {
        decimal = decimal - 10;
        symbol = "X";
        Roman = Roman + symbol;
    }

    while (decimal >= 5)
    {
        decimal = decimal - 5;
        symbol = "V";
        Roman = Roman + symbol;
    }

    while (decimal >= 1)
    {
        decimal = decimal - 1;
        symbol = "I";
        Roman = Roman + symbol;
    }

    cout << input << " is " << Roman << endl;

    return 0;
}