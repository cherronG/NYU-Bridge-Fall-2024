// Asks the user to input the year and starting day (1-7) of the week of 1/1 in that year
// Prints a formatted calender of that year 

#include <iostream>
#include <string>
using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
// takes the number of days in the month and the number (1-7) that represents the starting day in the week of the first day of the month
// prints a formatted monthly calendar of that month and returns the number of the day in the week of the last day of the month
bool leapYear(int year);
// takes the year as input
// returns true if the year is a leap year and false if otherwise
void printYearCalender(int year, int startingDay);
// takes the year and the number (1-7) that represents the starting day in the week of 1/1 in that year
// uses functions printMonthCalender() and leapyear() to print a formatted year calendar of that year

int main()
{
    int year, yearStartingDay;

    cout << "Please enter the year: ";
    cin >> year;
    cout << "Please enter the day in the week of 1/1 in that year (1-7): ";
    cin >> yearStartingDay;

    printYearCalender (year, yearStartingDay);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay)
{
    int totalSpaces = startingDay - 1;
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

    for (int space = 1; space <= totalSpaces; space++)
        cout << " \t";

    for (int number = 1; number <= numOfDays; number++)
    {
        if (((number + startingDay - 1) % 7 == 0) || (number == numOfDays))
            cout << number << endl;
        else 
            cout << number << "\t";
    }

    if (((numOfDays + startingDay) % 7) == 0)
        return 7;
    else
        return ((numOfDays + startingDay) % 7);
}

bool leapYear(int year)
{
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    else if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
        return true;
    else 
        return false;
}

void printYearCalender(int year, int startingDay)
{
    int lastDayInMonth = startingDay;
    bool leap = leapYear (year);

    for (int month = 1; month <= 12; month++)
    {
        if (month == 1)
        {
            cout << "January " << year << endl;        
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);
        }
        else if (month == 2)
        {
            cout << "February " << year << endl;
            if (leap == true)
            {
                lastDayInMonth = printMonthCalender(29, lastDayInMonth);
            }
            else if (leap == false)
            {
                lastDayInMonth = printMonthCalender(28, lastDayInMonth);
            }
        }
        else if (month == 3)
        {
            cout << "March " << year << endl;
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);
        }
        else if (month == 4)
        {
            cout << "April " << year << endl;
            lastDayInMonth = printMonthCalender(30, lastDayInMonth);
        }
        else if (month == 5)
        {
            cout << "May " << year << endl;
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);
        }
        else if (month == 6)
        {
            cout << "June " << year << endl;
            lastDayInMonth = printMonthCalender(30, lastDayInMonth);
        }
        else if (month == 7)
        {
            cout << "July " << year << endl;
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);
        }
        else if (month == 8)
        {
            cout << "August " << year << endl;
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);

        }
        else if (month == 9)
        {
            cout << "September " << year << endl;
            lastDayInMonth = printMonthCalender(30, lastDayInMonth);
        }
        else if (month == 10)
        {
            cout << "October " << year << endl;
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);
        }
        else if (month == 11)
        {
            cout << "November " << year << endl;
            lastDayInMonth = printMonthCalender(30, lastDayInMonth);
        }
        else if (month == 12)
        {
            cout << "December " << year << endl;
            lastDayInMonth = printMonthCalender(31, lastDayInMonth);
        }
        cout << endl;
    }
}