// Ask user to input 3 real numbers a, b, c
// Displays the solutions when there are 1 or 2 real solutions

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    double num1, num2, real_solution, solution1, solution2;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    if ((a == 0) && (b == 0) && (c == 0))
        cout << "This equation has infinite solutions \n";
    else if (((b * b) - (4 * a * c)) < 0)
        cout << "This equation has no real solutions \n";
    else if (((b * b) - (4 * a * c)) == 0)
    {
        real_solution = (b * -1) / (2 * a);
        cout << "This equation has a single real solution x=" << real_solution << endl;
    }
    else if (((b * b) - (4 * a * c)) > 0)
    {
        num1 = (b * -1) + sqrt(((b * b) - (4 * a * c)));
        solution1 = num1 / (2 * a); 
        num2 = (b * -1) - sqrt(((b * b) - (4 * a * c)));
        solution2 = num2 / (2*a);
        cout << "This equation has two real solutions x=" << solution1 << " and x=" << solution2 << endl;
    }
        
    return 0;
}