#include <iostream>
#include <cassert>
#include "priority_queue.h"


PriorityQueue::PriorityQueue(int max_size) : max_size(max_size), size(0) {       // konstruktor parametrowy
    array = new int[max_size + 1];
} 

PriorityQueue::~PriorityQueue() {                                               // destruktor
    delete[] array;
}

int PriorityQueue::getParentIndex(int index) {                 // zwraca index rodzica
    return (index-1)/2;
}

int PriorityQueue::getLeftChildIndex(int index) {              // zwraca index lewego dziecka
    return 2*index + 1;
}

int PriorityQueue::getRightChildIndex(int index) {             // zwraca index prawego dziecka
    return 2*index + 2;
}

void PriorityQueue::heapify(int index) {                       // zamienia drzewo w stertę
    int leftIndex = getLeftChildIndex(index);
    int rightIndex = getRightChildIndex(index);
    int current_index = index;
    if((leftIndex < size) && (array[leftIndex] < array[index])) {
        current_index = leftIndex;
    }
    if((rightIndex < size) && (array[rightIndex] < array[current_index])) {
        current_index = rightIndex;
    }
    if (current_index != index) {
        std::swap(array[index], array[current_index]); 
        heapify(current_index);
    }
}



bool PriorityQueue::full() const {                             // zwraca czy tablica, na podstawie której bazuje drzewo, jest pełna
    return (max_size == size);
}



int PriorityQueue::getRoot() {                               // zwraca korzeń sterty
    return array[0];
}

int PriorityQueue::popRoot() {                               // usuwa korzeń sterty i zwraca jego wartość
    if(size == 0) {
        std::cout<<"No elements in queue ";
        return -1;
    } else if (size == 1) { 
        size--; 
        return array[0]; 
    } else {
        int root = array[0];
        array[0] = array[size - 1];
        size --;
        heapify(0);
        return root;
    }
}

void PriorityQueue::insert(const int priority) {                 // dodaje element "item" do sterty
    assert(!full());
    array[size] = priority;
    size ++;

    int i = size - 1;
    while((i != 0) && (array[i] < array[getParentIndex(i)])) {
        std::swap(array[i], array[getParentIndex(i)]); 
        i = getParentIndex(i); 
    }
}

void PriorityQueue:: print() {
    for (int i = 0; i < size/2; i++) {
        std::cout<<"PARENT : "<<array[i]<<"LEFT CHILD : "<<array[2*i + 1]<<"RIGHT CHILD : "<< array[2*i + 2]<<std::endl;
    }
}
