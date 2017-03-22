//
// Created by Patrick on 3/15/17.
//


#include <vector>
#include <cmath>
#include "Heap.h"

template<typename T>
Heap<T>::Heap(vector<string> list)
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
    int par = (int) floor(index/2);
    return par;
}

template<typename T>
int Heap<T>::left(int &index)
//Left takes in the index of a word, determines what it's left child is
//in the heap, and returns this value's index
{
    if (2 * index > this->length)
    {
        return -1;
    }
    else
    {
        int lchild = 2 * index;
    return lchild;
    }
}

template<typename T>
int Heap<T>::right(int &index)
//Left takes in the index of a word, determines what it's left child is
//in the heap, and returns this value's index
{
    if (2*index >= this->length)
    {
        return -1;
    }
    else
    {
        int rchild = 2 * index + 1;
        return rchild;
    }
}

template <typename T>
T Heap<T>::getItem(int &index)
//getItem returns the value at a specified index
{
    return heaplist[index];
}

template<typename T>
void Heap<T>::heapSort()
//sorts the entire vector heaplist, using a heap sort algorithm
{
    buildMaxHeap();
    for (int i = (int) this->length; i > 0; i--)
    {
        swap(this->heaplist[1], this->heaplist[i]);
        this->length--;
        maxHeapify(1);
    }
}

template<typename T>
void Heap<T>::maxHeapify(int i)
//maxHeapify checks to make sure
{
    int largest, l, r;
    l = left(i);
    r = right(i);

    if (0 < l <= this->length && this->getItem(l) > this->getItem(i))
        largest = l;

    else
        largest = i;

    if (0 < r <= this->length && this->getItem(r) > this->getItem(i))
        largest = r;

    if (largest != i)
    {
        swap(this->getItem(i), this->getItem(largest));
        maxHeapify(this->getItem(largest));
    }
}

template<typename T>
void Heap<T>::buildMaxHeap()
{
    for (int i = (int) (floor(this->length / 2)); i > 0; i--)
        maxHeapify(i);
}