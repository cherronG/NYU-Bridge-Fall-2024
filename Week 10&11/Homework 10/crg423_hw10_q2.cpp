// Implements the function findMistting that creates an array containing the numbers missing from an original array
// The original array contains n elements in the range {0, 1, 2,..., n} of size n+1
// There must be at least one number that is missing (could be more than one number missing, if there are duplicate values in the original array)

#include <iostream>
using namespace std;

// Constants:
const int arrSize = 6;


// Function Declarations:
int* findMissing(int arr[], int n, int& resArrSize);
// Takes an array of integers, arr, and its logical size, n
// Creates and returns a new array that contains all the numbers in range {0, 1, 2,..., n} that are not in arr
// Updates the output parameter, resArrSize, with the logical size of the array that was created

void printArray(int arr[], int arrSize);
// Takes an array of integers, arr, and its logical size, arrSize
// Prints the elements within the array 


int main()
{
    int arr[arrSize] = {3, 1, 3, 0, 6, 4};
    int missingNums = 0;

    // missingNums != size of the new array; size of new array = missingNums-1
    int *missingNumsPtr;
    
    missingNumsPtr = findMissing(arr, arrSize, missingNums);
    
    cout << missingNums << " missing numbers: ";
    printArray(missingNumsPtr, missingNums);

    // delete and nullify pointer
    delete[] missingNumsPtr;
    missingNumsPtr = nullptr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize)
{
    int occurrence[n+1];        // creates a new array for the occurrences of values in range {0,1,2,...,n}
    int *missingNumPtr = new int [n];       // creates a new array for the missing numbers referred to using the pointer, missingNumPtr
    int index = 0, missingNumCount = 0;

    // initialize the occurrences to 0
    for (int i = 0; i < n+1; i++)
        occurrence[i] = 0;
    
    // update the occurrence of the arr[] values 
    for (int i = 0; i < n; i++)
        occurrence[arr[i]]++;

    // checks if the occurrence of i correspinding to the values in range {0,1,2,...,n} is o
    for (int i = 0; i < n + 1; i++)
    {
        if (occurrence[i] == 0)     // if i is not in arr[]
        {
            missingNumPtr[index] = i;       // add i to the new array
            index++;        // go to the next index
            missingNumCount++;      // update count for the amount of missing numbers
        }
    }

    // update value of resArrSize
    resArrSize = missingNumCount;

    // return address of missingNumPtr[]
    return missingNumPtr;
}

void printArray(int arr[], int arrSize)
{
    cout << "[ ";
    // will only print the indices containing values
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}