//
// Created by Adam Bechtold on 3/22/17.
//

#include "genTest.h"
#include <iostream>

using namespace std;

template <typename T>
genTest<T>::genTest(T t1, T t2) {
    this->t1 = t1;
    this->t2 = t2;
}

template <typename T>
T genTest<T>::getT1() {
    return this->t1;
}

template class genTest<int>;
