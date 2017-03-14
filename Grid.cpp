//
// This is the implementation file for the Grid Class
// This file contains the implementations of the grid functions, including the:
//  -Constructor
//  -overloaded << operator
//  -Length function
//  -getItem function
//


#include <fstream>
#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid(string fileName)
//initializes a grid object, with the grid file implemented as a matrix
{
    char letter;

    //open input file
    ifstream fin;
    fin.open(fileName);

    if (!fin){
        cout << "File access failure.\n";
    }

    //read he number of rows and columns in the grid file
    fin >> this->nRows;
    fin >> this->nCols;

    //initializes an nRow x nCol matrix
    this->mat = matrix<string>(this->nRows, this->nCols);

    //adds each character in the gridfile into the matrix
    for (int i = 0; i < this->nRows; i++) {
        for(int j = 0; j < this->nCols; j++) {
            fin >> letter;
            this->mat[i][j] = letter;
        }
    }

    fin.close();
}

ostream& operator<< (ostream& ostr, const Grid& g)
//overloads the << operator to print out the contents of the grid
{
    //prints out each letter of the matrix
    for (int i = 0; i < g.nRows; i++)
    {
        for (int j = 0; j < g.nCols; j++)
        {
            cout << g.mat[i][j] << " ";
        }
        cout << endl;
    }
    return ostr;
}

int Grid::Length()
//returns the length of the grid
{
    return this->nRows;
}

string Grid::getItem (int row, int col)
//gets a single character string from the grid's matrix
{
    return this->mat[row][col];
}
