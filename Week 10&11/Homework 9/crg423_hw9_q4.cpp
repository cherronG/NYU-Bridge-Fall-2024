// Reorders the elements of an array of integers

#include <iostream>
using namespace std;

// Constants 
const int arrSize = 6;


// Function Declarations
int countEvenNumbers(int arr[], int arrSize);
// Takes an array of integers, arr, and its logical size, arrSize
// Counts and returns the number of even numbers in arr

bool isEven(int num);
// Takes an integer, num
// Determines if num is even

void swap(int& a, int& b);
// Takes two integers, a and b
// Swaps the values of the integer variables

void printArray(int arr[], int arrSize); 
// Takes an array of intergers, arr, and its logical size, arrSize
// Prints all the values of the integers within arr

void oddsKeepEvensFlip(int arr[], int arrSize);
// Takes an array of intergerm arr, and its logical size, arrSize
// Reorders the elements of arr so that all the odd numbers come before all the even numbers, while also keeping their original relative order
// Reorders the elements of arr so that the even numbers will be placed in a reversed order (relative to their original order)


int main()
{
    int arr[6] = {5, 2, 11, 7, 6, 4};

    cout << "Original Array of Size " << arrSize << ": ";
    printArray(arr, arrSize);

    oddsKeepEvensFlip(arr, arrSize);
    
    cout << "Modified Array of Size " << arrSize << ": ";
    printArray(arr, arrSize);
    
    return 0;
}

int countEvenNumbers(int arr[], int arrSize)
{
    int even_counter = 0;
    
    for (int i = 0; i < arrSize; i++)
    {
        if (isEven(arr[i]))
            even_counter++;
    }
    return even_counter;
}

bool isEven(int num)
{
    return (num % 2 == 0);
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl; 
}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    // create a new array containing only the even numbers
    int even_current_index = 0, even_array_size = countEvenNumbers(arr, arrSize);
    int even_array[even_array_size];

    for (int i = 0; i < arrSize; i++)
    {
        if (isEven(arr[i])) 
        {
            even_array[even_current_index] = arr[i];
            even_current_index++;
        }
    }

    // odd to left, even to right
    int current_index = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (!isEven(arr[i]))
        {
            swap(arr[current_index], arr[i]);
            current_index++;
        }
    }

    // reverse order of even numbers
    int reverse_array_index = even_array_size - 1;
    for (int i = 0; i < even_array_size / 2; i++)
        swap(even_array[i], even_array[reverse_array_index - i]);

    // rewrite even numbers in original array
    for (int i = 0; i < even_array_size; i++)
        arr[current_index + i] = even_array[i];
}