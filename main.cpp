#include <iostream>
#include "Dictionary.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Dictionary d = Dictionary("TestDictionary.txt");

    cout << "here is your dictionary: \n";
    cout << d;

    return 0;
    //did this go through?
}