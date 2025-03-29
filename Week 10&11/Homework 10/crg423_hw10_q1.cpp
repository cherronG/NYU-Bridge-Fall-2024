// Implements a function createWordsArray that creates an array that contains all the words in an inputted sentence
// Assumes that the words in the sentence are separated by a single space

#include <iostream>
#include <string>
using namespace std;

// Function Declarations:
void addWordsToArray(string* wordArr, string sentence);
// Takes the address of the array intended to contain the words in sentence, wordArr, and the inputted sentence, sentence
// Adds the words within sentence to wordArr, using spaces and a period to determine the end of the word

string* createWordsArray(string sentence, int& outWordsArrSize);
// Takes a string, sentence, containing an inputted sentence
// Creates and returns a new array (of strings) that contains all the words in sentence
// Updates the output parameter, outWordsArrSize, with the logical size of the new array that was created

void printArray(string* wordArrPtr, int arrSize);
// Takes the address of the array contianing the words in the inputted sentence, wordArrPtr, and the array's logical size
// Prints the elements within the array 


int main()
{
    string sentence;
    int wordArrSize = 0;
    string *wordArrPtr;

    cout << "Please enter a sentence with each word separated by a single space:" << endl;
    getline(cin, sentence);

    wordArrPtr = createWordsArray(sentence, wordArrSize);

    cout << wordArrSize << " words: ";

    printArray(wordArrPtr, wordArrSize);

    // delete and nullify pointer
    delete[] wordArrPtr;
    wordArrPtr = nullptr;

    return 0;
}

void addWordsToArray(string* wordArr, string sentence)
{
    string word = "";
    int index = 0;

    // searches through sentence for each separate word and adds them to wordArr
    for (int i = 0; i < sentence.length(); i++)
    {
        // adds non-space and non-period characters to the word string (assumes there are no other punctuation)
        if ((sentence[i] != ' ') && (sentence[i] != '.'))
            word = word + sentence[i];

        // uses spaces, periods, and the end of the sentence as an indication of the end of a word
        else if ((sentence[i] == ' ') || (sentence[i] == '.') || (i == sentence.length() - 1))
        {
            // adds the word string (if not empty) to wordArr
            if (word.length() > 0)
            {
                wordArr[index] = word;
                index++;
                word = "";      // reset the word string
            }
        }
    }

    // adds word in case there are any characters left after loop
    if (word.length() > 0)
        wordArr[index] = word;
}

string* createWordsArray(string sentence, int& outWordsArrSize)
{
    int wordCount = 0;

    // counts the amount of words in the sentence to serve as the size of the new array
    // uses spaces, periods and the end of the sentence as an indication of the end of a word
    for (int i = 0; i < sentence.length(); i++)
    {
        if ((sentence[i] == ' ') || (sentence[i] == '.') || (i == sentence.length() - 1))
            wordCount++;
    }

    // updates the array size with the word count
    outWordsArrSize = wordCount;

    // creates a new array to contain the words within the sentence
    string *wordArr = new string[wordCount];
    addWordsToArray(wordArr, sentence);
    
    //returns the address of the new array
    return wordArr;
}

void printArray(string* wordArrPtr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        cout << "'" << wordArrPtr[i] << "' ";
    cout << endl;
}