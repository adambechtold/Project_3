//
// Created by Adam Bechtold on 3/4/17.
//
#include "d_matrix.h"
#include <cstdlib>

using namespace std;

#ifndef PROJECT_3_GRID_H
#define PROJECT_3_GRID_H


class Grid {
public:
    Grid(string fileName);
    int Length();
    friend ostream& operator<< (ostream& ostr, const Grid& g);
    char returnChar(int row, int column);
private:
    int nRow;
    int nCol;
    matrix<string> mat;

};


#endif //PROJECT_3_GRID_H
