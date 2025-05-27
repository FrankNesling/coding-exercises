#include <iostream>


void swapNumbers(int* unsortedList, int indexA, int indexB) {
    int tmp = unsortedList[indexB];
    unsortedList[indexB] = unsortedList[indexA];
    unsortedList[indexA] = tmp;
}


void bubbleSort(int* unsortedList, int listLength) {

    for (int i = 0; i < listLength - 1; i++) {
        for (int j = 0; j < listLength - 1 - i; j++) {
            if (unsortedList[j] > unsortedList[j + 1]) {
                swapNumbers(unsortedList, j, j + 1);
            }
        }
    }

}




int main() {
    int listLength;

    std::cout << "How many elements in your unsorted list?";
    std::cin >> listLength;

    int unsortedList[listLength];

    for (int i = 0; i < listLength; i++) {
        int element;

        std::cout << "What is element " << (i+1) << "?: ";
        std::cin >> element;

        unsortedList[i] = element;
    }
    
    bubbleSort(unsortedList, listLength);
    
    for (int i = 0; i < listLength; i++) {
        std::cout << unsortedList[i] << (i < listLength - 1 ? "," : "");
    }

    return 0;
}