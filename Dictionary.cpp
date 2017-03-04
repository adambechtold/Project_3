//
// Created by Adam Bechtold on 3/4/17.
//

#include "Dictionary.h"
#include <iostream>
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
        cout << line << '\n';
    }

    fin.close();
}
