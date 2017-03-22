//
// Created by Patrick on 3/15/17.
//

#ifndef PROJECT_3_HEAP_H
#define PROJECT_3_HEAP_H

#include <math.h>
#include <vector>

using namespace std;


template <typename T>
class Heap
{

public:
    Heap(vector<T> list);

    int parent (int& index);

    int left (int& index);

    int right (int& index);

    T getItem (int& index);

    void heapSort ();

    void maxHeapify(int i);

    void buildMaxHeap();

    void InitializeMaxHeap(vector<T> t);
private:
    vector<T> heaplist;

    long length;
};

template <typename T>
Heap<T>::Heap(vector<T> list)
//constructor for the Heap class, generates a vector of template type T
//Takes in a vector, and for the length of the input vector, adds the input
//vector's values to it's own vector
{
    this->length = list.size();
    for (int i = 0; i < list.size(); i++)
        this->heaplist.push_back(list[i]);
}

template<typename T>
int Heap<T>::parent(int &index)
//Parent takes in the index of a word, determines what it's parent is in the heap
//and returns the index to find the parent at
{
    return (int) ceil(index / 2) - 1;
}

template<typename T>
int Heap<T>::left(int &index)
//Left takes in the index of a word, determines what it's left child is
//in the heap, and returns this value's index
{
    int lchild = 2 * index + 1;

    if (lchild > this->length) {
        return -1;
    }
    else {
        return lchild;
    }
}

template<typename T>
int Heap<T>::right(int &index)
//Left takes in the index of a word, determines what it's left child is
//in the heap, and returns this value's index
{
    int rchild = 2 * index + 2;

    if (rchild > this->length) {
        return -1;
    }
    else {
        return rchild;
    }
}

template <typename T>
T Heap<T>::getItem(int &index)
//getItem returns the value at a specified index
{
    return this->heaplist[index];
}

template<typename T>
void Heap<T>::heapSort()
//sorts the entire vector heaplist, using a heap sort algorithm
{
    buildMaxHeap();
    for (int i = (int)this->length - 1; i > 0; i--)
    {
        swap(this->heaplist[0], this->heaplist[i]);
        this->length--;
        maxHeapify(0);
    }
}

template<typename T>
void Heap<T>::maxHeapify(int i)
//maxHeapify checks to make sure
{
    int largest, l, r;
    l = left(i);
    r = right(i);

    if(l < 0)
        return;

    if (l < this->length && this->heaplist[l] > this->heaplist[i])
        largest = l;
    else
        largest = i;

    if (r < this->length && r >= 0 && this->heaplist[r] > this->heaplist[largest])
        largest = r;

    if (largest != i)
    {
        swap(this->heaplist[i], this->heaplist[largest]);
        maxHeapify(largest);
    }
}

template<typename T>
void Heap<T>::buildMaxHeap()
{
    for (int i = (int) (ceil(this->length / 2) - 1); i >= 0; i--)
        maxHeapify(i);
}


#endif //PROJECT_3_HEAP_H

