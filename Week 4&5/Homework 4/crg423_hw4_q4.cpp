// Reads a sequence of positive integers from the user
// Calculates and prints their geometric mean

#include <iostream> 
#include <cmath>
using namespace std;

int main()
{
    // First read length of sequence
    cout << "Section a" << endl;

    int length;
    int count, input, product = 1;
    double gmean;

    cout << "Please enter the length of the sequence: ";
    cin >> length;
    cout << "Please enter your sequence: \n";

    for (count = 1; count <= length; count ++)
    {
        cin >> input;
        product = product * input;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    gmean = pow((double)product, 1.0/(double)length);
    
    cout << "The geometric mean is: " << gmean << endl;

    // Keep reading the numbers until -1 is entered

    cout << "Please enter a non empty sequenc of positive integers, each one in a separate line. ";
    cout << "End your sequence by typing -1: \n";

    product = 1;
    count = 0;
    while (input >= 0)
    {
        cin >> input;
        if (input == -1)
            break;
        product = product * input;
        count ++;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);
    gmean = pow((double)product, 1.0/(double)count);
    
    cout << "The geometric mean is: " << gmean << endl;
    return 0;
}