#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

double calculateTotalInterestNaive(double balance, float rate, int time) {
    float percentageRate = rate / 100;
    double totalInterest = 0.0;

    while (time > 0) {
        double interest = balance * percentageRate;
        balance = balance + interest;
        totalInterest = totalInterest + interest;
        --time;
    }

    return totalInterest;
}

double calculateTotalInterestPower(double balance, float rate, int time) {
    double totalAmount = balance * pow((1 + rate / 100), time);
    return totalAmount - balance;
}


int main() {
    double balance;
    float rate;
    int time;

    // display 2 digits in cout for double
    cout << std::fixed;
    cout << std::setprecision(2);


    while (true) {
        cout << "Enter your (current) balance: ";
        cin >> balance;

        cout << "Enter your interest rate (in percentage %): ";
        cin >> rate;

        cout << "Enter your desired time of waiting (in years): ";

        bool validYear = false;
        do {
            cin >> time;
            if (cin.good()) {
                validYear = true;
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid number (only integers): ";
            }
        } while (!validYear);

        cout << "After " << (time == 1 ? " year" : " years") << ", you collected in total " << calculateTotalInterestNaive(balance, rate, time) << " in interest (calculated naively)!\n";
        cout << "After " << (time == 1 ? " year" : " years") << ", you collected in total " << calculateTotalInterestPower(balance, rate, time) << " in interest (calculated with power)!\n";
    }
  
    

    return 0;
}
