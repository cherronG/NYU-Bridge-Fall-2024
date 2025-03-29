// Computes how much a customer has to pay after purchasing two items

#include <iostream>
using namespace std;

int main()
{
    double price1, price2, tax;
    double base, discount, half_total, total;
    char clubcard;

    cout << "Enter price of first item: ";
    cin >> price1;
    cout << "Enter price of second item: ";
    cin >> price2;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubcard;
    cout << "Enter tax rate, e.g. 5.5, for 5.5% tax: ";
    cin >> tax;

    base = price1 + price2;

    if ((price1 < price2) && ((clubcard == 'y') || (clubcard == 'Y')))
    {
        price1 = price1 - (price1 * 0.50); // lowest item half price
        half_total = price1 + price2; // new total amount with half price discount
        discount = half_total - (half_total * 0.10); // total amount with club discount and half price
        total = discount + (discount * (tax / 100)); // total amount with discounts and tax
    }
    else if ((price1 < price2) && ((clubcard == 'n') || (clubcard == 'N')))
    {
        price1 = price1 -(price1 * 0.50);
        half_total = price1 + price2;
        discount = half_total;
        total = discount + (discount * (tax / 100));
    }
    else if ((price1 > price2) && ((clubcard == 'y') || (clubcard == 'Y')))
    {
        price2 = price2 - (price2 * 0.50);
        half_total = price1 + price2;
        discount = half_total - (half_total * 0.10);
        total = discount + (discount * (tax / 100));
    }
    else if ((price1 > price2) && ((clubcard == 'n') || (clubcard == 'N')))
    {
        price2 = price2 - (price2 * 0.50);
        half_total = price1 + price2;
        discount = half_total;
        total = discount + (discount * (tax / 100));
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << "Base price: " << base << endl;
    cout << "Price after discounts: " << discount << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    cout << "Total Price: " << total << endl;

    return 0;
}