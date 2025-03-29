#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize);
// Takes an array of integers, arr, and its size, arrSize
// Prints the values of the integers within arr

void swapValues(int& value1, int& value2);
// Swaps two integer values

void reverseArray(int arr[], int arrSize);
// Takes an array of integers, arr, and its size, arrSize
// Reorders the elements of the array to appear in a reverse order

void removeOdd(int arr[], int& arrSize);
// Takes an array of integers, arr, and its size, arrSize,
// Alters arr so that the only even numbers remain, still in their original relative order 
// Updates arrSize so it contains the new logical size of the array afer removing the odd numbers

void splitParity(int arr[], int arrSize);
// Takes an array of integers, arr, and its size, arrSize
// Changes the order of numbers in arr so that all odd numbers would appear first and all even numbers appear last
// Inner order of the odd numbers and inner order of the even numbers do not matter

int main()
{
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7 ,14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
        
    return 0;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void swapValues(int& value1, int& value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void reverseArray(int arr[], int arrSize)
{
    int reverse_arr_index = arrSize - 1;

    for (int i = 0; i < arrSize / 2; i++)
        swapValues(arr[i], arr[reverse_arr_index - i]);
}

void removeOdd(int arr[], int& arrSize)
{
    int even_numbers = 0;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arr[even_numbers] = arr[i];
            even_numbers++;
        }            
    }
    arrSize = even_numbers;
}

void splitParity(int arr[], int arrSize)
{
    int temp, index_count2 = 0;

    for (int index_count1 = 0; index_count1 < arrSize; index_count1++)
    {
        if (arr[index_count1] % 2 != 0)
        {
            swapValues(arr[index_count1], arr[index_count2]);
            index_count2++;
        }
    }
}
