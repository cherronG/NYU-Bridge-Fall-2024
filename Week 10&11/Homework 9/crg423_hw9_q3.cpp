// Contains 4 versions of a function getPosNums that gets an array of integers arr, and its logical size
// Each version creates a new array containing only the positive numbers from arr

#include <iostream>
using namespace std;

// Constants
const int arrSize = 6;


// Function Declarations
void printArray(int arr[], int arrSize); 
// Takes an array of intergers, arr, and its logical size, arrSize
// Prints all the values of the integers within arr

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
// Takes the address of the orginial array, arr, and its logical size, arrSize
// References to the variable for the size of the new array (containing the positive numbers)
// Returns the base address of the array (containing the positive numbers) 
// Updates the output parameter outPosArrSize with the array's logical size

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
// Takes the address of the original array, arr, and its logical size, arrSixe
// References to the variable for the size of the new array (containing the positive numbers)
// Returns the base address of the array (containing the positive numbers)
// Uses the pointer outPosArrSizePtr to update the array's logical size

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
// Takes the address of the original array, arr, and its logical size, arrSize
// Takes the address of the new array (containing the positive numberes)
// References to the variable for the size of the new array
// Updates the output parameter outPosArr with the base address of the array (containing the positive numbers)
// Updates the output parameter outPosArrSize with the array's logical size

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* PosArrSizePtr);
// Takes the address of the original array, arr, and its logical size, arrSize
// References the pointer of the new array (containing the positive numbers)
// Takes the address of the variable containing the size of the new array
// Uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers)
// Uses the pointer outPosArrSizePtr to update the array's logical size


int main()
{
    int arr[6] = {3, -1, -3, 0, 6, 4};
    int *odd_and_even = arr;

    // print values of orginial array
    cout << "Original Array of Size " << arrSize << ": ";
    printArray(arr, arrSize);

    // function version 1
    int PosArrSize1 = 0;
    int *PosArr1 = getPosNums1(odd_and_even, arrSize, PosArrSize1);
    cout << "Version 1 Array of Size " << PosArrSize1 << ": ";
    printArray(PosArr1, PosArrSize1);

    // function version 2
    int PosArrSize2 = 0;
    int *PosArr2 = getPosNums2(odd_and_even, arrSize, &PosArrSize2);
    cout << "Version 2 Array of Size " << PosArrSize2 << ": ";
    printArray(PosArr2, PosArrSize2);

    // function version 3
    int *PosArr3 = new int [arrSize];
    int PosArrSize3 = 0;
    getPosNums3(odd_and_even, arrSize, PosArr3, PosArrSize3);
    cout << "Version 3 Array of Size " << PosArrSize3 << ": ";
    printArray(PosArr3, PosArrSize3);


    // function version 4
    int *PosArr4 = new int [arrSize];
    int **PosArr4Ptr = &PosArr4;
    int PosArrSize4 = 0;
    getPosNums4(odd_and_even, arrSize, PosArr4Ptr, &PosArrSize4);
    cout << "Version 4 Array of Size " << PosArrSize4 << ": ";
    printArray(PosArr4, PosArrSize4);

    // delete and nullify pointers
    delete [] PosArr1;
    PosArr1 = nullptr;
    delete [] PosArr2;
    PosArr2 = nullptr;
    delete [] PosArr3;
    PosArr3 = nullptr;
    delete [] PosArr4;
    PosArr4 = nullptr;

    return 0;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl; 
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
{
   // creates a new, empty array
   int *even_only = new int [arrSize];
   int currentpos = 0;

    // adds only positive numbers to the new array
    for(int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            even_only[currentpos] = arr[i];
            currentpos++;
        }
    }

    // updates the new array size
    outPosArrSize = currentpos++;
    return even_only;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
{
    // creates a new, empty array
    int *even_only = new int [arrSize];
    int currentpos = 0;

    // adds only positive nmbers to the new array
    for(int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            even_only[currentpos] = arr[i];
            currentpos++;
        }
    }

    // dereference the pointer to update the value of the new array size
    *outPosArrSizePtr = currentpos++;
    return even_only;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
    int currentpos = 0;

    // adds only positive numbers to the new array
    for(int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            outPosArr[currentpos] = arr[i];
            currentpos++;
        }
    } 

    // updates the new array size
    outPosArrSize = currentpos++;  
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* PosArrSizePtr)
{
    int currentpos = 0;

    // adds only positive numbers to the new array
    for(int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            // must dereference the pointer to modify the values
            (*outPosArrPtr)[currentpos] = arr[i];
            currentpos++;
        }
    }

    // dereference the pointer to update the value of the array size
    *PosArrSizePtr = currentpos++;
}