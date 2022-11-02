
/* CSE310
 * Homework3
 * Yuan Bo  1220397048
 *
 * This is the 3rd assignment of CSE310
 * This is a function about heap
 * Use guide will be find in the file "README.txt"
 * The input file will be name as "HEAPinput.txt:"
 *
 * This function will be provide the data structures "Heap"
 * The function are able to:
 * Build a empty heap by give the capacity number
 * Build heap from a input file
 * insert any element by enter element
 * delement max element of the heap
 * print the heap out
 * 
 * The make file will creat "run" and to run the fucntion
 * enter the command "./run"
 */

#include "util.h"
#include "heap.h"
#include <iostream>
#include <fstream>

using namespace std;

//All of the function that will be use for build heap
heap *initialize(int capacity);

void buildHeap(heap *myHeap, element **A, int elementSize);

void insert(heap *myHeap, int flag, element *key);

void deleteMax(heap *myHeap, int flag);

void increaseKey(heap *myHeap, int flag, int index, int value);

void printHeap(heap *myHeap);

void maxHeapify(heap *myHeap, int index);

//main function start at this line---------------------------------------------------------------------------------------
int main(int argc, char **argv) {
    //the function will have a char "c" for looking for user's command
    char c;
    //the function will have 5 different int for different int command
    int i, v, f, n, k;
    //the function will have a bool called loop to enter and exit loop
    bool loop = true;
    //also it will have two different int for saving arraySize and arrayelement when it read the input file
    int arraySize, arrayElement;
    //there will a a list of element for same the input file and element for save element
    element **elementArray, *insertElement;
    //the heap
    heap *myHeap;

    //Print program start before enter the loop
    std::cout << "Program Start!" << std::endl;
    while (loop) {
        //call the nextCommand function get user's command
        c = nextCommand(i, v, f, n, k);
        switch (c) {
            //when case s, enter the program stop case
            case 's': {
                case 'S':
                    std::cout << "Command: S" << std::endl;
                std::cout << "Program Stop" << std::endl;
                loop = false;
                break;
            }

                //when case c, enter creat empty heap case
            case 'c': {
                case 'C':
                    std::cout << "Command: C " << n << std::endl;
                if (n >= 0) {
                    myHeap = initialize(n);
                } else {
                    std::cout << "Error: invalid heap capacity" << std::endl;
                }
                break;
            }

                //when case r, enter read file and build a heap case
            case 'r': {
                case 'R':
                    std::cout << "Command: R" << std::endl;
                std::ifstream heapInput("HEAPinput.txt");
                if (heapInput.is_open()) {
                    heapInput >> arraySize;
                    elementArray = new element *[arraySize];

                    for (int i = 0; i < arraySize; i++) {
                        heapInput >> arrayElement;
                        elementArray[i] = new element(arrayElement);
                    }
                } else {
                    std::cout << "Error: There are no heap input file" << std::endl;
                }
                buildHeap(myHeap, elementArray, arraySize);
                break;
            }

                //when case w, enter print out heap case
            case 'w': {
                case 'W':
                    std::cout << "Command: W" << std::endl;
                printHeap(myHeap);
                break;
            }

                //when case i, enter insert elemetn case
            case 'i': {
                case 'I':
                    std::cout << "Command: I " << f << " " << k << std::endl;
                insertElement = new element(k);
                insert(myHeap, f, insertElement);
                break;
            }

                //when case d, enter delete max element case
            case 'd': {
                case 'D':
                    std::cout << "Command: D " << f << std::endl;
                deleteMax(myHeap, f);
                break;
            }

                //when case k, enter increase key case 
            case 'k': {
                case 'K':
                    std::cout << "Command: K " << f << " " << i << " " << v << std::endl;
                increaseKey(myHeap, f, i, v);
                break;
            }

            default:
                break;
        }
    }
}


//this function will creat an empty heap with a number with the capacity
heap *initialize(int capacity) {
    heap *myHeap = new heap(capacity);
    return myHeap;
};

//this function will have a list of element and build a heap by the list.
//it will print a error message if there are no empty heap yet or the heap size is not enough
void buildHeap(heap *myHeap, element **A, int elementSize) {
    if (myHeap == NULL) {
        cout << "Error: heap not initialized" << endl;
        return;
    }
    if (elementSize > myHeap->getCapacity()) {
        cout << "Error: array size exceeds heap capacity" << endl;
        return;
    }
    myHeap->clean();
    for (int i = 0; i < elementSize; i++) {
        myHeap->insertElement(A[i]);
        myHeap->goToMax(myHeap->getSize());
    }
}

//this function will insert a element to current heap
//an error message will be print out and return if the heap has not creat yet
void insert(heap *myHeap, int flag, element *key) {
    if (myHeap == NULL) {
        cout << "Error: heap not initialized" << endl;
        return;
    }
    if (flag == 1) {
        myHeap->insertElement(key);

        myHeap->goToMax(myHeap->getSize());
    } else if (flag == 2) {
        cout << "Before insert operation:" << endl;
        printHeap(myHeap);

        myHeap->insertElement(key);

        myHeap->goToMax(myHeap->getSize());

        cout << "After insert operation:" << endl;
        printHeap(myHeap);
    } else {
        cout << "invalid flag value" << endl;
    }
}

//this function will delete the max element in the current heap
//an error message will be print out and return if the heap has not creat yet or the heap is empty
void deleteMax(heap *myHeap, int flag) {
    if (myHeap == NULL) {
        cout << "Error: heap not initialized" << endl;
        return;
    }
    if (myHeap->getSize() == 0) {
        cout << "Error: heap empty" << endl;
        return;
    }
    if (flag == 1) {
        int maxValue = myHeap->deleteFirst();

        maxHeapify(myHeap, 0);

        cout << "Deleted max = " << maxValue << endl;

    } else if (flag == 2) {
        cout << "Before delete max operation:" << endl;
        printHeap(myHeap);

        int maxValue = myHeap->deleteFirst();

        maxHeapify(myHeap, 0);

        cout << "After delete max operation:" << endl;
        printHeap(myHeap);
        cout << "Deleted max = " << maxValue << endl;

    } else {
        cout << "invalid flag value" << endl;
    }
}

//this function will find a key from heap by unsing index and increase current to the key user entered
//an error message will be print out and return if the heap has not creat yet or the heap is empty or the index is out of range
void increaseKey(heap *myHeap, int flag, int index, int value) {
    if (myHeap == NULL) {
        cout << "Error: heap not initialized" << endl;
        return;
    }

    if (myHeap->getSize() == 0) {
        cout << "The heap is empty!" << endl;
        return;
    }

    if (index > myHeap->getSize() || index <= 0) {
        cout << "Error: invalid index" << endl;
        return;
    }

    if (flag == 1) {
        myHeap->getElement(index)->increase(value);
        myHeap->goToMax(index);
    } else if (flag == 2) {
        cout << "Before increase key operation:" << endl;
        printHeap(myHeap);

        myHeap->getElement(index)->increase(value);

        myHeap->goToMax(index);

        cout << "After increase key operation:" << endl;
        printHeap(myHeap);
    } else {
        cout << "invalid flag value" << endl;
    }
}

//this function will print out the current heap
//an error message will be print out and return if the heap has not creat yet
void printHeap(heap *myHeap) {
    if (myHeap == NULL) {
        cout << "Error: heap not initialized" << endl;
        return;
    }

    cout << "capaity: " << myHeap->getCapacity() << endl;
    cout << "size: " << myHeap->getSize() << endl;
    for (int i = 0; i < myHeap->getSize(); i++) {
        myHeap->printKey(i);
    }

}

//this is the maxHeapify function that will be use in some of the fucntion of the heap.
//It will not be used in main function.
void maxHeapify(heap *myHeap, int index) {
    int heapSize = myHeap->getSize();
    int leftIndex = ((index + 1) * 2) - 1;
    int rightIndex = (index + 1) * 2;
    int largestElement = index;

    if (leftIndex <= heapSize && myHeap->heapCompare(largestElement, leftIndex)) {
        largestElement = leftIndex;
    }
    if (rightIndex <= heapSize && myHeap->heapCompare(largestElement, rightIndex)) {
        largestElement = rightIndex;
    }
    if (largestElement != index) {
        myHeap->switchElement(index, largestElement);
        maxHeapify(myHeap, largestElement);
    }
}
