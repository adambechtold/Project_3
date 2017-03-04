#include <iostream>
#include "Dictionary.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Dictionary d = Dictionary("TestDictionary.txt");

    cout << "here is your dictionary: \n";
    cout << d;

    cout << "\nhere is your dictionary sorted :)\n";
    d.selectionSort();
    cout << d;

    return 0;
    //did this go through?
}