#include <iostream>
#include <iomanip>
#include "Dictionary.h"
#include "Grid.h"
#include "d_matrix.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    Dictionary testDict = Dictionary("TestDictionary.txt");

    cout << "here is your dictionary: \n";
    cout << testDict;

    cout << "\nhere is your dictionary sorted :)\n";
    testDict.selectionSort();
    cout << testDict;

//    int a = testDict.lookup("a");
//    int b = testDict.lookup("bactericide");
//    int c = testDict.lookup("skulls");
//    int e = testDict.lookup("awarded");
//    int r = testDict.lookup("unreeves");
//
//    cout << "a: " << a << endl;
//    cout << "b: " << b << endl;
//    cout << "c: " << c << endl;
//    cout << "e: " << e << endl;
//    cout << "r: " << r << endl;

    Grid g = Grid("15x15grid.txt");

    matrix<int> mm = matrix<int>(15, 15);


//    cout << g;


    return 0;
    //did this go through?
}