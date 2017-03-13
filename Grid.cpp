//
// Created by Adam Bechtold on 3/4/17.
//

#include <fstream>
#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid(string fileName)
//initializes a grid object, with the gridfile implimented as a matrix
{
    char letter;

    //open input file
    ifstream fin;
    fin.open(fileName);

    if (!fin){
        cout << "File access failure.\n";
    }

    //read he number of rows and columns in the grid file
    fin >> this->nRow;
    fin >> this->nCol;

    //initializes an nRow x nCol matrix
    this->mat = matrix<string>(nRow, nCol);

    //adds each character in the gridfile into the matrix
    for (int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++) {
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
    for (int i = 0; i < g.nRow; i++)
    {
        for (int j = 0; j < g.nCol; j++)
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
    return this->nRow;
}

char Grid::returnChar(int row, int column)
//returns the character from the grid at position [row][column]
{
    vector <string> x;
    x = this->mat[row];
    string C = (basic_string<char, char_traits<char>, allocator<char>> &&) x.at(column);
    char Ch;
    Ch = C.at(0);
    return Ch;
}
/*
 * TODO modify the returnChar function to handle the matrix
 * Determine a way to return a string as a character
*/


int Grid::getRows() {
    return this->nRows;
}

int Grid::getCols() {
    return this->nCols;
}

string Grid::getItem(int row, int col) {
    return this->mat[row][col];
}
