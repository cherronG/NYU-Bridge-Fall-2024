// Computes the cost of a long-distance call
// User inputs day of the week, time call started, and length of call in minutes
// Outputs cost of the call

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int minutes;
    double hour24, minutes24;
    char colon;
    string day;
    double cost;

    cout << "Please enter the day of the week (Mo, Tu, We, Th, Fr, Sa, or Su): ";
    cin >> day;
    cout << "Please enter the time the call started in 24-hour format: ";
    cin >> hour24 >> colon >> minutes24;
    cout << "Please enter the length of the call in minutes: ";
    cin >> minutes;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if ((day == "Sa") || (day == "Su"))
    {
        cost = (double)minutes * 0.15;
        cout << "Your call costs $" << cost << endl;
    }
    else
{
    if ((hour24 < 8) || (hour24 > 18))
        {
            cost = (double)minutes * 0.25;
            cout << "Your call costs $" << cost << endl;
        }
    else if ((hour24 >= 8) || (hour24 <= 18))
        {
            cost = (double)minutes * 0.40;
            cout << "Your call costs $" << cost << endl;
        }
}
    return 0;
}