// Reads a positive integer n from the user 
// Prints out a nxn multiplication table with columns spaced by a tab

#include <iostream>
using namespace std;

int main()
{
    int n;
    int number; 

    cout << "Please enter a positive integer:\n";
    cin >> n;

    for (int lines = 1; lines <= n; lines++)
    {
        for (int columns = 1; columns <= n; columns++)
        {
            number = columns *  lines;
            cout << number << "\t";
        }
        cout << endl;
    }

    return 0;
}