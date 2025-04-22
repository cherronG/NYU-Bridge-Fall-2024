// Reads a line of text and outputs the number of words in the line and the number of occurences of each letter

#include <iostream>
#include <string>
using namespace std;

// Function Declaractions
void findWords(string line, int& words);
// Takes the inputted line and word counter
// Updates and returns the word counter as it searches through the line of text for spaces, commas, and periods

void letterCount(string line);
// Takes the inputted line of text
// Creates the letterCounter[] array with indecies corresponding to each letter's position in the alphabet with "a" being 0
// Updates values at each index as the occurrence of each letter
// Prints the letters and their occurrences


int main()
{
    string line;
    int words = 0;

    cout << "Please enter a line of text: " << endl;
    getline(cin, line);

    findWords(line, words);
    
    // prints the amount of words
    cout << words << "\twords" << endl;

    letterCount(line);

    return 0;
}

void findWords(string line, int& words)
{
    // initialize word string
    string word = "";

    for(int i = 0; i < line.length(); i++)
    {
        // adds letter to word string if character at i is not a space, comma, or period
        if ((line[i] != ' ') && (line[i] != ',') && (line[i] != '.'))
            word = word + line[i]; 
        // updates word counter and resets word string if character at i is a space, comma, or period
        else if ((line[i] == ' ') || (line[i] == ',') || (line[i] == '.'))
        {
            if (word.length() > 0)
                words++;   

            word = "";
        }
    }
    // updates the word counter in case the inputted line does not end with a space, comma, or period
    if (word.length() > 0)
        words++;
}

void letterCount(string line)
{
    // initialize the array to avoid garbage values
    int letterCounter[26] = {0};

    // updates the value within the index of the letterCounter array that corresponds to the letter's position on ASCII table
    for (int i = 0; i < line.length(); i++)
    {
        // for lowercase letters
        if ((line[i] >= 'a') && (line[i] <= 'z'))
            letterCounter[line[i] - 'a']++;
        //  for uppercase letters
        else if ((line[i] >= 'A') && (line[i] <= 'Z'))
            letterCounter[line[i] - 'A']++;
    }

    // prints the letters and their occurrences if they are present in the line of text
    for (int i = 0; i < 26; i++)
    {
        if (letterCounter[i] > 0)
            cout << letterCounter[i] << "\t" << char(i + 'a') << endl;
    }
}