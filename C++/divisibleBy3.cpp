#include <iostream>

bool divisibleBy3(int numberBy3) {
    int digitsum = 0;
    int digitPosition10 = 10;

    while (digitPosition10 <= numberBy3) {
        digitPosition10 = digitPosition10 * 10;
    }
    
    digitPosition10 = digitPosition10 / 10;

    while (numberBy3 > 0) {
        int difference = numberBy3 - digitPosition10;
        if (difference >= 0) {
            numberBy3 = difference;
            ++digitsum;
        } else {
            digitPosition10 = digitPosition10 / 10;
        }
    }

    if (digitsum < 10) {
        if (digitsum == 0 || digitsum == 3 || digitsum == 6 || digitsum == 9) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return divisibleBy3(digitsum);
    }
}


int main() {
    int numberBy3;
    bool isDivisibleBy3;

    while (true) {
        std::cout << "Which number do you want to check if divisible by 3 (by digitsum rule): ";
        std::cin >> numberBy3;

        while (numberBy3 < 0) {
            std::cout << "Let's stay positive please!";
            std::cin >> numberBy3;
        }

        isDivisibleBy3 = divisibleBy3(numberBy3);
        std::cout << "It is divisble by 3: " << (isDivisibleBy3 ? "true" : "false") << "\n";
    }

    return 0;
}