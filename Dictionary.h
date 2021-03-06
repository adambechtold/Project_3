//
// This is the header file for the Dictionary Class
// This file includes all the functions available to this class, including
//  -Constructor
//  -overloaded << operator
//  -a three functions to sort the dictionary (quickSort, heapSort, and selectionSort)
//  -a lookup function, which tries to find a given string, and returns the index
//  -a writeDictionary function, which writes the dictionary to a new file
// Includes the private variables:
//  -words, a vector containing the entire dictionary
//

#include <vector>
#include <fstream>

using namespace std;

#ifndef PROJECT_3_DICTIONARY_H
#define PROJECT_3_DICTIONARY_H


class Dictionary {
private:
    vector<string> words;

public:
    Dictionary(string fileName);

    friend ostream& operator<< (ostream& ostr, const Dictionary &d);

    void selectionSort();

    void quickSort();

    void heapSort();

    int lookup(string& target);

    void writedictionary();
};


#endif //PROJECT_3_DICTIONARY_H
