// Asks the user to input the number of triangles in the tree and the character filling the tree
// Prints a pine tree consisting of triangles of increasing sizes, filled with a character

#include <iostream>
using namespace std;

void printShiftedTriangle (int n, int m, char symbol);
// Prints an n-line triangle, filled with symbol characters, shifted m spaces from the left margin
void printPineTree (int n, char symbol);
// Prints a sequence of n triangles of increasing sizes, which form the shape of a pine tree
// the smallest triangle is a 2-line triangle
// triangles are filled with the symbol character

int main()
{
    int triangles;
    char character;

    cout << "How many triangles?: ";
    cin >> triangles;
    cout << "What character to fill the triangles?: ";
    cin >> character;

    printPineTree (triangles, character);

    return 0;
}

void printShiftedTriangle (int n, int m, char symbol)
{
    int total_lines = n + 1;
    int total_spaces = n;
    int total_fill = 1;

    for (int line = 1; line <= total_lines; line++)
    {
        for (int margin = 1; margin <= m; margin++)
            cout << " ";
        for (int spaces = 1; spaces <= total_spaces; spaces++)
            cout << " ";
        for (int fill = 1; fill <= total_fill; fill++)
            cout << symbol;
        
        cout << endl;
        total_spaces--;
        total_fill = total_fill + 2;
    }
}

void printPineTree (int n, char symbol)
{
    int m = n - 1;
    for (int t = 1; t <= n; t++)
    {
        printShiftedTriangle (t, m, symbol);
        m--;
    }
}