// Asks the user to input a positive integer num
// Prints the num's elements in the Fibonacci sequence

#include <iostream>
using namespace std;

int fib(int n);
// Returns the nth element of the Fibonacci sequence

int main() 
{
    int num;

    cout << "Please enter a positive integer: ";
    cin >> num ;

    int element = fib(num);

    cout << element;

    return 0;
}

int fib(int n)
{
    int fn, fn1 = 1, fn2 = 1;
    
    for (int i = 1; i <= n; i++)
    {
        if ((i == 1) || (i == 2))
            fn = 1;
        else 
        {
            fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
        }
    }

    return (fn);
}