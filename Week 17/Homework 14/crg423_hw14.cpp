// Divide-and-Conquer algorithm that finds the simultaneous max and min of a sequence of N numbers

#include <iostream>
#include <vector>
using namespace std;

// Function Declarations
void printVector(const vector<int>& sequence);
// Takes a vector of integers, sequence, and prints its elements

void printMinMax(const vector<int>& vec);
// Takes a vector of integers, sequence, and prints the minimum and maximum valeues

vector<int> minMax(const vector<int>& sequence, int firstIndex, int lastIndex);
// Takes a vector of integers, sequence, the first index of the intended range, firstIndex, and the last index of the indended range, lastIndex
// Returns a vector containing the mainimum and maximum values in sequence within the range of firstIndex to lastIndex


// Main
int main() 
{
    vector<int> N = {15, 45, -52, 103, 24, 1, -19, 24, 30};
    
    cout << "Integers: ";
    printVector(N);

    vector<int> minMaxVector = minMax(N, 0, N.size() - 1);
    printMinMax(minMaxVector);

    return 0;
}


// Function Definitions
void printVector(const vector<int>& sequence)
{
    for (int i = 0; i < sequence.size(); i++)
        cout << sequence[i] << " ";
    cout << endl;
}

void printMinMax(const vector<int>& vec)
{
    cout << "Min: " << vec.at(0) << endl;
    cout << "Max: " << vec.at(1) << endl;
}

vector<int> minMax(const vector<int>& sequence, int firstIndex, int lastIndex)
{
    vector<int> vec;
    if (firstIndex == lastIndex)                // one item in the sequence
    {
        vec.push_back(sequence.at(firstIndex));
        vec.push_back(sequence.at(firstIndex));
        return vec;
    }    
    else if (lastIndex - firstIndex == 1)       // two items in the sequence
    {
        int num1 = sequence.at(firstIndex);
        int num2 = sequence.at(lastIndex);

        if (num1 > num2)        // first integer is greater than the last integer
        {
            vec.push_back(num2);
            vec.push_back(num1);
        }
        else if (num2 > num1)   // the last integer is greater than the first integer
        {
            vec.push_back(num1);
            vec.push_back(num2);
        }
        return vec;
    } 
    else                                        // more than two items in the sequence 
    {
        // find the midpoint of the intended range
        int half = firstIndex  + (lastIndex - firstIndex) / 2;

        // recursively find the min and max values of the two halves of the sequence
        vector<int> half1 = minMax(sequence, firstIndex, half);
        vector<int> half2 = minMax(sequence, half + 1, lastIndex);

        if (half1.at(0) < half2.at(0))      // if the minimum of the first half is less than the minimum of the second half
            vec.push_back(half1.at(0));
        else                                // if the minimum of the second half is less than the minimum of the first half
            vec.push_back(half2.at(0));

        if (half1.at(1) > half2.at(1))      // if the maximum of the first half is greater than the maximum of the second half
            vec.push_back(half1.at(1));
        else                                // if the mximum of the second half is greater than the maximum of the first half
            vec.push_back(half2.at(1));
        
        return vec;
    }
}