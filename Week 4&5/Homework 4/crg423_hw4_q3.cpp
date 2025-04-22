// Reads from the user a positive integer (decimal)
// Prints its binary representation

#include <iostream>
using namespace std;

int main()
{
    int input; 
    int decimal, two_multiple;

    cout << "Enter decimal number: \n";
    cin >> input;
    decimal = input;
    
    cout << "The binary representation of " << input << " is ";

    for (two_multiple = 64; two_multiple > 0; two_multiple = two_multiple / 2)
    {
        if (decimal >= two_multiple)
        {
            cout << "1";
            decimal = decimal - two_multiple;
        }
        else 
            cout << "0";
    }

    return 0;
}