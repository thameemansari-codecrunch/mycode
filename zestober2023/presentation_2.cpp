#include <iostream>
#include <unordered_map>

std::unordered_map<int, long long> memo;  // Memoization table

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    // Check if the value is already memoized
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    // Recursive calculation with memoization
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n for Fibonacci sequence: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Please enter a non-negative integer." << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}
MY VIEW OF THIS PROGRAMME
This program efficiently calculates Fibonacci numbers using a memoization technique, reducing redundant calculations and improving performance.
   Memoization helps store and reuse previously computed Fibonacci values, especially for large n.
      The code showcases a cool logic technique—memoization—to enhance the efficiency of recursive calculations.
