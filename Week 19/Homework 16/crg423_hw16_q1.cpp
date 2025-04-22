// Implements a symbol balance checker function for the Pascal programming language

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure Defintiions
struct Node
{
    char data;      // value of the node
    Node* next;     // pointer to the next node
};


// Class Definitions
class Stack
{
    private:
        Node* head;     // pointer to the first node at the top of the stack
    
    public:
        Stack() : head(nullptr) {} 
        // Constructor for the Stack class
        // Creates an empty stack of an empty linked list, with head initialized to nullptr

        ~Stack() { clear(); }
        // Destructor to properly cleanup the dynamically allocated nodes

        void push(const char& newData);
        // Pushes a new element onto the stack

        void pop();
        // Pops the top element off of the stack

        char top() const;
        // Returns the top element on the stack without removing it

        bool isEmpty() const { return (head == nullptr); }
        // Returns true if the stack is empty; otherwise returns false

        void clear();
        // Properly cleans up the dynamically allocated nodes
};

// Additional Function Declarations
void inputStream(ifstream& inStream);
// Takes the input stream, inSteam, and ensures that the input file is correctly opened before the program continues
// Asks user to type the file name again if the input file failed to open

bool validInput(ifstream& inFile);
// Takes the input stream containing the input file, inFile
// Returns true if inFile starts with the word "begin"; otherwise, returns false

bool symbolBalanceChecker(ifstream& inputFile);
// Takes the input stream containing the inputFile, inputFile
// Returns true if the symbols in inputFile are balanced; otherwise, returns false


// Main
int main() 
{
    // open input file
    ifstream inputFile;
    inputStream(inputFile);

    // call the checker function
    if (symbolBalanceChecker(inputFile))
        cout << "Symbols are balanced" << endl;
    else
        cout << "Symbols are not balanced" << endl;

    // close input file
    inputFile.close();
    return 0;
}


// Stack Class Member Funciton Definitions
void Stack::push(const char& newData)
{
    Node* newNode = new Node;   // create a new node
    newNode->data = newData;    // set the data member variable
    newNode->next = head;       // set the next link as the head
    head = newNode;             // make the new node as the head of the stack
}

void Stack::pop()
{
    if (isEmpty())
    {
        cout << "Error: Cannot pop an empty stack" << endl;
        exit(1);
    }

    Node* temp = head;  // store the current top node
    head = head->next;  // move the head to the next node
    delete temp;        // free memory of the old top node
}

char Stack::top() const
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return head->data;
}

void Stack::clear()
{
    while (!isEmpty())
        pop();
}


// Additional Function Definitions
void inputStream(ifstream& inStream)
{
    string fileName;
    cout << "Enter input file name: ";
    cin >> fileName;
    inStream.open(fileName);

    while (inStream.fail())
    {
        cout << "Input file failed to open. Please try another file name: ";
        cin >> fileName;
        inStream.clear();
        inStream.open(fileName);
    }
}

bool validInput(ifstream& inFile)
{
    char character;
    inFile >> character;
    if (character == 'b')
    {
        inFile >> character;
        if (character == 'e')
        {
            inFile >> character;
            if (character == 'g')
            {
                inFile >> character;
                if (character == 'i')
                {
                    inFile >> character;
                    if (character == 'n')
                        return true;
                }
            }
        }
    }
    return false;
}

bool symbolBalanceChecker(ifstream& inputFile)
{
    Stack symbols;
    string word;
    char symbol;

    // check that the first word in the file is "begin"
    if (!validInput(inputFile))
    {
        cout << "Error: Input file does not start with 'begin'" << endl;
        exit(1);
    }

    while (inputFile >> symbol)
    {
        if ((symbol == '{') || (symbol == '(') || (symbol == '['))
            symbols.push(symbol);     // push the opening symbols onto the stack
        else if ((symbol == '}') || (symbol == ')') || (symbol == ']'))
        {
            // if the stack is empty -> symbols are not balanced (return false)
            if (symbols.isEmpty())
                return false;

            char topSymbol = symbols.top();

            // pop if there is a matching pair; otherwise the symbols are not balanced (return false)
            if ((symbol == '}' && topSymbol == '{') ||
                (symbol == ')' && topSymbol == '(') ||
                (symbol == ']' && topSymbol == '['))
                symbols.pop();
            else 
                return false;
        }

        // check if 'e' is encountered as part of the word "end"
        if (symbol == 'e')
        {
            inputFile >> symbol;
            if (symbol == 'n')
            {
                inputFile >> symbol;
                if (symbol == 'd')
                    break;
            }
            else    // put the character after 'e' back into the stream
                inputFile.putback(symbol);
        }
    }

    // check if there is no extra input after "end"
    string leftover;
    if (inputFile >> leftover)
    {
        cout << "Error: Extra input found after 'end': " << leftover << endl;
        exit(1);
    }

    return symbols.isEmpty();   // if stack is now empty -> symbols are balanced
}