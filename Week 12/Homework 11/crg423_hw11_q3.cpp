// Implements two recursive versions of the function minInArray
// Function generally will be given a sequence of elements and should return the minimum value n that sequence
// The two versions differ in the technique used to pass the sequence to the function

#include <iostream>
using namespace std;

// Function Declarations
int minInArray1(int arr[], int arrSize);
// Takes an array of integers, arr, and its logical size, arrSize
// Finds the minimum value out of all the elements in positions: 0, 1, 2,..., arrSize-1

int minInArray2(int arr[], int low, int high);
// Takes an array of integers, arr, and two additional indecies, low and high (low <= high)
// The indecies indicate the range of indices that need to be considered
// Finds the minimum value out of all the elements in positions: low, low+1,..., high


int main()
{
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl;        // should both be -9

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4);               // arr+2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl;        // should both be 3

    return 0;
}

int minInArray1(int arr[], int arrSize)
{
    if (arrSize == 1)           // Base Case: arrSize == 1 (only one value in the array)
        return arr[arrSize - 1];
    else                        // Recursive Case: arrSize > 1 (more than one value in the array)
    {
        // creates a variable, temp, to hold the last value in the array
        int temp = arr[arrSize - 1];
        
        // calls the function again on one less than the original array size
        if (temp < minInArray1(arr, arrSize - 1)) 
            return temp;
        else 
            return arr[arrSize - 2];
    }
}

int minInArray2(int arr[], int low, int high)
{
    if (low == high)            // Base Case: low == high (only one value/index in the range)
        return arr[low];
    else                        // Recursive Case: low < high (more than one value/index in the range)
    {
        // creates a variable, lastValue, to hold the value in the high index
        int lastValue = arr[high];

        // calls the function again on one less than the original range of indices
        if (lastValue < minInArray2(arr, low, high - 1))
            return lastValue;
        else 
            return arr[high - 1];
    }
}