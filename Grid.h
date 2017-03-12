//
// Created by Adam Bechtold on 3/4/17.
//
#include "d_matrix.h"

#include <vector>

using namespace std;

#ifndef PROJECT_3_GRID_H
#define PROJECT_3_GRID_H


class Grid {
public:
    Grid(string fileName);
    //friend ostream& operator<< (ostream& ostr, const Grid& g);
    vector<string> findCombos();
    int getRows();
    int getCols();
    string getItem(int row, int col);
private:
    matrix<string> mat;
    int nRows, nCols;
};


#endif //PROJECT_3_GRID_H
