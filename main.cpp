#include <iostream>
#include <iomanip>
#include "Dictionary.h"
#include "Grid.h"
#include "d_matrix.h"

using namespace std;

void checkAndPrint(string s, Dictionary d) {
    if (d.lookup(s) != -1) {
        cout << s << endl;
    }
}

string joinVector(vector<string> v) {
    string result;
    for (auto const& s : v) { result += s; }
    return result;
}

void findMatches(Dictionary d, Grid g) {
    cout << "\nlet's find those matches\n";

    int rows = g.getRows();
    int cols = g.getCols();

    //sort the dictionary
    //d.selectionSort();

    //check for words in the grid
    for(int i = 0; i < g.getRows(); i++) {
        for(int j = 0; j < g.getCols(); j++) {
            //see if the letter is in the dictionary
            checkAndPrint(g.getItem(i, j), d);

            vector<string> left, right, up, down, upleft, upright, downright, downleft;

            left.push_back(g.getItem(i,j));
            right.push_back(g.getItem(i,j));
            up.push_back(g.getItem(i,j));
            down.push_back(g.getItem(i,j));
            upleft.push_back(g.getItem(i,j));
            upright.push_back(g.getItem(i,j));
            downleft.push_back(g.getItem(i,j));
            downright.push_back(g.getItem(i,j));

            //check elements
            for(int a = 1; a < cols; a++) {
                int moveleft = (((j - a) %  cols) + cols) % cols;
                int moveright = (((j + a) % cols) + cols) % cols;
                int moveup = (((i - a) % cols) + cols) % cols;
                int movedown = (((i + a) % cols) + cols) % cols;

                left.push_back(g.getItem(i, moveleft));
                right.push_back(g.getItem(i, moveright));
                down.push_back(g.getItem(movedown, j));
                up.push_back(g.getItem(moveup, j));
                upleft.push_back(g.getItem(moveup, moveleft));
                upright.push_back(g.getItem(moveup,moveright));
                downright.push_back(g.getItem(movedown, moveleft));
                downleft.push_back(g.getItem(movedown,moveright));

                string leftStr = joinVector(left);
                string rightStr = joinVector(right);
                string upStr = joinVector(up);
                string downStr = joinVector(down);
                string upleftStr = joinVector(upleft);
                string uprightStr = joinVector(upright);
                string downleftStr = joinVector(downleft);
                string downrightStr = joinVector(downright);

                checkAndPrint(leftStr, d);
                checkAndPrint(rightStr, d);
                checkAndPrint(upStr, d);
                checkAndPrint(downStr, d);
                checkAndPrint(upleftStr, d);
                checkAndPrint(uprightStr, d);
                checkAndPrint(downleftStr, d);
                checkAndPrint(downrightStr, d);
            }
        }
    }

}

int main() {
    Dictionary testDict = Dictionary("TestDictionary.txt");

    cout << "here is your dictionary: \n";
    cout << testDict;

    cout << "\nhere is your dictionary sorted :)\n";
    testDict.selectionSort();
    cout << testDict;

    Dictionary sortedDict = Dictionary("DictionarySorted.txt");

    Grid g = Grid("15x15grid.txt");
    Grid gSmall = Grid("5x5grid.txt");

    findMatches(sortedDict, gSmall);
    findMatches(sortedDict, g);


    return 0;
}

