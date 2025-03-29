// Asks the user to input a positive integer n
// Prints all numbers from 1 to n that have more even digits than odd digits

#include <iostream>
using namespace std;

int main()
{
    int n;
    int input, number; 
    int currentDigit, remainder, evenDigits = 0, oddDigits = 0;
    
    cout << "Please enter a positive integer: ";
    cin >> n;

    input = 1; 
    while (input <= n)
    {
        evenDigits = 0;
        oddDigits = 0;
        for (number = input; number > 0; number = number / 10)
        {
            currentDigit = number % 10;
            remainder = currentDigit % 2;

            if (remainder == 0)
                evenDigits++;
            else if (remainder != 0)
                oddDigits++;
        }   
        if (evenDigits > oddDigits)
            cout << input << endl;
            
        input++;     
    }

    return 0;
}