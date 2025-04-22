// Asks the user to input a positive integer M >= 2
// Prints all perfect numbers between 2 and M
// Prints all pairs of amicable numbers that are between 2 and M

#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
// Takes a postive integer num >= 2 
// Updates two output parameters with the number of num's proper divisors and their sum
bool isPerfect(int num);
// Takes a postive integer num >= 2
// Determines if it is a perfect number or not
void isAmicable(int x, int num);
// Takes a positive integer num >= 2
// Prints the amicable number pairs between 2 and num

int main()
{
    int M;
    bool perfect;
    
    // reads positive integer from user
    cout << "Please enter positive integer that is greater than or equal to 2: ";
    cin >> M;

    cout << "All perfect numbers between 2 and " << M << ": ";

    // prints all perfect numbers between 2 and M
    for (int i = 2; i <= M; i++)
    {
        perfect = isPerfect(i);
        if (perfect)
            cout << i << " ";
    }
    cout << endl;

    // prints amicable pairs between 2 and M
    cout << "All pairs of amicable numbers between 2 and " << M << ":" << endl;
    for (int i = 2; i <= M; i++)
    {
        isAmicable(i, M);
    }
    
    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    double square_num = sqrt(num);
    int divisor;

    //resets the initialization of outCountDivs and outSumDivs for every use of the function
    outCountDivs = 0;
    outSumDivs = 0;

    for (int i = 1; i < square_num; i++)
    {
        if (num % i == 0)
        {
            outSumDivs += i;
            outCountDivs++;
            divisor = num / i;

            if ((divisor != i) && (divisor != num))
            {
                outSumDivs += divisor;
                outCountDivs++;
            }
        }
    }
}

bool isPerfect(int num)
{
    int countDivs = 0, sumDivs = 0;

    analyzeDividors (num, countDivs, sumDivs);
    
    return num == sumDivs;
}

void isAmicable(int x, int num)
{
    int xCount = 0, xSum = 0, yCount = 0, ySum = 0;

    analyzeDividors(x, xCount, xSum);
    analyzeDividors(xSum, yCount, ySum);

    if ((x == ySum) && (x < xSum) && xSum <= num)
        cout << "(" << x << ", " << xSum << ") ";
}