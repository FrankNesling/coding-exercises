#include <iostream>
#include <regex>
#include <string>

class ComplexNumber {
public:
    static char i;
    int real, imaginary;
    smatch match;

    ComplexNumber(int re, int im) {
        real = re;
        imaginary = im;
    }

    ComplexNumber(string complexNumber) {
        if (!isComplexNumber(complexNumber)) {
            throw invalid_argument("Invalid complex number!");
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
            string imagStr = match[2].str();

            // trailing i
            imagStr.pop_back();

            // +i, -i => +1, -1
            if (imagStr == "+" || imagStr == "-") {
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

    string toString() {
        char sign = "";
        string imaginePart = "";

        if (imaginary != 0) {
            if (imaginary == 1) {
                imaginePart = i;
            }
            else if (imagine == -1) {
                imaginePart = '-' + i;
            }
            else {
                imaginePart = to_string(imaginary) + i;
            }

            if (imaginary > 0 || real != 0) {
                sign = "+";
            }
        }
        return to_string(real) + sign + imaginePart;
    }

    static bool isComplexNumber(string complexNumber) {        
        if (complexNumber.empty()) {
            return false;
        }

        regex pattern("^([+-]?[0-9]+)?([+-][0-9]*i)?$")
        return regex_match(complexNumber, match, pattern);
    }
};

char ComplexNumber::i = 'i';


int main() {
    string a;
    string b;

    ComplexNumber complex1;
    ComplexNumber complex2;


    while (true) {
        std::cout << "Your first complex number?: ";
        std::cin >> a;

        try {
            complex1(a);
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
            break;
        }

        std::cout << "Your second complex number?: ";
        std::cin >> b;

        try {
            complex2(b);
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
            break;
        }

        std::cout << "The sum is: " << ComplexNumber::addition(complex1, complex2);
    }

    return 0;
}