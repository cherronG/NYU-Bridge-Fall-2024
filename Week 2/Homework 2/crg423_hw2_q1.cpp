// Asks the user to enter a number of quaters, dimes, nickels, and pennies
// Outputs the monetary value of the coins in the format of dollars and remaining cents

#include <iostream>
using namespace std;

int main()
{
    int quaters, dimes, nickels, pennies, dollars, cents;

    cout << "Please enter number of coins: \n" << "# of quaters: ";
    cin >> quaters;

    cout << "# of dimes: ";
    cin >> dimes;

    cout << "# of nickels: ";
    cin >> nickels;

    cout << "# of pennies: ";
    cin >> pennies;

    dollars = ((quaters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)) / 100;
    cents = (int)((quaters * 25) + (dimes * 10) + (nickels * 5) + (pennies * 1)) % (int) 100;
    
    cout << "The total is " << dollars << " dollars and " << cents << " cents. \n";

    return 0;
}