#include <iostream>

int main() {
    int i = 2, count = 0, n;

    // User prompt
    std::cout << "Checking prime or not" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> n;

    while (i <= n / 2) {
        if (n % i == 0) {
            count++;
            break;  // Exit the loop if n is divisible by i
        }
        i++;
    }

    if (count == 0 && n > 1) {
        std::cout << "Entered number " << n << " is prime." << std::endl;
    } else {
        std::cout << "Entered number " << n << " is not prime." << std::endl;
    }

    return 0;
}

Initialization: The loop counter i is initialized to 2, as 0 and 1 are not prime numbers.

     User Input: The program prompts the user to enter a number using std::cout and reads the input into the variable n using std::cin.

   Loop for Prime Checking:

        The while loop runs until i is less than or equal to half of the entered number (n / 2).
   The loop checks if the entered number (n) is divisible evenly by the current value of i. If it is, the count is incremented, and the loop breaks.
Prime Check Result:

             After the loop, the program checks if count is 0 and n is greater than 1. If true, it indicates that the entered number is only divisible by 1 and itself, making it a prime number.
     If the conditions are met, it prints that the entered number is prime. Otherwise, it prints that the entered number is not prime.
   Output: The results are displayed using std::cout.

       Return 0: The program returns 0 to indicate successful execution.
  
    Note: The original program had syntax errors and logical issues. I corrected them to create a functional program that checks whether a given number is prime or not.




