#include <iostream>
#include "Dictionary.h"
#include "Grid.h"
#include <queue>
#include <fstream>
#include "d_matrix.h"

int modval(int a, int b, int mod);

using namespace std;


void findMatches (Grid grid, Dictionary dictionary)
//this function takes in a grid and dictionary, and goes through the entire
//grid, generates words from the grid, compares them against the dictionary,
//then prints out all the words that it found
{
    //initializes the strings we use to keep track of the words made
    string right, left, up, down, ur, ul, dr, dl;
    queue <string> list; //list to store words found in the dictionary
    int mod1, modi, mod2, modj, l;
    int length = grid.Length();

    for (int i = 0; i < grid.Length(); i++)
    {
        for (int j = 0; j < grid.Length(); j++)
        {
        //reinitializes counter and strings for each character in the grid
            l = 0;
            right.clear();
            left.clear();
            up.clear();
            down.clear();
            ur.clear();
            ul.clear();
            dr.clear();
            dl.clear();

            while (l < length)
            {
                mod1 = modval(i, l, length);
                modi = modval(i, -l, length);
                mod2 = modval(j, l, length);
                modj = modval(j, -l, length);

                right += grid.getItem(mod1,j);
                left += grid.getItem(modi,j);
                up += grid.getItem(i,mod2);
                down += grid.getItem(i,modj);
                ur += grid.getItem(mod1,mod2);
                ul += grid.getItem(modi,mod2);
                dr += grid.getItem(mod1,modj);
                dl += grid.getItem(modi,modj);

                //this if statement forces the words to be at least 5 letters
                //long.  On each loop afterwards, it determines if the current
                //word is in the dictionary.  If so, it adds it to the list.
                if (l >= 4)
                {
                    if (dictionary.lookup(right))
                    {
                        list.push(right);
                    }
                    if (dictionary.lookup(left))
                    {
                        list.push(left);
                    }
                    if (dictionary.lookup(up))
                    {
                        list.push(up);
                    }
                    if (dictionary.lookup(down))
                    {
                        list.push(down);
                    }
                    if (dictionary.lookup(ur))
                    {
                        list.push(ur);
                    }
                    if (dictionary.lookup(ul))
                    {
                        list.push(ul);
                    }
                    if (dictionary.lookup(dr))
                    {
                        list.push(dr);
                    }
                    if (dictionary.lookup(dl))
                    {
                        list.push(dl);
                    }
                } //end if l >= 4 loop
                l++;
            } //end the while l < grid.Length() loop
        } //end the column for loop
    } //end the row for loop
    cout << "There were " << list.size() << " words found: " << endl;

    while(!list.empty())
        //Moves through the list of words, printing them out one by one.
        //It then removes the word from the list until none are left.
    {
        cout << list.front() << endl;
        list.pop();
    }
}

bool search(Dictionary d)
//search takes in a dictionary, asks the user for the name of a grid to search
//if the grid file is found, the function calls findMatches to find the words
//from the given grid in the dictionary
{
    string gridname;
    cout << "Please put the name of the grid you'd like to search: " << endl;
    cin >> gridname; //reads gridname from user
    ifstream gridfile;
    gridfile.open(gridname); //attempts to open gridname

    if (!gridfile)
    //checks to see if name of grid is valid
    {
        cout << "Unable to find file.\n";
        return false;
    }
    else
    //if gridname is valid, generates a grid from the gridname
    //calls findMatches to compare the gridname against the dictionary
    {
        Grid grid = Grid(gridname);
        findMatches (grid, d);
        return true;
    }
    gridfile.close;
}


int main()
//main function controls the flow of the program.
//it initializes the dictionary, and searches various grids for suitable words
{
    bool istrue = false;
    Dictionary testDict = Dictionary("SortedDictionary.txt");
    Grid g = Grid("15x15grid.txt");
    Grid gSmall = Grid("5x5grid.txt");
    Dictionary sortedDict = Dictionary("DictionarySorted.txt");

    findMatches(g, sortedDict);
    findMatches(gSmall, sortedDict);


    return 0;
}

int modval(int a, int b, int mod)
//this function will always return a value between 0 and mod - 1
//writen to be able to handle a - b when b is larger than a
{

    int x = a + b;
    while (x < 0)
    {
       x = x + mod;
    }
    return x % mod;
}