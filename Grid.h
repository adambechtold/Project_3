//
// This is the header file for the Grid Class
// This file includes all the functions available to this class, including
//  -Constructor
//  -overloaded << operator
//  -a length function to return the grid side length
//  -a getItem function, which returns the character at a specified index
// Includes the private variables:
//  -mat, a matrix containing the entire grid
//  -nRows and nCols, specifying the size of the matrix
//
#include "d_matrix.h"
#include <cstdlib>

using namespace std;

#ifndef PROJECT_3_GRID_H
#define PROJECT_3_GRID_H


class Grid {
public:
    Grid(string fileName);

    //overloaded
    friend ostream& operator<< (ostream& ostr, const Grid& g);

    string getItem(int row, int col);

    int Length();

private:
    matrix<string> mat;

    int nRows, nCols;
};


#endif //PROJECT_3_GRID_H
