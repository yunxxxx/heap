/* 
 *
 * heap.cpp is a class that creat heap and element
 *
 * heap will a int for the capacity number, int for the size and a list of element
 *
 * element class will be a element to save int.
 *
 * There are some unused function in the heap class
 * however they are still in the class because it may be use in some of the function in the future for different heap usage
 */

#include "heap.h"
#include <iostream>
#include <fstream>

using namespace std;


//heap class
heap::heap() {
    this->capacity = 0;
    this->size = 0;
    this->H = new element *[0];
};

//build empty heap with a capacity number
heap::heap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->H = new element *[capacity];
};

//insert element
void heap::insertElement(element *elementInsert) {
    if (capacity == this->size) {
        element **newHeap = new element *[capacity + 1];
        for (int i = 0; i < this->size; i++) {
            newHeap[i] = H[i];
        }

        this->H = newHeap;
        this->capacity = this->capacity + 1;
    }
    H[size] = elementInsert;
    this->size = this->size + 1;
};

//return the element in heap by get the index
element *heap::getElement(int index) {
    return this->H[index - 1];
};

//get the left child for the index element
element *heap::getLeft(int index) {
    index = index * 2;
    return this->H[index];
};

//get the right child for the index element
element *heap::getRight(int index) {
    index = (index * 2) + 1;
    return this->H[index];
};

//return a bool result for compare two element of the heap
bool heap::heapCompare(int parent, int child) {
    return (H[parent]->getKey() < H[child]->getKey());
}

//switch the element by have two index of different element
void heap::switchElement(int parent, int child) {
    element *save = H[parent];
    H[parent] = H[child];
    H[child] = save;
}

//delete first element of the heap
int heap::deleteFirst() {
    int maxValue = H[0]->getKey();
    H[0] = H[size - 1];
    size--;
    return maxValue;
}

//by have a index n keep let n compare with the parent until it is less than parent or hit the roop
void heap::goToMax(int n) {
    int current = n - 1;
    int parent = (current - 1) / 2;
    while (current != 0 && H[parent]->getKey() < H[current]->getKey()) {
        switchElement(parent, current);
        current = parent;
        parent = (current - 1) / 2;
    }
}

//return the size of the heap
int heap::getSize() {
    return this->size;
};

//return the capacity of the heap
int heap::getCapacity() {
    return this->capacity;
};

//return the heapSize
int heap::getHeapSize() {
    int heapSize = this->size;
    heapSize = (heapSize - 1) / 2;
    return heapSize;
}

//print the key by have the index of the key
void heap::printKey(int index) {
    int key = H[index]->getKey();
    cout << key << endl;
}

//return a bool tell if the heap is full or not
bool heap::fullChecker() {
    return (this->size == this->capacity);
};

//clean the loop
void heap::clean() {
    this->size = 0;
}

//element class
element::element() {
    this->key = 0;
};

//set the key of the element
element::element(int key) {
    this->key = key;
};

//return the key of the element
int element::getKey() {
    return this->key;
};

//incease the key to the key user entered
//if it's less than current key, print an error message and return
void element::increase(int key) {
    if (this->key <= key) {
        this->key = key;
    } else {
        std::cout << "Error: new key is smaller than current key" << std::endl;
    }
}

//override oprator == 
bool element::operator==(const element &other) {
    return (this->key == other.key);
}
