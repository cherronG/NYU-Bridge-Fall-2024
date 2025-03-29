// Asks for the user to enter an amount of money in the format of dallors and remaining cents
// Calulates and prints the minimum number of coins that are equivalent to the given amount

#include <iostream>
using namespace std;

int main()
{
    int dollars, original_cents, remaining_cents, quarters, total_quarters, dimes, nickels, pennies;

    cout << "Please enter your amount in the format of dollars and cents separated by a space: \n";
    cin >> dollars >> original_cents;

    quarters = dollars * 4;
    total_quarters = quarters + (original_cents / 25);
    remaining_cents = original_cents % 25;
    dimes = remaining_cents / 10;
    remaining_cents = remaining_cents % 10;
    nickels = remaining_cents / 5;
    remaining_cents = remaining_cents % 5;
    pennies = remaining_cents / 1;

    cout << dollars << " dollars and " << original_cents << " cents are: \n";
    cout << total_quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies \n";

    return 0;
}