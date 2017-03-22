//
// Created by Patrick on 3/15/17.
//


#ifndef PROJECT_3_HEAP_H
#define PROJECT_3_HEAP_H

#include <vector>

using namespace std;

template <typename T>
class Heap
{

public:
    Heap(vector <T> list);

    int parent (int& index);

    int left (int& index);

    int right (int& index);

    T getItem (int& index);

    void heapSort ();

    void maxHeapify(int i);

    void buildMaxHeap();
private:
    vector <T> heaplist;

    long length;
};

#endif //PROJECT_3_HEAP_H

