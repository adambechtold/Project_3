#include <iostream>
#include <iomanip>
#include "Dictionary.h"
#include "Grid.h"
#include "d_matrix.h"

using namespace std;

void findMatches (Grid grid, Dictionary dictionary)
{
    string right, left, up, down, ur, ul, dr, dl;
    vector <string> list;
    for (int i = 0; i < grid.Length(); i++)
    {
        for (int j = 0; j < grid.Length(); j++)
        {
            int l = 0;
            while (l < 5)
            {
                right.push_back(grid.returnChar((i+l)%15,j));
                left.push_back(grid.returnChar((i-l)%15,j));
                up.push_back(grid.returnChar(i,(j+l)%15));
                down.push_back(grid.returnChar(i,(j-l)%15));
                ur.push_back(grid.returnChar((i+l)%15,(j+l)%15));
                ul.push_back(grid.returnChar((i-l)%15,(j+l)%15));
                dr.push_back(grid.returnChar((i+l)%15,(j-l)%15));
                dl.push_back(grid.returnChar((i-l)%15,(j-l)%15));
                l++;
            }
            //determines if index [i][j] can create any words
            while (dictionary.lookup(right) || l < 15)
            {
                list.push_back(right);
                right.push_back(grid.returnChar((i+l)%15,j));
                l++;
            }
            l=5;
            while (dictionary.lookup(left) || l < 15)
            {
                list.push_back(left);
                left.push_back(grid.returnChar((i-l)%15,j));
                l++;
            }
            l=5;
            while (dictionary.lookup(up) || l < 15)
            {
                list.push_back(up);
                up.push_back(grid.returnChar(i,(j+l)%15));
                l++;
            }
            l=5;
            while (dictionary.lookup(down) || l < 15)
            {
                list.push_back(down);
                down.push_back(grid.returnChar(i,(j-l)%15));
                l++;
            }
            l=5;
            while (dictionary.lookup(ur) || l < 15)
            {
                list.push_back(ur);
                ur.push_back(grid.returnChar((i+l)%15,(j+l)%15));
                l++;
            }
            l=5;
            while (dictionary.lookup(ul) || l < 15)
            {
                list.push_back(ul);
                ul.push_back(grid.returnChar((i-l)%15,(j+l)%15));
                l++;
            }
            l=5;
            while (dictionary.lookup(dr) || l < 15)
            {
                list.push_back(dr);
                dr.push_back(grid.returnChar((i=l)%15,(j-l)%15));
                l++;
            }
            l=5;
            while (dictionary.lookup(dl) || l < 15)
            {
                list.push_back(dl);
                dl.push_back(grid.returnChar((i-l)%15,(j-l)%15));
                l++;

            }

        } //end the column for loop
    } //end the row for loop
    cout << "There were " <<list.size() << " words found";
    while(!list.empty())
    {
        cout << list.back();
        list.pop_back();
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