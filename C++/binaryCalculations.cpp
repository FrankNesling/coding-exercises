#include <iostream>
#include <cmath>

std::string addTwoBinaries(std::string binaryA, std::string binaryB) {
    std::string binarySum;
    int maxLength = std::max(binaryA.length(), binaryB.length());
    int lengthA = binaryA.length();
    int lengthB = binaryB.length();

    bool overFlow = false;

    for (int i = 0; i < maxLength; i++) {
        if (i+1 > lengthA) {
            if (binaryB[lengthB - 1 - i] == '1' && overFlow) {
                binarySum.append("0");
            }
            else {
                if (overFlow) {
                    binarySum.append("1");
                }
                else {
                    binarySum.append(1, binaryB[lengthB - 1 - i]);
                }
                overFlow = false;
            }
        }
        else if (i+1 > lengthB) {
            if (binaryA[lengthA - 1 - i] == '1' && overFlow) {
                binarySum.append("0");
            }
            else {
                if (overFlow) {
                    binarySum.append("1");
                }
                else {
                    binarySum.append(1, binaryA[lengthA - 1 - i]);
                }
                overFlow = false;
            }
        }
        else {
            if (binaryA[lengthA - 1 - i] == '1' && binaryB[lengthB - 1 - i] == '1') {
                if (overFlow) {
                    binarySum.append("1");
                }
                else {
                    binarySum.append("0");
                }
                overFlow = true;
            }
            else if (binaryA[lengthA - 1 - i] == '0' && binaryB[lengthB - 1 - i] == '0') {
                if (overFlow) {
                    binarySum.append("1");
                    overFlow = false;
                }
                else {
                    binarySum.append("0");
                }
            }
            else {
                if (overFlow) {
                    binarySum.append("0");
                }
                else {
                    binarySum.append("1");
                }
            }
        }       
    }

    if (overFlow) {
        binarySum.append("1");
    }

    std::string result;
    int binarySumLength = binarySum.length();
    for (int i = 0; i < binarySumLength; i++) {
        result.append(1, binarySum[binarySumLength - 1 - i]);
    }
        
    return result;
}


int convertBinaryToDecimal(std::string binaryNumber) {
    int n = binaryNumber.length();
    int decimalNumber = 0;

    for (int i = 0; i < n; i++) {
        if (binaryNumber[n - 1 - i] == '1') {
            decimalNumber += pow(2, i);
        }
        else if (binaryNumber[n - 1 - i] != '0') {
            std::cout << "Not a binary number, aborting ... \n";
            return -1;
        }
    }

    return decimalNumber;
}



std::string convertDecimalToBinary(int decimalNumber) {
    int n = 0;
    std::string binaryNumber;
    
    while (pow(2, n) < decimalNumber) {
        ++n;
    }

    if (decimalNumber - pow(2, n) != 0 && n > 0) {
        --n;
    }

    while (n >= 0) {
        if (decimalNumber - pow(2, n) >= 0) {
            binaryNumber.append("1");
            decimalNumber = decimalNumber - pow(2, n);
        }
        else {
            binaryNumber.append("0");
        }
        --n;
    }

    return binaryNumber;
}




int main() {
    int conversionOption;
    std::string binaryNumber;
    int decimalNumber;


    while (true) {
        std::cout << "Do you want to convert binary to decimal (0) or decimal to binary (1) or do you want to add two binaries (2)?: ";
        std::cin >> conversionOption;

        if (conversionOption == 0) {
            std::cout << "Which binary number to you want to convert to decimal?: ";
            std::cin >> binaryNumber;
            decimalNumber = convertBinaryToDecimal(binaryNumber);
            std::cout << binaryNumber << " in decimal is: " << decimalNumber << "\n";
        }
        else if (conversionOption == 1) {
            std::cout << "Which decimal number to you want to convert to binary?: ";
            std::cin >> decimalNumber;
            binaryNumber = convertDecimalToBinary(decimalNumber);
            std::cout << decimalNumber << " in binary is: " << binaryNumber << "\n";
        }
        else if (conversionOption == 2) {
            std::string binaryA;
            std::string binaryB;

            std::cout << "What is the first binary number?: ";
            std::cin >> binaryA;
            std::cout << "What is the second binary number?: ";
            std::cin >> binaryB;
            binaryNumber = addTwoBinaries(binaryA, binaryB);
            std::cout << "The sum is: " << binaryNumber << "\n";
        }
        else {
            std::cout << "Only 0,1 or 2 is allowed as option!\n";
        }
    }

    return 0;
}