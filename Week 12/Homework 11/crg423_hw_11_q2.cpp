// Recursively implements the functions sumOfSquares and isSorted 
#include <iostream>
using namespace std;

// Constants 
const int SIZE = 4;


// Function Declarations
int sumOfSquares(int arr[], int arrSize);
// Takes an array of integers, arr, and its logical size, arrSize
// Returns the sum of the squares of each of the values in arr

bool isSorted(int arr[], int arrSize);
// Takes an array of intergers, arr, and its logical siz, arrSize
// Returns true if the elements in arr are sorted in an ascending order, or false if they are not


int main()
{
    int arr[SIZE] = {2, -1, 3, 10};

    int sum = sumOfSquares(arr, SIZE);
    cout << "The sum of the squares of the elements in the array is: " << sum << endl;

    if (isSorted(arr, SIZE))
        cout << "The elements of the array are sorted in ascending order." << endl;
    else
        cout << "The elements of the array are not sorted in ascending order." << endl;
    return 0;
}

int sumOfSquares(int arr[], int arrSize)
{
    int square;
    if (arrSize == 1)           // Base Case: arrSize == 1
    {
        // square the value in the array
        square = arr[0] * arr[0];

        // return the squared value
        return square;
    }
    else                        // Recursive Case: arrSize > 1
    {
        // square the value in the last index
        square = arr[arrSize - 1] * arr[arrSize - 1];

        // call the function again and continuously add the square before returning the value
        return sumOfSquares(arr, arrSize - 1) + square;
    }
}

bool isSorted(int arr[], int arrSize)
{
    if (arrSize == 2)           // Base Case: arrSize == 2 (at least two integers in the array)
        return arr[arrSize - 1] >= arr[arrSize - 2];
    else if (arrSize > 2)       // Recursive Case: arrSize > 2 (more than 2 integers in the array)
    {
        // call the function again until it reaches the base
        if (isSorted(arr, arrSize - 1))
            return arr[arrSize - 1] >= arr[arrSize - 2];
            // compare the last two integers
    }
}   