#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "Try to guess the number between 1 and 100." << endl;

    do {
        // Prompt user for a guess
        cout << "Enter your guess: ";
        cin >> guess;

        attempts++;

        // Provide feedback on the guess
        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
MY UNDERSTANDING POINT VIEW:
              The srand (time(0)) line seeds the random number generator using the current time. This ensures that the random number is different each time the program runs.

               rand() % 100 + 1 generates a random number between 1 and 100.

Game Logic:

             The program then enters a loop (do-while) where the user is prompted to guess the number.

      After each guess, the program provides feedback on whether the guess is too high, too low, or correct.

The loop continues until the user guesses the correct number.

User Input:

cout is used to display messages to the user, and cin is used to get input from the user.
Congratulations Message:

When the user guesses the correct number, a congratulations message is displayed along with the number of attempts it took to guess correctly.
Return Statement:

return 0; indicates that the program has been executed successfully.
This program is a simple introduction to user input, conditional statements, loops, and random number generation in C++.
