// Reads from the user a sequence of 20 integers into an array
// Outputs the minimum value and all indices it appears in the array

#include <iostream>
using namespace std;

// Constants
const int SIZE = 20;

//Function Declarations
int minInArray(int arr[], int arrSize);
// Takes in an array of integers, arr, and its logical size, arrSize
// Returns the minimum value in arr
void minIndices(int arr[], int arrSize, int min);
// Takes an array of integers, arr,its logical size, arrSize, and the minimum value in arr, min
// Prints the indices in which min is located in arr

int main()
{
    int integers[SIZE];
    int min;

    cout << "Please enter 20 integers separated by a space:" << endl;

    //reads the integers
    for (int i = 0; i < SIZE; i++)
        cin >> integers[i];

    min = minInArray(integers, SIZE);

    cout << "The minimum value is " << min << ", and it is located in the following indices: ";
    minIndices(integers, SIZE, min);

    return 0;
}

int minInArray(int arr[], int arrSize)
{
    int min = arr[0];

    //searches through array for the lowest value
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void minIndices(int arr[], int arrSize, int min)
{
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] == min)
            cout << i << " "; 
    }
}