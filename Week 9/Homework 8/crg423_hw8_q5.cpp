// Reads a person's name in format: first name, then middle name or initial, and then last name
// Outputs the name in the format: Last_Name, First_Name, Middle_Initial

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string first, middle, last;

    cout << "Please enter your name (first middle last): " << endl;
    cin >> first >> middle >> last;

    if (middle.length() > 1)
        middle = middle[0];

    cout << last << ", " << first << " " << middle << "." << endl;
    
    return 0;
}