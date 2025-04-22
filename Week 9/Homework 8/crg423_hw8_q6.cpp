// Reads in a line of text 
// Outputs the line with all the digits in all integer numbers replaced with "x"

#include <iostream>
#include <string>
using namespace std;

bool isInteger(string word);
// Takes in a word from the original line
// Checks if the word consists of only digits
// Returns true if the word is an integer

string replaceNumbers(string word);
// Takes in a word from the original line of text 
// Returns a new word with all digits replaced by 'x' if the word is an integer

string searchLine(string line);
// Takes in the original line of text enter by the user
// Searches through the line word-by-word to and adds the modified words to a new line
// Returns the newly-created line

int main()
{
    string line;
    cout << "Please enter a line of text: " << endl;
    getline(cin, line);

    cout << searchLine(line);

    return 0;
}

bool isInteger(string word)
{
    // searches through each character in the word
    for (int i = 0; i < word.length(); i++)
    {
        // checks if the character is within the range of digits on the ASCII table
        if ((word[i] < '0') || (word[i] > '9'))
            return false;
    }
    return true;
}

string replaceNumbers(string word)
{
    // first checks if the word is an integer
    if (isInteger(word))
    {
        string new_word;

        // changes each character to "x" if the word is an integer
        for (int i = 0; i < word.length(); i++)
            new_word = new_word + 'x';
        return new_word;
    }
    else // returns the word without any alterations if the word is not an integer
        return word;
}

string searchLine(string line)
{
    string new_line;

    // searches through the inputted line and adds the modified word to the new line
    for (int i = 0; i < line.length(); i++)
    {
        string word;

        // adds each character until a space is encountered to form a word
        while (i < line.length() && line[i] != ' ')
        {
            word = word + line[i];
            i++;
        }
        new_line = new_line + replaceNumbers(word) + ' ';
    }
    return new_line;
}