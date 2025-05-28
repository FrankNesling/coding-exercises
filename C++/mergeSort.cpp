#include <iostream>


void swapNumbers(int* unsortedList, int indexA, int indexB) {
    int tmp = unsortedList[indexB];
    unsortedList[indexB] = unsortedList[indexA];
    unsortedList[indexA] = tmp;
}

void merge(int* unsortedList, int start, int end) {
    int length = end - start + 1;
    int tmpList[length];
    int diff = length / 2 + (length % 2 == 0 || length == 1 ? 0 : 1);
    int leftPointer = start;
    int rightPointer = start + diff;

    for (int i = 0; i < length; i++) {
        if (leftPointer - diff >= start) {
            tmpList[i] = unsortedList[rightPointer];
            rightPointer++;
        }
        else if (rightPointer > end) {
            tmpList[i] = unsortedList[leftPointer];
            leftPointer++;
        }
        else {
            if (unsortedList[leftPointer] < unsortedList[rightPointer]) {
                tmpList[i] = unsortedList[leftPointer];
                leftPointer++;
            }
            else {
                tmpList[i] = unsortedList[rightPointer];
                rightPointer++;
            }
        }
    }

    for (int i = 0; i < length; i++) {
        unsortedList[start + i] = tmpList[i];
    }
}



void divide(int* unsortedList, int start, int end) {

    if (end - start > 1) {
        divide(unsortedList, start, (end - start) / 2 + start);
        divide(unsortedList, (end - start) / 2 + 1 + start, end);
    }

    merge(unsortedList, start, end);
}


void mergeSort(int* unsortedList, int listLength) {
    divide(unsortedList, 0, listLength - 1);
}




int main() {
    int listLength ;

    std::cout << "How many elements in your unsorted list?";
    std::cin >> listLength;

    int unsortedList[listLength];

    for (int i = 0; i < listLength; i++) {
        int element;

        std::cout << "What is element " << (i + 1) << "?: ";
        std::cin >> element;

        unsortedList[i] = element;
    }
    

    mergeSort(unsortedList, listLength);

    for (int i = 0; i < listLength; i++) {
        std::cout << unsortedList[i] << (i < listLength - 1 ? "," : "");
    }

    return 0;
}