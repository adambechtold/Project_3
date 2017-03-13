#include <iostream>
#include <iomanip>
#include "Dictionary.h"
#include "Grid.h"
#include <queue>
#include "d_matrix.h"

int modval(int a, int b, int mod);

using namespace std;


void findMatches (Grid grid, Dictionary dictionary)
{
    string right, left, up, down, ur, ul, dr, dl;
    queue <string> list;
    int mod1, modi, mod2, modj, l;
    int length = grid.Length();

    for (int i = 0; i < grid.Length(); i++)
    {
        for (int j = 0; j < grid.Length(); j++)
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
            while (l < length)
            {
                mod1 = modval(i, l, length);
                modi = modval(i, -l, length);
                mod2 = modval(j, l, length);
                modj = modval(j, -l, length);

                right.push_back(grid.returnChar(mod1,j));
                left.push_back(grid.returnChar(modi,j));
                up.push_back(grid.returnChar(i,mod2));
                down.push_back(grid.returnChar(i,modj));
                ur.push_back(grid.returnChar(mod1,mod2));
                ul.push_back(grid.returnChar(modi,mod2));
                dr.push_back(grid.returnChar(mod1,modj));
                dl.push_back(grid.returnChar(modi,modj));
                if (l >= 4)  //determines if index [i][j] can create any words
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
                }
                l++;
            }
        } //end the column for loop
    } //end the row for loop
    cout << "There were " << list.size() << " words found: " << endl;
    while(!list.empty())
    {
        cout << list.front() << endl;
        list.pop();
    }
}

int main() {
    //Dictionary testDict = Dictionary("SortedDictionary.txt");

    Grid g = Grid("15x15grid.txt");
    Dictionary sortedDict = Dictionary("DictionarySorted.txt");

    //findMatches(g, sortedDict);


    Grid gSmall = Grid("5x5grid.txt");

    findMatches(gSmall, sortedDict);
    //findMatchesAdam(sortedDict, g);


    return 0;
}

int modval(int a, int b, int mod)
{
    int x = a + b;
    while (x < 0)
    {
       x = x + mod;
    }
    return x % mod;
}

