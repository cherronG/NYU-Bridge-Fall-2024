// Asks the user to input their name, graduation year, and current year
// Assume 4-year undergraduate program
// Display current status the student is in

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int g_year, c_year;
    string name;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> g_year;
    cout << "Please enter current year: ";
    cin >> c_year;

    if ((g_year - c_year) > 4)
        cout << name << ", you are not in college yet \n";
    else if ((g_year - c_year) == 4)
        cout << name << ", you are a Freshman \n";
    else if ((g_year - c_year) == 3)
        cout << name << ", you are a Sophmore \n";
    else if ((g_year - c_year) == 2)
        cout << name << ", you are a Junior \n";
    else if ((g_year - c_year) == 1)
        cout << name << ", you are a Senior \n";
    else if ((g_year - c_year) <=0)
        cout << name << ", you graduated \n";

    return 0;
}