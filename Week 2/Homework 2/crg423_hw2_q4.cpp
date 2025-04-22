// Reads from the user two positive integers
//Prints the result of when we add, subtract, multiply, divide, div and mod them

#include <iostream>
using namespace std;

int main ()
{
    int pos_int1, pos_int2;
    double pos_double1, pos_double2;

    cout << "Please enter two positive integers, separated by a space: \n";
    cin >> pos_int1 >> pos_int2;

    cout << pos_int1 << " + " << pos_int2 << " = " << (pos_int1 + pos_int2) << endl;
    cout << pos_int1 << " - " << pos_int2 << " = " << (pos_int1 - pos_int2) << endl;
    cout << pos_int1 << " * " << pos_int2 << " = " << (pos_int1 * pos_int2) << endl;

    pos_double1 = (double)pos_int1;
    pos_double2 = (double)pos_int2;
    cout << pos_int1 << " / " << pos_int2 << " = " << ( pos_double1 / pos_double2) << endl;

    cout << pos_int1 << " div " << pos_int2 << " = " << (pos_int1 / pos_int2) << endl;
    cout << pos_int1 << " mod " << pos_int2 << " = " << (pos_int1 % pos_int2) << endl;

    return 0;
}