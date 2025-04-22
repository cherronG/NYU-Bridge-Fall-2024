#include <iostream>
using namespace std;

double eApprox (int n);
// Takes a positive integer n
// Returns an approximation of e calculated by the sum of the first (n+1) addends  of the infinit sum

int main()
{
    cout.precision(30);

    for (int n = 1; n <= 15; n++)
    {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }

    return 0;
}

double eApprox (int n)
{
    double e = 1.0, factorial = 1.0;
    for (double i = 1; i <= n; i++)
    {
        factorial = factorial * i;
        e = e + (1.0 / factorial);
    }
    return (e);

}