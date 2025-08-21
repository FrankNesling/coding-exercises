#include <iostream>
#include <map>
using namespace std;

// can be sped up with an initialized array instead of a map
map<char, int> singleRomanValue = {
    { 'I', 1 },
    { 'V', 5 },
    { 'X', 10 },
    { 'L', 50 },
    { 'C', 100 },
    { 'D', 500 },
    { 'M', 1000 }
};

// assumes that the roman Numeral is correctly given, there is no error handling
int romanToInt(string romanNumeral) {
    int totalSum = 0;
    int length = romanNumeral.length();

    int letter;
    int nextLetter;

    for (int i = 0; i < length; ++i) {
        letter = singleRomanValue.find(romanNumeral[i])->second;
        nextLetter = i < length - 1 ? singleRomanValue.find(romanNumeral[i + 1])->second : 0;

        if (letter < nextLetter) {
            totalSum += (nextLetter - letter);
            ++i;
        }
        else {
            totalSum += letter;
        }
    }


    return totalSum;
}



int main() {
    string romanNumeral;


    while (true) {
        cout << "Enter your roman numeral here: ";
        cin >> romanNumeral;

        cout << "The roman numeral " << romanNumeral << " is " << romanToInt(romanNumeral) << "!\n";
    }

    return 0;
}