// Implements a recursive function that solves the "Jump It" problem
// Outputs the lowest total cost (sum) of the cost of the visited coloumns on the game board

#include <iostream>
using namespace std;

// Constants
const int n = 6;

// Function Declarations
int lowestCost(int arr[], int arrSize);
// Takes the game board as an array of integers, arr, and its logical size, arrSize
// Returns the lowest cost of the game board by recursively evaluating all possible paths


int main()
{
    int gameBoard[n] = {0, 3, 80, 6, 57, 10};
    int cost = lowestCost(gameBoard, n);
    cout << "The lowest cost is: " << cost << endl;

    return 0;
}

int lowestCost(int arr[], int arrSize)
{
    if (arrSize <= 3)               // Base Case: arrSize <= 3 (if there are 3 or less columns on the game board)
        return arr[arrSize - 1];
    else                            // Recursive Case: arrSize > 3 (there are more than 3 columns on the game board)
    {
        // calculate the cost of a one-step jump
        int oneJump = arr[arrSize - 1] + lowestCost(arr, arrSize - 1);

        // calculate the cost of a two-step jump
        int twoJump = arr[arrSize - 1] + lowestCost(arr, arrSize - 2);

        // return the smaller of the two costs
        if (oneJump < twoJump)
            return oneJump;
        else
            return twoJump;
        
    }
}