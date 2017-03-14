#include <iostream>
#include "Dictionary.h"
#include "Grid.h"
#include <iomanip>
#include "d_matrix.h"


//prints found words and their information
void printword(const string &word, const int &index, const int i, const int j);

using namespace std;


void findMatches (Grid grid, Dictionary dictionary)
//this function takes in a grid and dictionary, and goes through the entire
//grid, generates words from the grid, compares them against the dictionary,
//then prints out all the words that it found
{
    //initializes the strings we use to keep track of the words made
    string right, left, up, down, ur, ul, dr, dl;
    int moveright, moveleft, moveup, movedown, l, index;
    int length = grid.Length();
    cout << "The words will be presented in the following order: \n \n";
    cout << setw(15) << "Word";
    cout << setw(25) << "Sorted Dictionary index";
    cout << setw(15) << "Grid index" << endl;
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < length; i++) //each row of the grid
    {
        for (int j = 0; j < length; j++) //each column of the grid
        //re-initializes counter and strings for each grid starting point
        {
            l = 0;
            right.clear();
            left.clear();
            up.clear();
            down.clear();
            ur.clear();
            ul.clear();
            dr.clear();
            dl.clear();

            //look in each direction for words
            while (l < length)
            {


                moveright = (j + l) % length;
                moveleft = (i - l + length) % length;
                moveup = (j + l) % length;
                movedown = (j - l + length) % length;

                //add each letter to its respective string
                right += grid.getItem(moveright,j);
                left += grid.getItem(moveleft,j);
                up += grid.getItem(i,moveup);
                down += grid.getItem(i,movedown);
                ur += grid.getItem(moveright,moveup);
                ul += grid.getItem(moveleft,moveup);
                dr += grid.getItem(moveright,movedown);
                dl += grid.getItem(moveleft,movedown);

                //ensures the word being looked up is at least 5 letters
                if (l >= 4) {
                    //prints out word if found
                    if (dictionary.lookup(right) > -1)
                        printword(right, dictionary.lookup(right), i, j);

                    if (dictionary.lookup(left) > -1)
                        printword(left, dictionary.lookup(left), i, j);

                    if (dictionary.lookup(up) > -1)
                        printword(up, dictionary.lookup(up), i, j);

                    if (dictionary.lookup(down) > -1)
                        printword(down, dictionary.lookup(down), i, j);

                    if (dictionary.lookup(ur) > -1)
                        printword(ur, dictionary.lookup(ur), i, j);

                    if (dictionary.lookup(ul) > -1)
                        printword(ul, dictionary.lookup(ul), i, j);

                    if (dictionary.lookup(dr) > -1)
                        printword(dr, dictionary.lookup(dr), i, j);

                    if (dictionary.lookup(dl) > -1)
                        printword(dl, dictionary.lookup(dl), i, j);
                } //end if l >= 4 loop
                l++;
            } //end the while l < grid.Length() loop
        } //end the column for loop
    } //end the row for loop

}

void search()
//search takes in a dictionary, asks the user for the name of a grid to search
//if the grid file is found, the function calls findMatches to find the words
//from the given grid in the dictionary
{
    Dictionary testDict = Dictionary("SortedDictionary.txt");
    //testDict.selectionSort();
    string gridname;
    ifstream gridfile;
    bool found = false;

    while (!found)
    {
        cout << "Please put the name of the grid you'd like to search: " << endl;
        cin >> gridname; //reads grid name from user
        gridfile.open(gridname); //attempts to open gridname

        if (!gridfile)
            //checks to see if name of grid is valid
        {
            cout << "Unable to find file.\n";
        }
        else
            //if gridname is valid, generates a grid from the gridname
            //calls findMatches to compare the gridname against the dictionary
        {
            found = true;
            Grid grid = Grid(gridname);
            findMatches(grid, testDict);
        }
    }
    gridfile.close();
}


int main()
//calls search function and returns 0
{
    search();
    return 0;
}

void printword(const string &word, const int &index, const int i, const int j)
//prints out information regarding the word found in the grid
{
    cout << setw(15) << word;
    cout << setw(25) << index;
    cout << setw(10) << "(" << i << "," << j << ")\n";

}