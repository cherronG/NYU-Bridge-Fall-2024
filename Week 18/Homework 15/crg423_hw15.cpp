// Reads in an external file containing the amount each friend in a group paid, and their names
// Prints out a step-by-step list of instructions for how to reimburse each member of the group

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Class Definitions
class Friend
// represents each member of the friend group, each with their individual attributes
{
    private:
        string name;            // the name of the friend
        double amountPaid;      // the amount the friend paid at first
        double amountDue;       // the amount the friend owes due to paying less than the target amount
        double amountOwed;      // the amount the friend is owed due to paying more than the target amount

    public:
        Friend() : name(""), amountPaid(0), amountDue(0), amountOwed(0) {}
        // Constructor for the Friend class
        // Initializes name to an empty string and all amounts to $0.00

        Friend(string Name, double paid, double due, double owe);
        // Constructor for the Friend class
        // Initializes all member variables to the specified values

        string getName() const { return name; }
        // Returns the name of the friend

        double getAmountPaid() const { return amountPaid; }
        // Returns the amount the friend paid at first

        double getAmountDue() const { return amountDue; }
        // Returns the amount the friend owes due to paying less than the target amount

        double getAmountOwed() const { return amountOwed; }
        // Returns the amount the friend is owed due to paying more than the target amount

        void setName(string Name) { name = Name; }
        // Sets the name member variable to the specified string

        void setAmountPaid(double paid) { amountPaid = paid; }
        // Sets the amountPaid member variable of the associated Friend object to the specified value

        void setAmountDue(double due) { amountDue = due; }
        // Sets the amountDue member variable of the associated Friend object to the specified value

        void setAmountOwed(double owe) { amountOwed = owe; }
        // Sets the amountOwed member variable of the associated Friend object to the specified value
};

class Node
// represents the nodes in the linked list, each containing an object of the Friend class to represent a member of the group
{
    private:
        Friend person;              // an object of the Friend class as the data stored in the node 
        Node* next;                 // pointer linking to the next node
        friend class LinkedList;    // allows LinkedList class to manage the nodes

    public:
        Node() : person(Friend()), next(nullptr) {}
        // Constructor for the Node class
        // Initializes member variables to default attributes 

        Node(Friend member) : person(member), next(nullptr) {}
        // Constructor for the Node class
        // Initializes person member variable to the specified object of the Friend class, and next to nullptr

        Friend& getFriend() { return person; }
        // Returns the Friend object associated with the node

        Node* getNextLink() const { return next; }
        // Returns the pointer linking to the next node

        void setNextLink(Node* ptr) { next = ptr; }
        // Sets next to the specified pointer
};

class LinkedList
// class used to manage the linked list containing the group of friends
{
    private:
        Node* head;     // pointer to the first node of the list

    public:
        LinkedList() : head(nullptr) {}
        // Constructor for the LinkedList class
        // Creates an empty linked list, with head initialized to nullptr

        ~LinkedList();
        // Destructor to properly cleanup the dynamically allocated nodes

        void addToLinkedList(Friend member);
        // Takes the new friend to be added to the linked list, member
        // Adds a new node containing member to the top of the linked list

        void printList();
        // Prints the name of each friend in the linked list,
        // Prints how much each friend is owed and how much tey owe in relation to the target value

        void updateAmounts(const double targetValue);
        // Takes the target amount that would make each friend pay the same amount, targetValue
        // Updates each node to show how much each friend is owed or owes in relation to the targetValue

        void reimburse(const double target);
        // Takes the target amount that would make each friend pay the same amount, target
        // Updates the data in each node to provide step-by-step instructions for reimbursement 
};


// Additional Function Declarations
void inputStream(ifstream& inStream);
// Takes the input stream, inSteam, and ensures that the input file is correctly opened before the program continues
// Asks user to type the file name again if the input file failed to open

void readIn(ifstream& input, LinkedList& list, int& friends, double& total);
// Takes the input stream, input, and the linked list containing the group of friends, list
// Takes the references to the variables containing the total amount of friends in the group, friends, and the bill total, total
// Reads through the input file and adds each friend to the linked list, and updates friends and total

double calculateTarget(const int friends, const double total);
// Takes the total amount of friends in the group, friends, and the bill total, total
// Calculates and returns the target value each friend would pay if the bill was evenly split
// Prints these values to the screen

void moreDue(Node* giver, Node* receiver, double& owed, double& due);
// Takes the pointer to the node containing the friend who owes money, giver, and the pointer to the node containing the friend who is owed money, receiver
// Takes the amount the giver has to pay, due, and the amount the amount the receiver is owed, owed, each in relation to the target value
// Precondition: due > owed
// Manipulates the data to reflect that the giver reimburses the receiver, and prints this step to the screen

void lessDue(Node* giver, Node* receiver, double& due, double& owed);
// Takes the pointer to the node containing the friend who owes money, giver, and the pointer to the node containing the friend who is owed money, receiver
// Takes the amount the giver has to pay, due, and the amount the receiver is owed, owed, each in relation to the target value
// Precondition: due < owed
// Manipulates the data to reflect that the giver reimburses the receiver, and prints this step to the screen

void sameDue(Node* giver, Node* receiver, double& due, double& owed);
// Takes the pointer to the node containing the friend who owes money, giver, and the pointer to the node containing the friend who is owed money, receiver
// Takes the amount the giver has to pay, due, and the amount the receiver is owed, owed, each in relation to the target value
// Precondition: due == owed
// Manipulates the data to reflect that the giver reimburses the receiver, and prints this step to the screen


// Main
int main()
{
    LinkedList group;
    
    int totalFriends = 0;
    double totalPaid = 0;
    double targetValue;

    // open input file
    ifstream inputFile;
    inputStream(inputFile);

    readIn(inputFile, group, totalFriends, totalPaid);
    inputFile.close();

    // format money output with two places after decimal point
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    targetValue = calculateTarget(totalFriends, totalPaid);
    group.reimburse(targetValue);

    return 0;
}


// Friend Member Function Definitions
Friend::Friend(string Name, double paid, double due, double owe)
{
    name = Name;
    amountPaid = paid;
    amountDue = due;
    amountOwed = owe;
}


// LinkedList Member Function Definitions
LinkedList::~LinkedList()
{
    // cycle through the linked list and delete each node pointer
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

void LinkedList::addToLinkedList(Friend member)
{
    Node* newNode = new Node(member);
    newNode->next = head;
    head = newNode;
}

void LinkedList::printList()
{
    Node* current = head;
    while (current)     // cycle through the linked list 
    {
        Friend person = current->person;
        double due = current->person.getAmountDue();
        double owed = current->person.getAmountOwed();
        string name = current->person.getName();

        cout << name << " owes $" << due << " and is owed $" << owed << endl;
        current = current->next;    // move to the next node
    }
    cout << endl;
}

void LinkedList::updateAmounts(const double targetValue)
{
    Node* current = head;
    while (current)     // cycle through the linked list
    {
        double currentPaid = current->person.getAmountPaid();

        if (currentPaid > targetValue)          // friend paid more than target value -> they are owed the difference
            current->person.setAmountOwed(currentPaid - targetValue);
        else if (currentPaid < targetValue)     // friend paid less than target value -> they owe the difference 
            current->person.setAmountDue(targetValue - currentPaid);
        
        current = current->next;    // move to the next node
    }
}

void LinkedList::reimburse(const double target)
{
    updateAmounts(target);      // update the amounts each friend owes or is owed
    printList();                // print the initial state of the linked list

    Node* current = head;       // friend that has to pay money
    Node* recipient = head;     // friend that will receive reimbursement
    double currentDue;          // the amount the current owes
    double currentOwed;         // the amount the current is owed
    double recipientOwed;       // the amount the recipient has to receive
    double giveAmount;          // the amount current has to pay the recipient

    while (current)     // cycle through the linked list
    {
        currentDue = current->person.getAmountDue();
        currentOwed = current->person.getAmountOwed();

        // check if the current person neither owes anything nor is owed anything
        if (currentDue == 0.00 && currentOwed == 0.00)
        {
            cout << current->person.getName() << " does not owe any money" << endl;
        }
        else if (currentDue > 0) // friend paid less than the target value (amountDue > 0)
        {
            while (recipient)   // cycle through linked list again to find a friend who is owed money
            {
                recipientOwed = recipient->person.getAmountOwed();

                if (recipientOwed > 0)  // recipient is owed money (amountOwed > 0)
                {
                    if ((currentDue != 0) && (currentDue > recipientOwed)) // the current friend pays all the receiver is owed
                        moreDue(current, recipient, currentDue, recipientOwed);
                    else if ((currentDue != 0) && (currentDue < recipientOwed))   // the current friend pays all that is due for them
                        lessDue(current, recipient, currentDue, recipientOwed);
                    else if ((currentDue != 0) && (currentDue == recipientOwed))   // the current friend pays all that receiver is owed, fully paying off what is due for them
                        sameDue(current, recipient, currentDue, recipientOwed);
                }
                recipient = recipient->next;    // move to the next node to find the next friend who is owed money
            }
        }
        recipient = head;           // reset recipient to the head of the list for the next iteration
        current = current->next;    // move to the next node for the current friend
    }
}


// Additional Function Definitions
void inputStream(ifstream& inStream)
{
    string fileName;
    cout << "Enter input file name: ";
    cin >> fileName;
    inStream.open(fileName);

    while (inStream.fail())     // iterate again each time the input failed to open
    {
        cout << "Input file failed to open. Please try another file name: ";
        cin >> fileName;
        inStream.clear();   // clear the input stream flags
        inStream.open(fileName);
    }
}

void readIn(ifstream& input, LinkedList& list, int& friends, double& total)
{
    Friend person;
    double amount;
    string name;
    char space;

    while (input >> amount)
    {
        // read in the amount
        person.setAmountPaid(amount);
        total += amount;

        // read in the space
        input.get(space);

        // read in the name
        getline(input, name);
        person.setName(name);

        // add the friend to the linked list
        list.addToLinkedList(person);
        friends++;
    }
}

double calculateTarget(const int friends, const double total)
{
    double target;
    target = total / friends;

    cout << "The bill total was: $" << total << endl;
    cout << "Since there were " << friends << " friend(s) at dinner, the bill will split evenly to: $" << target << endl;
    cout << endl;

    return target;
}

void moreDue(Node* giver, Node* receiver, double& due, double& owed)
{
    double giveAmount;
    string giverName = giver->getFriend().getName();
    string receiverName = receiver->getFriend().getName();

    giveAmount = owed;                                      // giver pays all that the receiver is owed
    giver->getFriend().setAmountDue(due - giveAmount);      // update the giver's amountDue
    due = due - giveAmount;                                 // update the due value 
    receiver->getFriend().setAmountOwed(0);                 // update the receiver's amountOwed
    owed = 0;                                               // update the owed value
    
    cout << giverName << " should give $" << giveAmount << " to " << receiverName << endl;
}

void lessDue(Node* giver, Node* receiver, double& due, double& owed)
{
    double giveAmount;
    string giverName = giver->getFriend().getName();
    string receiverName = receiver->getFriend().getName();

    giveAmount = due;                                       // giver pays all that they were due to pay
    giver->getFriend().setAmountDue(0);                     // update the giver's amountDue
    receiver->getFriend().setAmountOwed(owed - due);        // update the receiver's amountOwed 
    owed = owed - due;                                      // update the owed value
    due = 0;                                                // update the due value (after update the other values)

    cout << giverName << " should give $" << giveAmount << " to " << receiverName << endl;
}

void sameDue(Node* giver, Node* receiver, double& due, double& owed)
{
    double giveAmount;
    string giverName = giver->getFriend().getName();
    string receiverName = receiver->getFriend().getName();

    giveAmount = due;                           // giver pays all that they were due to pay
    giver->getFriend().setAmountDue(0);         // update the giver's amountDue
    due = 0;                                    // update the due value
    receiver->getFriend().setAmountOwed(0);     // update the receiver's amountOwed
    owed = 0;                                   // update the owed value

    cout << giverName << " should give $" << giveAmount << " to " << receiverName << endl;
}