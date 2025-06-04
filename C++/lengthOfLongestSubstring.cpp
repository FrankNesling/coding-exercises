#include <iostream>
#include <map>
using namespace std;

int lengthOfLongestSubstring(std::string input) {
    int length = input.length();
    int longestSubstring = 0;

    std::map<char, int> repeatedCharacters;


    int startIndex = 0;
    int lastIndex = 0;

    for (int i = 0; i < length; i++) {
        auto charIndex = repeatedCharacters.find(input[i]);
        if (charIndex != repeatedCharacters.end()) {    // character found in sliding window
            if (input[i] == input[startIndex]) {
                startIndex++;
                lastIndex = i;
            }
            else {
                if (charIndex->second >= startIndex) {
                    startIndex = (charIndex->second) + 1;
                }
                lastIndex = i;

                if (lastIndex - startIndex + 1 > longestSubstring) {
                    longestSubstring = lastIndex - startIndex + 1;
                }
            }
            repeatedCharacters[input[i]] = i;
        }
        else {  // not found in sliding window
            repeatedCharacters.insert({ input[i], i });
            lastIndex = i;
            if (lastIndex - startIndex + 1 > longestSubstring) {
                longestSubstring = lastIndex - startIndex + 1;
            }
        }
    }

    return longestSubstring;
}



int main() {
    std::string input;


    while (true) {
        std::cout << "Enter your string here. What is the longest substring? ";
        std::getline(std::cin, input);

        std::cout << "The longest substring is " << lengthOfLongestSubstring(input) << "\n";
    }

    return 0;
}