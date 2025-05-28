#include <iostream>

void rotateArray(int* rotatingList, int listLength, int rotateK) {

    int tmpList[listLength];
    rotateK = rotateK % listLength;

    for (int i = 0; i < listLength; i++) {
        tmpList[i] = rotatingList[(listLength + i - rotateK) % listLength];
    }

    for (int i = 0; i < listLength; i++) {
        rotatingList[i] = tmpList[i];
    }

}



int main() {
    int listLength;
    int rotateK;

    std::cout << "How many elements in your list?: ";
    std::cin >> listLength;

    int rotatingList[listLength];

    for (int i = 0; i < listLength; i++) {
        int element;

        std::cout << "What is element " << (i + 1) << "?: ";
        std::cin >> element;

        rotatingList[i] = element;
    }

    std::cout << "How much shifting?: ";
    std::cin >> rotateK;

    rotateArray(rotatingList, listLength, rotateK);

    for (int i = 0; i < listLength; i++) {
        std::cout << rotatingList[i] << (i < listLength - 1 ? "," : "");
    }

    return 0;
}