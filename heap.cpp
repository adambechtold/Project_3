//
// Created by Patrick on 3/15/17.
//

#include <vector>
#include <cmath>
#include "heap.h"


Heap::Heap(vector<string> list)
//constructor for the Heap class, generates a vector of template type T
//Takes in a vector, and for the length of the input vector, adds the input
//vector's values to it's own vector
{
    for (int i = 0; i < list.size(); i++)
        this->heaplist.push_back(list[i]);
}

template <typename T>
T Heap::parent(int &index)
//Parent takes in the index of a word, determnes what it's parent is in the heap
//and returns the index to find the parent at
{
    int par = (int) floor(index/2);
    return par;
}

template <typename T>
T Heap::left(int &index)
//Left takes in the index of a word, determnes what it's left child is
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

template <typename T>
T Heap::right(int &index)
//Left takes in the index of a word, determnes what it's left child is
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
T Heap::getItem(int &index)
//getItem returns the value at a specified index
{
    return heaplist[index];
}

void Heap::heapSort()
//sorts the entire vector heaplist, using a heap sort algorithm
{

}

void Heap::initializeMaxHeap()
//TODO: I'm not entirely sure what she wants us to use this function for
// We already have a heap class constructor, and a heapSort function
{
}

void Heap::maxHeapify(int i)
//maxHeapify checks to make sure
{
    int largest, l, r;
    l = this->left(i);
    r = this->right(i);

    if (l <= this->length && this->getItem(l) > this->getItem(i))
        largest = l;

    else
        largest = i;

    if (r <= this->length && this->getItem(r) > this->getItem(i))
        largest = r;

    if (largest != i)
    {
        swap(this->getItem(i), this->getItem(largest));
        maxHeapify(this->getItem(largest));
    }
}

void Heap::buildMaxHeap() {

}



