//
// Created by Adam Bechtold on 3/4/17.
//

#include <fstream>
#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid(string fileName)
{
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

    this->nRows = stoi(nRowStr);
    this->nCols = stoi(nColStr);

    this->mat = matrix<string>(this->nRows, this->nCols);

    string letter;
    for (int i = 0; i < this->nRows; i++) {
        for(int j = 0; j < this->nCols; j++) {
            fin >> letter;
            this->mat[i][j] = letter;
        }
    }

    fin.close();
}

ostream& operator<< (ostream& ostr, const Grid& g)
{
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
{
    return this->nRow;
}

char Grid::returnChar(int row, int column)
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
vector<string> Grid::findCombos() {
    vector<string> list;


}

int Grid::getRows() {
    return this->nRows;
}

int Grid::getCols() {
    return this->nCols;
}

string Grid::getItem(int row, int col) {
    return this->mat[row][col];
}
