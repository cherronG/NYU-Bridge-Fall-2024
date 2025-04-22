// Reads a positive integer n, and prints the first n even numbers

#include <iostream>
using namespace std;

int main()
{
    int input; 
    int n, count = 0;

    cout << "Please enter a positive integer: ";
    cin >> input;  
    n = input; 
    
    // while loop version
    cout << "Section a" << endl;

    while (n > 0)
    {
        count++;
        if (count % 2 == 0)
            {
                cout << count << endl;
                n--;
            }
        else if (count % 2 != 0)
            continue;
    }

    //for loop version
    cout << "Section b" << endl;
    n = input;

    for (count = 1; n > 0; count++)
        if (count % 2 == 0)
        {
            cout << count << endl;
            n--;
        }
        else if (count % 2 != 0)
            continue;
    
    return 0;
}