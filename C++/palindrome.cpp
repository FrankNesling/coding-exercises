#include <iostream>
using namespace std;

bool checkPalindrome(std::string input) {
    size_t index = 0;
    int inputLength = input.length();

    while (index < inputLength / 2) {

        if (input[inputLength - 1 - index] != input[index]) {
            return false;
        }

        ++index;
    }

    return true;
}



int main() {
    std::string input;


    while (true) {
        std::cout << "Enter your word here: Is it a palindrome?";
        std::cin >> input;

        std::cout << "The word " << input << " is" << (checkPalindrome(input) ? "" : " NOT") << " a palindrome!\n";
    }
   
    return 0;
}

