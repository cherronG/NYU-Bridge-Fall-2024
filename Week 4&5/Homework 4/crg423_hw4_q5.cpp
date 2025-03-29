// Asks the reader to input a positive integer
// Prints a textual image of an hourglass made of 2n lines with asterisks

#include <iostream>
using namespace std;

int main()
{
    int n;
    int lines, totalDots, dots, frontSpaces, backSpaces, totalFrontSpaces, totalBackSpaces;

    cout << "Please enter a positive integer: ";
    cin >> n;

    totalDots = (2 * n) - 1;
    totalFrontSpaces = 0;
    totalBackSpaces = 0;
    for (lines = 1; lines <= n; lines++)
    {
        for (frontSpaces = 0; frontSpaces < totalFrontSpaces; frontSpaces++)
            cout << " ";
        for (dots = 0; dots < totalDots; dots++)
            cout << "*";
        for (backSpaces = 0; backSpaces < totalBackSpaces; backSpaces++)
            cout << " ";
        
        totalDots = totalDots - 2;
        totalFrontSpaces = totalFrontSpaces + 1;
        totalBackSpaces = totalBackSpaces + 1;

        cout << endl;
    }

    totalDots = 1;
    totalFrontSpaces = n - 1;
    totalBackSpaces = n -1;
    for (lines = n + 1; lines <= (2 * n); lines++)
    {
        for (frontSpaces = 0; frontSpaces < totalFrontSpaces; frontSpaces++)
            cout << " ";
        for (dots = 0; dots < totalDots; dots++)
            cout << "*";
        for (backSpaces = 0; backSpaces < totalBackSpaces; backSpaces++)
            cout << " ";
        
        totalDots = totalDots + 2;
        totalFrontSpaces = totalFrontSpaces - 1;
        totalBackSpaces = totalBackSpaces - 1;

        cout << endl;
    }
    return 0;
}