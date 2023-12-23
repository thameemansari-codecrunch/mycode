#include <iostream>

int main() {
    int i = 2, count = 0, n;

    std::cout << "Checking prime or not\n";
    std::cout << "Enter a number: ";
    std::cin >> n;

    while (i <= n / 2) {
        if (n % i == 0) {
            count++;
            break;
        }
        i++;
    }

    if (count == 0 && n != 1) {
        std::cout << "Entered number " << n << " is prime." << std::endl;
    } else {
        std::cout << "Entered number " << n << " is not prime." << std::endl;
    }

    return 0;
}
