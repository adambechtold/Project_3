#include <iostream>
#include <iomanip>
#include "Dictionary.h"
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

    ifstream fin;
    string fileName = "15x15grid.txt";
    fin.open(fileName);
    if (!fin){
        cout << "File access failure.\n";
    }
    string nRowStr;
    string nColStr;

    fin >> nRowStr;
    fin >> nColStr;

    int nRow = stoi(nRowStr);
    int nCol = stoi(nColStr);


    string letter;

    matrix<string> testMat = matrix<string>(nRow, nCol);

    for (int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++) {
            fin >> letter;
            testMat[i][j] = letter;
        }
        cout << endl;
    }

    testMat.print();



    return 0;
    //did this go through?
}