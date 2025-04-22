// Implements a class that uses a vector to store a queue

#include <iostream>
#include <vector>
using namespace std;

// Class Definitions
template <class T>
class Queue
{
    private:
        vector<T> queue;    // vector to store queue elements
        int frontIndex;     // index containing the first element in the queue
        int queueSize;      // amount of elements in the queue

    public:
        Queue() : queue({}), frontIndex(0), queueSize(0) {}
        // Constructor for the Queue class that creates an empty queue of a vector of size 0, with frontIndex initialized to 0

        ~Queue() { clear(); }
        // Destructor to properly cleanup an object of the Queue class

        void enqueue(T newItem);
        // Pushes a new element to the start of the queue

        T dequeue();
        // Removes the element at the front of the queue

        T front() const;
        // Returns the first element of the queue

        bool isEmpty() const { return (queueSize == 0); }
        // Returns true if the queue is empty; otherwise, returns false

        int size() const { return queueSize; }
        // Returns the amount of elements in the queue

        void clear() { queue.clear(); }
        // Properly clears out the queue/vector

        void print();
        // Prints the elements contained in the queue
};


// Main
int main()
{
    Queue<int> test;
    for (int i = 0; i < 11; i++)
    {
        test.enqueue(i);
    }
    cout << "Queue of size: " << test.size() << endl;
    test.print();

    cout << "Remove the first element in the queue: " << test.front() << endl;
    int removed = test.dequeue();
    cout << removed << " was dequeued" << endl;
    test.print();

    return 0;
}


// Queue Class Member Function Definitions
template <class T>
void Queue<T>::enqueue(T newItem)
{
    queue.push_back(newItem);
    queueSize++;
}

template <class T>
T Queue<T>::dequeue()
{
    if (!isEmpty())
    {
        T temp = queue.at(frontIndex);
        frontIndex++;
        queueSize--;
        return temp;
    }
    else
        cout << "Cannot dequeue an empty queue" << endl;
    return 0;
}

template <class T>
T Queue<T>::front() const
{
    if (!isEmpty())
        return queue.at(frontIndex);
    else
    {
        cout << "Queue is empty" << endl;
        return T();
    }
}

template <class T>
void Queue<T>::print()
{
    for (int i = frontIndex; i < queueSize; i++)
        cout << queue.at(i) << " ";
    cout << endl;
}