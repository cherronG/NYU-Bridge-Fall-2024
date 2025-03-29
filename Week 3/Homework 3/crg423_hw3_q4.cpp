// Asks the user to enter a real number, method to round the number (floor, ceiling, or nearest integer)
// Prints the rounded result

#include <iostream>
using namespace std;

int main()
{
    const int FLOOR_ROUND  = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    int round_method;
    int real, decimal;
    char decimal_point;

    cout << "Please enter a Real number:\n";
    cin >> real >> decimal_point >> decimal;
    cout << "Choose your rounding method:\n" << "1. Floor round\n" << "2. Ceiling round\n";
    cout << "3. Round to the nearest whole number \n";
    cin >> round_method;

    switch (round_method)
    {
        case FLOOR_ROUND:
            cout << real << endl;
            break;
        case CEILING_ROUND:
            cout << real + 1 << endl;
            break;
        case ROUND:
            if (decimal < 50)
                cout << real << endl;
            else if (decimal >= 50)
                cout << real + 1 << endl;
            break;
        default:
            cout << "Not a valid rounding method" << endl;
    }

    return 0;
}