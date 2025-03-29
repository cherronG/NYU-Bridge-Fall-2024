// Reads a word from the user
// Announces to the user if the word is a palidrome or not

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);
// Takes a string, str, containing a word
// Returns true if and only if str is a palindrome

int main()
{
    string word;
    bool palindrome;

    cout << "Please enter a word: ";
    cin >> word;

    palindrome = isPalindrome(word);
    if (palindrome)
        cout << word << " is a palindrome" << endl;
    else 
        cout << word << " is not a palindrome" << endl;

    return 0;
}

bool isPalindrome(string str)
{
    string word_backwards;
    int index;

    // adds characters from str to word_backwards, starting from the last character of the str
    for (index = str.length() - 1; index >= 0; index--)
        word_backwards = word_backwards + str[index];
    
    return word_backwards == str;    
}