//
// Created by Adam Bechtold on 3/4/17.
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

    int lookup(string word);
};


#endif //PROJECT_3_DICTIONARY_H
