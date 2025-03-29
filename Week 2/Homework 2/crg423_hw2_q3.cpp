// Suppose John and Bill worked for some time.
// Calculates the total time both of them worked
// Reads number of days, hours, minutes each of them worked
// Pprints the total time both of them worked together as days, hours, minutes

#include <iostream>
using namespace std;

int main()
{
    int Jdays, Jhours, Jminutes, Bdays, Bhours, Bminutes, tdays, thours, tminutes;

    cout << "Please enter the numeber of days John has worked: ";
    cin >> Jdays;
    cout << "Please enter the number of hours John has worked: ";
    cin >> Jhours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> Jminutes;

    cout << endl;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> Bdays;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> Bhours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> Bminutes;

    tminutes = Jminutes + Bminutes;
    thours = (Jhours + Bhours) + (tminutes / 60);
    tminutes = tminutes % 60;
    tdays = (Jdays + Bdays) + (thours / 24);
    thours = thours % 24;    
    
    cout << endl;

    cout << "The total time both of them worked together is: " << tdays << " days, " << thours << " hours, " << tminutes << " minutes. \n";

    return 0;
}