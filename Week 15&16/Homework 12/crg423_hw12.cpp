// Reads in the old account balance
// Reads in how many checks will be entered, the number of each check (int), and the amount of the check (double)
// Reads in whether or not it has been cashed (1 or 0, boolean in the array)
// Reads in all deposits and how many deposits will be inputted
// Outputs the total of the deposits and the total of the checks cashed
// Outputs a list of checks cashed, and a list of checks that have not been cashed
// Outputs the new balance, and the difference between this figure and the bamk balance
// Money class and all of its related functions are from the textbook

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
using namespace std;


// Class Definitions
class Money
// values of this type are amounts of money in US currency
{
    
    private:
        long all_cents;
    
    public:
        friend Money operator +(const Money& amount1, const Money& amount2);
        // Returns the sum of the values of amount1 and amount2

        friend Money operator -(const Money& amount1, const Money& amount2);
        // Returns amount1 - amount2

        friend Money operator -(const Money& amount);
        // Returns the negative of the value of aamount

        Money(long dollars, int cents);
        // Initializes the object so its value represents an amount with the dollars and cents given as arguments
        // If the amount is negative, then both dollars and cents should be negative

        Money(long dollars);
        // Initializaes the object so its value represents $dollars.00

        Money();
        // Initializes the object so its value represents $0.00

        double get_value() const;
        // Returns the amount of money recorded in the data portion of the calling object

       friend ostream& operator <<(ostream& outs, const Money& amount);
        // Overloads the << operator so it can be used to output values of type Money
        // Precedes each output value of type Money with a dollar sign
        // Precondition: If outs is a file output stream, then outs has already been connected to a file
};

class Check
{
    private:
        int check_num;
        Money check_amount;
        bool check_cashed;

    public:
        Check();
        // Initializes the object as a blank check of $0.00 that was not casded with 0 as its check number

        Check(int num, Money amount, bool cashed);
        // Initializes the object with the check number, amount and whether it was cashed or not as arguments

        bool Cashed() const;
        // Returns true if the check has been cashed or false if check was not cashed

        friend Money operator +(Money amount, Check check);
        // Returns the sum of amount and the check_amount of check

        friend ostream& operator <<(ostream& outs, const Check& check);
        // Overloads the << operator so it can be used to output values of type Check
        // Prints only the check_num that is used to identify the check
};


// Function Declarations
void doubleToMoney(double decimal, Money& money);
// Takes a decimal number of type double, decimal, and a Money type initialized as $0.00, money
// Converts decimal to Money type, and assigns it to money

void obtainChecks(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Adds Check objects to arr with their inputted values as their associated member variables 

void printCashedChecks(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Prints the check numbers of the cashed checks

void printUncashedChecks(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Prints the check numbers of the checks that were not cashed

void totalCashed(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Prints the amount of cashed checks in arr, and the check numbers of those cashed checks

void categorizeChecks(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Prints the amount of cashed checks in arr, and the check numbers of those checks
// Prints the check numbers of the checks that were not cashed

Money totalDeposits(double arr[], int arrSize);
// Takes an array of decimals, arr, containing the inputted deposits, and its logical size, arrSize
// Prints and returns the sum of the deposits

Money obtainDeposits();
// Obtains the inputted deposits 
// Prints and returns the the sum of the deposits

Money amountCashed(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Returns the sum of the check amounts of the cashed checks 

Money amountUncashed(Check arr[], int arrSize);
// Takes an array of Checks, arr, and its logical size, arrSize
// Returns the sum of the check amounts of the uncashed checks

Money updateBalance(Money old_balance, Money deposits, Money cashed);
// Takes the old account balance (old_balance), and the sum of all the inputted deposits (deposits)
// Takes the sum of the check_amounts of the cashed checks (cashed)
// Prints and returns the new account balance 

Money checkbookBalance(Money old_balance, Money deposits, Money cashed, Money uncashed);
// Takes the old account balance (old_balance), and the sum of all the inputted deposits (deposits)
// Takes the sum of the check_amounts of the cashed checks (cashed), and the sum of the check_amounts of the uncashed checks (uncashed)
// Prints and returns the difference between the new account balance and the bank balance

void balanceDifference(double prev_balance, Money deposit, Check arr[], int arrSize);
// Takes the old account balance, prev_balance, and the sum of the inputted deposits
// Takes an array of Checks, arr, and its logical size, arrSize
// Prints the new account balance, and the current checkbook balance
// Prints the difference between the bank balance and the checkbook balance


// Main
int main()
{
    int check_count;
    double previous_balance;
    
    // obtain old account balance
    cout << "Welcome to your checkbook. \n Please enter your previous check balance in the format dollars.cents: $";
    cin >> previous_balance;

    // obtain the amount of checks to be entered
    cout << "How many checks do you want to add to your checkbook? ";
    cin >> check_count;

    // create a pointer to an array containing the inputted checks with all their member variables
    Check* check_ptr = new Check[check_count];
    obtainChecks(check_ptr, check_count);

    // obtain deposits and their total
    Money deposit = obtainDeposits();
    
    // categorize checks as cashed or uncashed
    categorizeChecks(check_ptr, check_count);

    // determine bank balance and checkbook balance difference
    balanceDifference(previous_balance, deposit, check_ptr, check_count);

    cout << endl << "Checkbook balancing complete." << endl;

    // delete and nullify pointers
    delete[] check_ptr;
    check_ptr = nullptr;
    
    return 0;
}


// Money Class Functions
Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0)        // if one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents." << endl;
        exit(1);
    }
    
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100)
{
    // body intentially left blank
}

Money::Money() : all_cents(0)
{
    // body intentially left blank
}

double Money::get_value() const
{
    return (all_cents * 0.01);
}


// Money Overloaded Operations
Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "- $" << dollars << ".";
    else 
        outs << "$" << dollars << ".";
    
    if (cents < 10)
        outs << '0';
    
    outs << cents;

    return outs;
}


// Check Class Functions
Check::Check(int num, Money amount, bool cashed)
{
    check_num = num;
    check_amount = amount;
    check_cashed = cashed;
}

Check::Check()
{
    check_num = 0;
    check_amount = Money();
    check_cashed = 0;
}

bool Check::Cashed() const
{
    return check_cashed;
}


// Check Overloaded Operations
Money operator +(Money amount, Check check)
{
    Money sum = amount + check.check_amount;
    return sum;
}

ostream& operator <<(ostream& outs, const Check& check)
{
    int number = check.check_num;
    outs << number;
    return outs;
}


// Additional Function Definitions 
void doubleToMoney(double decimal, Money& money)
{
    long dollars = static_cast<long>(decimal);
    int cents = static_cast<int>(round((decimal - dollars) * 100));
    money = Money(dollars, cents);
}

void obtainChecks(Check arr[], int arrSize)
{
    // iterates for the inputted amount of checks to be entered
    for (int i = 0; i < arrSize; i++)
    {
        int check_num;
        double check_amount;
        bool cashed;

        // to indicate current iteration/inputted check
        cout << endl << "Check #" << i + 1 << endl;

        // obtain check member variable values
        cout << "Check Number: ";
        cin >> check_num;
        cout << "Has this check been cashed? Enter '1' for yes or '0' for no: ";
        cin >> cashed;
        cout << "Please enter the following in the format dollars.cents. ";
        cout << "If the amount is negative, use format -dollars.cents." << endl;
        cout << "Check Amount: $";
        cin >> check_amount;

        // convert check_amount to Money type
        Money amount;
        doubleToMoney(check_amount, amount);
        
        // add new Check object to array
        arr[i] = Check(check_num, amount, cashed);
    }
    cout << endl;
}

void printCashedChecks(Check arr[], int arrSize)
{
    int count = 0;
    cout << "Check numbers of cashed checks: ";
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i].Cashed())
        {
            count++;
            cout << arr[i] << " ";
        }   
        else 
            continue;
    }

    if (arrSize == 0)
        cout << "No checks entered.";
    else if (count == 0)
        cout << "None of the checks were cashed.";
    cout << endl;
}

void printUncashedChecks(Check arr[], int arrSize)
{
    int count = 0;
    cout << "Check numbers of uncashed checks: ";
    for (int i = 0; i < arrSize; i++)
    {
        if (!arr[i].Cashed())
        {
            count++;
            cout << arr[i] << " ";
        }
        else 
            continue;
    }

    if (arrSize == 0)
        cout << "No checks entered.";
    else if (count == 0)
        cout << "All checks were cashed.";
    cout << endl;
}

void totalCashed(Check arr[], int arrSize)
{
    int total_cashed = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i].Cashed())
            total_cashed++;
        else   
            continue;
    }
    cout << "Total checks cashed: " << total_cashed << endl; 
    printCashedChecks(arr, arrSize);
}

void categorizeChecks(Check arr[], int arrSize)
{
    cout << endl;
    totalCashed(arr, arrSize);
    printUncashedChecks(arr, arrSize);
    cout << endl;
}

Money totalDeposits(double arr[], int arrSize)
{
    Money sum = Money(0,0); 
    for (int i = 0; i < arrSize; i++)
    {
        Money temp;
        doubleToMoney(arr[i], temp);
        sum = sum + temp;
    }
    cout << "Total Deposits: " << sum << endl;
    return sum;
}

Money obtainDeposits()
{
    // obtain deposits
    int num_of_deposits;
    cout << "How many deposits will you be entering: ";
    cin >> num_of_deposits;
    cout << "Please enter your deposits. Each should be in a separate line and in the format dollars.cents. " << endl;

    // create a new array to contain the inputted deposits
    double* deposits_ptr = new double[num_of_deposits];

    // iterates for the inputted amount of deposits to be entered
    for (int i = 0; i < num_of_deposits; i++)
    {
        cout << "$";
        cin >> deposits_ptr[i];
    }
    cout << endl;

    // determine the total deposits
    Money total = totalDeposits(deposits_ptr, num_of_deposits);

    delete[] deposits_ptr;
    deposits_ptr = nullptr;
    return total;
}

Money amountCashed(Check arr[], int arrSize)
{
    Money cashed_total = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i].Cashed())
            cashed_total = cashed_total + arr[i];
        else 
            continue;
    }
    return cashed_total;
}

Money amountUncashed(Check arr[], int arrSize)
{
    Money uncashed_total = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (!arr[i].Cashed())
            uncashed_total = uncashed_total + arr[i];
        else 
            continue;
    }
    return uncashed_total;
}

Money updateBalance(Money old_balance, Money deposits, Money cashed)
{
    Money new_balance = old_balance + deposits - cashed;
    cout << "New Balance: " << new_balance << endl; 
    return new_balance;
}

Money checkbookBalance(Money old_balance, Money deposits, Money cashed, Money uncashed)
{
    Money checkbook_balance = old_balance + deposits - cashed - uncashed;
    cout << "Current Checkbook Balance: " << checkbook_balance << endl;
    return checkbook_balance;
}

void balanceDifference(double prev_balance, Money deposit, Check arr[], int arrSize)
{
    // determine new balance
    Money old_balance, new_balance, total_amount_cashed; 
    doubleToMoney(prev_balance, old_balance);
    total_amount_cashed = amountCashed(arr, arrSize);
    new_balance = updateBalance(old_balance, deposit, total_amount_cashed);

    // determine actual checkbook balance 
    Money total_amount_uncashed, checkbook_balance;
    total_amount_uncashed = amountUncashed(arr, arrSize);
    checkbook_balance = checkbookBalance(old_balance, deposit, total_amount_cashed, total_amount_uncashed);
    
    // determine difference between bank balance and checkbook balance 
    Money difference = new_balance - checkbook_balance;
    cout << "Bank Balance and Checkbook Balance Difference: " << difference << endl;
}