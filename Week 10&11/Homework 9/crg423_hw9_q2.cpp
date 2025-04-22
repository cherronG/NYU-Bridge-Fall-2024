// Determines if two strings are anagrams, disregarding any punctuation

#include <iostream>
#include <string>
using namespace std;

// Function Declarations
void letterCount(string line, int letterCounter[]);
// Takes the inputted line of text and the letterCounter[] array with indecies corresponding to each letter's position in the alphabet with "a" being 0
// Updates values at each index as the occurrence for each letter
// Ignores any non-alphabet characters

bool isAnagram(int string_1[], int string_2[]);
// Takes the letterCounter array for the two inputted strings
// Checks if the two arrays are equal by comparing each value


int main()
{
    string string_1, string_2;

    // initialize the letterCounter arrays to avoid any garbage values
    int string_1_letterCounter[26] = {0};
    int string_2_letterCounter[26] = {0};

    cout << "Please enter your first string: " << endl;
    getline(cin, string_1);
    letterCount(string_1, string_1_letterCounter);

    cout << "Please enter your second string: " << endl;
    getline(cin, string_2);
    letterCount(string_2, string_2_letterCounter);

    if (isAnagram(string_1_letterCounter, string_2_letterCounter))
        cout << "The two strings are anagrams." << endl;
    else
        cout << "The two strings are not anagrams." << endl;

    return 0;
}

void letterCount(string line, int letterCounter[])
{
    for(int i = 0; i < line.length(); i++)
    {
        // for lowercase letters
        if ((line[i] >= 'a') && (line[i] <= 'z'))
            letterCounter[line[i] - 'a']++;

        // for uppercase letters
        else if ((line[i] >= 'A') && (line[i] <= 'Z'))
            letterCounter[line[i] - 'A']++;

        // disregard any other characters
        else 
            continue;
    }
}

bool isAnagram(int string_1[], int string_2[])
{
    // compares each value of the arrays (each letter count)
    for (int i = 0; i < 26; i++)
    {
        if (string_1[i] != string_2[i])
            return false;
    }
    return true;
}
