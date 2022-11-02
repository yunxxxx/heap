/* CSE310
 * Homework3
 * Yuan Bo  1220397048
 *
 * heap.h is a header file for the head.cpp
 *
 * more information will be write in the top of head.cpp
 */


#ifndef HEAP_H
#define HEAP_H

using namespace std;

class element;

class heap {
private:
    int capacity;
    int size;
    element **H;

public:
    heap();

    heap(int capacity);

    void insertElement(element *elementInsert);

    element *getElement(int index);

    element *getLeft(int index);

    element *getRight(int index);

    bool heapCompare(int largestElement, int child);

    void switchElement(int parent, int child);

    int deleteFirst();

    void goToMax(int n);

    int getSize();

    int getCapacity();

    int getHeapSize();

    void printKey(int index);

    bool fullChecker();

    void clean();
};

class element {
private:
    int key;

public:
    element();

    element(int key);

    void increase(int key);

    int getKey();

    bool operator==(const element &other);

};

#endif