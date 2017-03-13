#include <iostream>
#include "Dictionary.h"
#include "Grid.h"
#include <queue>
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
    //queue <pair> coordinates;
    queue <int> dictindex;
    int mod1, modi, mod2, modj, l, index;
    int length = grid.Length();
    //pair Charindex;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
        //re-initializes counter and strings for each grid starting point
            //Charindex.first = i;
            //Charindex.second = j;
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

                //ensures the word being looked up is at least 5 letters
                if (l >= 4) {
                    //increments the list queue if found.
                    if (dictionary.lookup(right, index))
                    {
                        cout << right << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;
                    }
                    if (dictionary.lookup(left, index))
                    {
                        cout << left << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;

                    }
                    if (dictionary.lookup(up, index))
                    {
                        cout << up << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;

                    }
                    if (dictionary.lookup(down, index))
                    {
                        cout << down << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;
                    }
                    if (dictionary.lookup(ur, index))
                    {
                        cout << ur << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;
                    }
                    if (dictionary.lookup(ul, index))
                    {
                        cout << ul << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;
                    }
                    if (dictionary.lookup(dr, index))
                    {
                        cout << dr << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;
                    }
                    if (dictionary.lookup(dl, index))
                    {
                        cout << dl << "\t" << index << "\t(";
                        cout << i << ", " << j << ")" << endl;
                    }
                    /*
                    //increments the list queue if found.
                    if (dictionary.lookup(right, index))
                    {
                        list.push(right);
                        coordinates.push(Charindex);
                        dictindex.push(index);
                    }
                    if (dictionary.lookup(left, index))
                    {
                        list.push(left);
                        coordinates.push(Charindex);
                        dictindex.push(index);

                    }
                    if (dictionary.lookup(up, index))
                    {
                        list.push(up);
                        coordinates.push(Charindex);
                        dictindex.push(index);

                    }
                    if (dictionary.lookup(down, index))
                    {
                        list.push(down);
                        coordinates.push(Charindex);
                        dictindex.push(index);
                    }
                    if (dictionary.lookup(ur, index))
                    {
                        list.push(ur);
                        coordinates.push(Charindex);
                        dictindex.push(index);
                    }
                    if (dictionary.lookup(ul, index))
                    {
                        list.push(ul);
                        coordinates.push(Charindex);
                        dictindex.push(index);
                    }
                    if (dictionary.lookup(dr, index))
                    {
                        list.push(dr);
                        coordinates.push(Charindex);
                        dictindex.push(index);
                    }
                    if (dictionary.lookup(dl, index))
                    {
                        list.push(dl);
                        coordinates.push(Charindex);
                        dictindex.push(index);
                    }
                     */
                } //end if l >= 4 loop
                l++;
            } //end the while l < grid.Length() loop
        } //end the column for loop
    } //end the row for loop
    /*
    cout << "There were " << list.size() << " words found: " << endl;
    cout << "The words will be presented in the following order" << endl;
    cout << "Word\tSorted Dictionary index\tGrid index" << endl;
    while(!list.empty())
        //Moves through the list of words, printing them out one by one.
        //It then removes the word from the list until none are left.
    {
        cout << list.front() << "\t" << dictindex.front() << "\t";
        cout << "(" << coordinates.front() << ")\n";
        list.pop();
        dictindex.pop();
        coordinates.pop();
    }
     */
}

void search()
//search takes in a dictionary, asks the user for the name of a grid to search
//if the grid file is found, the function calls findMatches to find the words
//from the given grid in the dictionary
{
    Dictionary testDict = Dictionary("SortedDictionary.txt");
    string gridname;
    bool found = false;

    while (!found)
    {
        cout << "Please put the name of the grid you'd like to search: " << endl;
        cin >> gridname; //reads gridname from user
        ifstream gridfile;
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
}


int main()
//calls search function and returns 0
{
    search();
    return 0;
}

int modval(int a, int b, int mod)
//modval returns a value between 0 and mod - 1, and is used in place of
//% as the predefined modulo function cannot handle negative values
{

    int x = a + b;
    while (x < 0)
    {
       x = x + mod;
    }
    return x % mod;
}