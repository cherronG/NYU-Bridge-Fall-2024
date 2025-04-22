// Recursively implements the functions printTriangle, printOppositeTriangles, and printRuler 
#include <iostream>
using namespace std;

// Function Declarations
void printTriangle(int n);
// Takes a positive integer, n
// Prints a textual image of a right triangle (aligned to the left) made of n lines with "*"

void printOppositeTriangles(int n);
// Takes a positive integer, n
// Prints a textual image of two opposite right triangles (aligned to the left) each containing n lines with "*"

void printRuler(int n);
// Takes a positive integer, n
// Prints a vertical ruler of 2^n-1 lines, each containing "-" marks according to a set of rules


int main()
{
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;

    cout << "Single Triangle" << endl;
    printTriangle(n);
    cout << endl;

    cout << "Opposite Triangles" << endl;
    printOppositeTriangles(n);
    cout << endl;

    cout << "Ruler" << endl;
    printRuler(n);
    cout << endl;

    return 0;
}

void printTriangle(int n)
{
    // n == number of lines in triangle

    if (n == 1)     // Base Case: n == 1
        cout << "*" << endl;
    else            // Recursive Case: n > 1
    {
        // call the function again to start from line 1
        printTriangle(n - 1);

        // print the amount of "*" corresponding to the line number 
        for (int i = 0; i < n; i++)
            cout << "*";
        // end line before going to the next line
        cout << endl;
    }
}

void printOppositeTriangles(int n)
{
    // n == number of lines in each triangle
    if (n == 1)     // Base Case: n == 1
    {
        cout << "*" << endl;
        cout << "*" << endl;
    }
    else            // Recursive Case: n > 1
    {
        // print the amount of "*" corresponding to the line number for the top triangle
        for(int i = 0; i < n; i++)
            cout << "*";
        
        // end line before going to the next line
        cout << endl;

        // call to the function again on the smaller instance 
        printOppositeTriangles(n-1);

        // print the amount of "*" correspinding to the line number for the bottom triangle
        for (int i = 0; i < n; i++)
            cout << "*";
        
        // end the line before going to the next line
        cout << endl;
    }
}

void printRuler(int n)
{
    // n == number of "-" in the middle line
    if (n == 1)         // Base Case: n == 1
        cout << "- " << endl;
    else                // Recursive Case: n > 1
    {
        // call to the function again on the smaller instance
        printRuler(n - 1);

        // print the amount of "-" corresponding to the value of n
        for (int i = 0; i < n; i++)
            cout << "- ";
        
        // end the line before going to the next line
        cout << endl;

        // call to the function again on the smaller instance
        printRuler(n - 1);
    }
}