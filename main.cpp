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
            while (l < 15)
            {
                mod1 = modval(i, l, 15);
                modi = modval(i, -l, 15);
                mod2 = modval(j, l, 15);
                modj = modval(j, -l, 15);

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
    cout << "Hello, World!" << endl;
    Dictionary testDict = Dictionary("SortedDictionary.txt");
/*
//    cout << "here is your dictionary: \n";
//    cout << testDict;
//    cout << "\nhere is your dictionary sorted :)\n";
//    testDict.selectionSort();
//    cout << testDict;
//    testDict.writedictionary();

//    int a = testDict.lookup("a");
//    int b = testDict.lookup("bactericide");
//    int c = testDict.lookup("skulls");
//    int e = testDict.lookup("awarded");
//    int r = testDict.lookup("unreeves");
//
//    cout << "a: " << a << endl;
//    cout << "b: " << b << endl;
//    cout << "c: " << c << endl;
//    cout << "e: " << e << endl;
//    cout << "r: " << r << endl;
*/
    Grid g = Grid("15x15.txt");

//    matrix<int> mm = matrix<int>(15, 15);
    cout << g;
    findMatches(g, testDict);

    return 0;
    //did this go through?
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