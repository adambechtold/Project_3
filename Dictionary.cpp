//
// Created by Adam Bechtold on 3/4/17.
//

#include "Dictionary.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


Dictionary::Dictionary(string fileName) {
    ifstream fin;
    fin.open(fileName.c_str());
    if (!fin){
        cout << "File access failure.\n";
    }
    string line;
    while ( getline (fin,line) )
    {
        //cout << line << '\n';
        this->words.push_back(line);
    }

    fin.close();
}

ostream &operator<<(ostream &ostr, const Dictionary &d) {

    for(int i = 0; i < d.words.size(); i++) {
        ostr << d.words[i] << endl;
    }


    return ostr;
}

void Dictionary::selectionSort() {
    for(int i = 0; i < this->words.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < this->words.size(); j++) {
            string currCheck = this->words[j];
            string currMin = this->words[min];
            if (currMin.compare(currCheck) > 0) {
                min = j;
            }
        }
        swap(this->words[i], this->words[min]);
    }
}

int Dictionary::lookup(string target) {
    int first = 0;
    int last = this->words.size() - 1;

    while (first <= last) {
        int mid = (first + last) / 2;
        string midValue = this->words[mid];
        if (target == midValue) {
            return mid; //target found. Return index.
        }
        else if (target.compare(midValue) < 0)
            last = mid - 1;
        else
            first = mid + 1;
    }
    //target not found in the list
    return -1;
}


