#include <iostream>

long long int getNthFibonacci(int n) {
    long long int a = 0;
    long long int b = 1;
    long long int tmp;

    std::cout << a;

    while (n > 1) {
        tmp = a + b;
        a = b;
        b = tmp;
        std::cout << "," << a;
        --n;
    }

    return a;
}

int recursiveFibonnaci(int n) {
    if (n == 1) {
        return 0;
    }
    else if (n == 2) {
        return 1;
    }
    else {
        int result = recursiveFibonnaci(n - 1) + recursiveFibonnaci(n - 2);
        return result;
    }
}



int main() {
    int fibonacci;


    while (true) {
        std::cout << "Which nth fibonacci number to you seek?: ";
        std::cin >> fibonacci;

        while (fibonacci < 1) {
            std::cout << "Please at least 1: ";
            std::cin >> fibonacci;
        }

        std::cout << " --- " << getNthFibonacci(fibonacci) << "\nRecursive: \n";
        std::cout << recursiveFibonnaci(fibonacci) << "\n";
    }

    return 0;
}