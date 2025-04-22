// Asks the user to input a positive integer >= 2
// Prints all of the integer's divisors

#include <iostream>
#include <cmath>
using namespace std;

void printDivisors (int num);
// Takes a positive integer num
// Prints all of num's divisors in an ascending order, separated by a space

int main()
{
    int num;

    cout << "Please enter a a positive integer >= 2: ";
    cin >> num;

    printDivisors(num);

    return 0;
}

void printDivisors (int num)
{
    double square_num = sqrt(num);
    int divisor;

    for (int i = 1; i < square_num; i++)
    {
        if (num % i == 0)
            cout << i << " ";
    }
    for (int i = square_num; i > 1; i--)
    {
        if (num % i == 0)
        {
            divisor = num / i;
            cout << divisor << " ";
        }
    }
    cout << num << endl;
}