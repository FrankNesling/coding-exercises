#include <iostream>
using namespace std;

int main() {

    int a;
    int b;
    cout << "Enter number:";
    cin >> a;
    int* ptrA = &a;
    b = a;
    int* ptrB = &b;


    cout << "The pointer values is " << *ptrA << " the memory address ptrA is: " << ptrA << " and for ptrB: " << ptrB << "\n";

    char gstr[] = "The good string!";
    char* ptrStr = gstr;

    cout << gstr[0] << ' ' << *ptrStr << ' ' << ptrStr[4] << "\n";
    ptrStr += 2;
    cout << gstr[0] << ' ' << *ptrStr << ' ' << ptrStr[5] << ' ' << ptrStr[-1] << ' ' << ptrStr[244] << "\n";

    return 0;
}