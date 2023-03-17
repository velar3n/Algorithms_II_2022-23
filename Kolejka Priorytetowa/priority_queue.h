#pragma once
#include <iostream>

class PriorityQueue { 
    int* array;                                     // tablica na której bazuje sterta
    int max_size;                                   // maksymalny rozmiar sterty = maksymalna liczba elementów
    int size;                                       // aktualny rozmiar sterty = aktualna liczba elemetów

public: 
    PriorityQueue(int max_size);
    ~PriorityQueue();

    int getParentIndex(int index);
    int getLeftChildIndex(int index);
    int getRightChildIndex(int index);
    void heapify(int index);
    bool full() const;

    int getRoot();
    int popRoot();
    void insert(const int priority);
    void print();
}; 