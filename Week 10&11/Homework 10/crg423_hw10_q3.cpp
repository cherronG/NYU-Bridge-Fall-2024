// Implements two versions of a program that reads from the user a sequence of positive integers ending with -1
// The user should also input another positive integer, num, that the user wishes to search for
// Both programs prints all the line numbers in the sequence entered by the user that contain num, or a message saying that num does not show at all in the sequence

#include <iostream>
#include <vector>
using namespace std;

// Constants:
const int defaultMaxInput = 10;

// Version 1 Function Declarations:
int main1();
// Version of the program that does not use the vector data structure

void resizeArr(int*& arr, int arrSize, int newArrSize);
// Takes the array containing the previously inputted values, arr, and its logical size, arrSize
// Takes the doubled size that will be used to create the larger array, newArrSize
// Adds the previously inputted values to the new, larger array, and deletes the old smaller array
// Changes the address of the pointer of the old array to the address of the new, larger array

int* findNum1(int arr[], int arrSize, int num, int& linesIndex);
// Takes the array containing the inputted integers, arr, and its logical size, arrSize
// Takes the positive integer that the user wishes to search for, num
// Returns an array containing the lines at which num occurs
// Updates the logical size of the new array, linesIndex

void printArrResults(int linesArr[], int linesArrSize, int num);
// Takes the the positive integer the user wishes to search for, num
// Takes the array containing the lines at which num occurs, linesArr[], and its logical size, linesArrSize
// Prints the values within linesArr[], or indicates that num was not found

// Version 2 Function Declarations:
int main2();
// Version of the program that uses the vector data structure

vector<int> findNum2(const vector<int>& sequence, int num);
// Takes the vector containing the inputted sequence, sequence, and the positive integer the user wishes to search for, num
// Returns a vector containing the lines at which num occurs

void printVectorResults(const vector<int>& linesVector, int num);
// Takes the positive integer the user wishes to search for, num and the vector containing the lines at which num occurs, linesVector
// Prints the values within linesVector, or indicates that num was not found


int main()
{
    cout << "Version 1:" << endl;
    main1();
    cout << endl;

    cout << "Version 2:" << endl;
    main2();
    return 0;
}

int main1()
{
    int num, input = 0, index = 0, count = 0, size = defaultMaxInput;
    int *arr = new int [defaultMaxInput]; // creates a new array to store inputted values with a max of 10 values

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1." << endl;

    while (input != -1)
    {
        cin >> input;
        if (input != -1)
        {
            arr[index] = input;     // adds the inputted value to the array
            index++;       // go to the next index
            count++;       // update the input count
            
            // resize array if the amount of input values exceed the default 10
            if (count == defaultMaxInput)
            {
                resizeArr(arr, count, size * 2); 
                size = size * 2;    // increase the size of the array
            }
        }
    }

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    int lines = 0;
    int *lineArr = findNum1(arr, defaultMaxInput, num, lines);
    printArrResults(lineArr, lines, num);

    // delete and nullify pointer
    delete[] arr;
    arr = nullptr;
    delete[] lineArr;
    lineArr = nullptr;

    return 0;
}

void resizeArr(int*& arr, int arrSize, int newArrSize)
{
    int *newArr = new int [newArrSize];     // creates a new array with a larger index

    // searches through the old array containing the previously inputted values
    for (int i = 0; i < arrSize; i++)
        newArr[i] = arr[i];     // adds the previously inputted values to the new array
    
    // delete the old array and set the old array pointer to the address of the new array
    delete[] arr; 
    arr = newArr;
}

int* findNum1(int arr[], int arrSize, int num, int& linesIndex)
{
    int *lines = new int [arrSize];     // creates a new array to contain the the lines at which num is located

    // searches through the inputted sequence for num
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == num)      // if num is in the sequence
        {
            lines[linesIndex] = i + 1;      // adds the lines at which num is located
            linesIndex++;       // go to the next index
        }
    }
    return lines;       // returns the lines array
}

void printArrResults(int linesArr[], int linesArrSize, int num)
{
    if (linesArrSize == 0)      // if no values were put into linesArr[]
    {
        cout << num << " is not in the inputted sequence" << endl;
    }
    else        // if values were put into linesArr[]
    {
        cout << num << " shows in lines ";
        for (int i = 0; i < linesArrSize; i++)
        {
            cout << linesArr[i];
            if (i == linesArrSize - 1)      // when at the last value put into linesArr[] (rest are 0's)
                cout << "." << endl;
            else        // if there are still values in linesArr[] (other than 0)
                cout << ", ";
        }
    }
}

int main2()
{
    int input = 0, num;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End your input by typing -1." << endl;

    vector<int> sequence;   // creates a new vector to hold the inputted sequence
    while (input != -1)     // loop continues until -1 is inputted
    {
        cin >> input;   // must read the inputted number before executing 
        if (input != -1)    // as long as the inputted number is not -1
            sequence.push_back(input);      // adds the input into the sequence vector
    }

    cout << "Please enter a number you want to search." << endl;
    cin >> num;

    vector<int> linesVector = findNum2(sequence, num);
    printVectorResults(linesVector, num);

    return 0;
}

vector<int> findNum2(const vector<int>& sequence, int num)
{
    vector<int> lines;      // creates a new vector to hold the lines at which num occurs

    // searches through the inputted sequence for num
    for (int i = 0; i < sequence.size(); i++)
    {
        if (sequence[i] == num)         // if num is in sequence
            lines.push_back(i + 1);     // adds the line (sequence index + 1) number at which num occurs to lines vector
    }
    return lines; // return lines vector
}

void printVectorResults(const vector<int>& linesVector, int num)
{
    if (linesVector.size() == 0)    // if no values were put into linesVector
    {
        cout << num << " is not in the inputted sequence" << endl;
    }
    else        // if values were put into linesVector
    {
        cout << num << " shows in lines ";
        for (int i = 0; i < linesVector.size(); i++)
        {
            cout << linesVector[i];
            if (i == linesVector.size() - 1)    // when at the last value put into linesVector
                cout << "." << endl;
            else        // if there are still values in linesVector
                cout << ", ";
        }
    }
}