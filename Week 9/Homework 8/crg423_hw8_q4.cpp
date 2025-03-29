// Stores an actual 5-digit PIN number as a constant
// Uses an array to assign random numbers to the digits from 0 to 9
// Outputs the random digits to the screen, inputs the response of the user
// Outputs whether or not the user's response correctly matches the PIN number

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constants
const int PIN[5] = {1, 2, 3, 4, 5};
const int MAP_SIZE = 10;

// Function Declarations
void printArr(int arr[], int arrSize);
// Takes an array of integers, arr, and its logical size, arrSize
// Prints the values of the integers within arr

void createRandomDigits(int arr[], int arrSize);
// Takes an empty array of integers, arr, and its logical size, arrSize
// Assigns random numbers between 1 and 3 to the indices of arr

void createCorrectSequence(int arr[], string& correct_order);
// Takes the array containing random digits as arr
// Alters the string, correc_order, with the correct sequence of digits that corresponds to the PIN

bool checkPIN(string str, string correct_order);
// Takes the input sequence of digits as a string, str
// Takes the correct sequence of digits that correspinds to the PIN, correct_order
// Checks if the inputted sequence is correct

int main()
{
    string correct_order;
    string input;

    cout << "Please enter your PIN according to the following mapping:" << endl; 
    cout << "PIN:\t0 1 2 3 4 5 6 7 8 9" << endl;

    int num[MAP_SIZE]; 
    srand(time(0));
    createRandomDigits(num, MAP_SIZE);

    cout << "NUM:\t";
    printArr(num, MAP_SIZE);

    createCorrectSequence(num, correct_order);

    cin >> input;
    if (checkPIN(input, correct_order))
        cout << "Your PIN is correct" << endl;
    else 
        cout << "Your PIN is not correct" << endl;

    return 0;
}

void printArr(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void createRandomDigits(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        int random = (rand() % 3) + 1;
        arr[i] = random;
    }
}

void createCorrectSequence(int arr[], string& correct_order)
{
    char ch;
    for (int i = 0; i < 5; i++)
    {
        ch = (char)arr[PIN[i]] + '0';
        correct_order = correct_order + ch;
    }
}

bool checkPIN(string str, string correct_order)
{
   return str == correct_order;
}