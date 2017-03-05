//
// Created by Adam Bechtold on 3/4/17.
//

#include <fstream>
#include "Grid.h"

using namespace std;

Grid::Grid(string fileName) {
    //open input file
    ifstream fin;
    fin.open(fileName);
    if (!fin){
        cout << "File access failure.\n";
    }

    //gather data from the first two lines of the
    string nRowStr;
    string nColStr;

    fin >> nRowStr;
    fin >> nColStr;

    int nRow = stoi(nRowStr);
    int nCol = stoi(nColStr);

    this->mat = matrix<string>(nRow, nCol);

    string letter;
    for (int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++) {
            fin >> letter;
            this->mat[i][j] = letter;
        }
    }

    fin.close();
}

//ostream& operator<< (ostream& ostr, const Grid& g) {
//    ostr << g.mat;
//    return ostr;
//}
