#include <iostream>
#include <regex>
#include <string>
#include <stdexcept>

class ComplexNumber {
public:
    static char i;
    int real, imaginary;
    std::smatch match;

    ComplexNumber() {
        real = 0;
        imaginary = 0;
    }

    ComplexNumber(int re, int im) {
        real = re;
        imaginary = im;
    }

    ComplexNumber(std::string complexNumber) {
        if (!isComplexNumber(complexNumber)) {
            throw std::invalid_argument("Invalid complex number!");
        }

        // real
        if (match[1].matched) {
            real = atof(match[1].str().c_str());
        }
        else {
            real = 0;
        }

        // imaginary
        if (match[2].matched) {
            std::string imagStr = match[2].str();

            // trailing i
            imagStr.pop_back();

            // +i, -i => +1, -1
            if (imagStr == "+" || imagStr.empty() || imagStr == "-") {
                imagStr += "1";
            }

            imaginary = atof(imagStr.c_str());
        }
        else {
            imaginary = 0;
        }
    }

    static ComplexNumber addition(ComplexNumber a, ComplexNumber b) {
        return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
    }

    std::string toString() {
        char sign = '\0';
        std::string imaginePart = "\0";
        std::string realPart = "\0";

        if (real == 0 && imaginary == 0) {
            return std::string("0");
        }
        else if (imaginary == 0) {
            return std::to_string(real);
        }
        else if (real == 0) {
            if (imaginary == 1) {
                return std::string(1, i);
            }
            else if (imaginary == -1) {
                return std::string("-") + i;
            }
            else {
                return std::to_string(imaginary) + i;
            }
        }
        else {
            realPart = std::to_string(real);

            if (imaginary == 1) {
                sign = '+';
                imaginePart = i;
            }
            else if (imaginary == -1) {
                sign = '-';
                imaginePart = i;
            }
            else {
                if (imaginary > 0) {
                    sign = '+';
                    imaginePart = std::to_string(imaginary) + i;
                }
                else if (imaginary < 0) {
                    sign = '-';
                    imaginePart = std::to_string(imaginary * -1) + i;
                }
            }

            std::cout << "[" << realPart << "][" << sign << "][" << imaginePart << "]\n";

            return realPart + sign + imaginePart;
        }
    }

    bool isComplexNumber(std::string complexNumber) {
        if (complexNumber.empty()) {
            return false;
        }

        std::regex pattern("^([+-]?[0-9]+(?![0-9]*i))?([+-]?[0-9]*i)?$");
        return std::regex_match(complexNumber, match, pattern);
    }
};

char ComplexNumber::i = 'i';


int main() {
    std::string a;
    std::string b;

    ComplexNumber complex1;
    ComplexNumber complex2;

    while (true) {
        std::cout << "Your first complex number?: ";
        std::cin >> a;

        try {
            complex1 = ComplexNumber(a);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
            break;
        }

        std::cout << "Your second complex number?: ";
        std::cin >> b;

        try {
            complex2 = ComplexNumber(b);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
            break;
        }

        std::cout << "The sum is: " << ComplexNumber::addition(complex1, complex2).toString() << "\n";
    }

    return 0;
}