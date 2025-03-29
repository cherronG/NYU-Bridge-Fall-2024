// Randomly chooses an integer between 1 and 100 (inclusive)
// Has the user try to guess the number

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int guess, guesses = 0;
    int counter, big_guess = 101, small_guess = 0;

    srand(time(0));
    int random = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to gues it." << endl;
    
    for (counter = 5; counter > 0; counter--)
    {
        cout << "Range: [" << small_guess + 1 << ", " << big_guess - 1 << "], ";
        cout << "Number of guesses left: " << counter << endl;
        cout << "Your guess: ";
        cin >> guess;
        guesses++;

        if (guess < random)
        {
            if (guess > small_guess)
                small_guess = guess;
            cout << "Wrong! My number is bigger." << endl;
            cout << endl;
        }
        else if (guess > random)
        {
            if (guess < big_guess)
                big_guess = guess;
            cout << "Wrong! My number is smaller." << endl;
            cout << endl;
        }
        else if (guess == random)
        {
            cout << "Congrats! You guessed my number in " << guesses << " guesses." << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout << "Out of guesses! My number is " << random << endl;
    }

    return 0;
}