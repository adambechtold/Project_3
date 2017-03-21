//
// This is the implementation file for the Dictionary Class
// This file contains the implimentation of the dictionary class, including:
//  -Constructor
//  -overloaded << operator
//  -selectionSort function
//  -lookup function
//  -writedictionary function
//

#include "Dictionary.h"
#include <iostream>
#include <iomanip>

using namespace std;


Dictionary::Dictionary(string fileName)
//reads a dictionary from text file, writing the words to a vector
{
    ifstream fin;
    fin.open(fileName.c_str());
    if (!fin){
        cout << "File access failure.\n";
    }
    string line;
    while ( getline (fin,line) )
    {
        char firstletter = line[0];
        line[0] = (char)(tolower(firstletter));
        this->words.push_back(line);
    }

    fin.close();
}

ostream &operator<<(ostream &ostr, const Dictionary &d)
//overloads the << operator to print out the contents of the dictionary
{

    for(int i = 0; i < d.words.size(); i++) {
        ostr << d.words[i] << endl;
    }


    return ostr;
}

void Dictionary::selectionSort()
//selectionSort uses a selection sort (I know, amazing!) to arrange an unsorted
//dictionary. It has no input arguments or output values
{
    //values track the progress of the search function
    bool percentTrack = true;
    if (this->words.size() < 100) {
        percentTrack = false;
    }
    int onePercentBlock = this->words.size()/100;
    int currentPercent = -1;

    for(int i = 0; i < this->words.size() - 1; i++)
    {
        if(percentTrack && i % onePercentBlock == 0) {
            currentPercent++;
            cout << "\r" << "percent complete: " << currentPercent << "%";
            cout.flush();
        }
        int min = i;
        for (int j = i + 1; j < this->words.size(); j++)
        {
            string currCheck = this->words[j];
            string currMin = this->words[min];
            if (currMin.compare(currCheck) > 0)
            {
                min = j;
            }
        }
        swap(this->words[i], this->words[min]);
    }
    cout << endl << endl;
}

int partitionHelp(vector<string> &A, int left, int right) {
    string pivot = A[(left + right) / 2];
    while(left != right) {
        while(A[left].compare(pivot) < 0) {
            left++;
        }

        while(A[right].compare(pivot) > 0) {
            right--;
        }

        if(left <= right) {
            swap(A[left], A[right]);
        }
    }
    return left;
}

void quickSortHelp(vector<string> &A, int left, int right) {
    if (left < right) {
        int s = partitionHelp(A, left, right);
        quickSortHelp(A, left, s - 1);
        quickSortHelp(A, s + 1, right);
    }
}

void Dictionary::quickSort()
//sort the words of the dictionary with the quicksort algorithm
{
    quickSortHelp(this->words, 0, this->words.size() - 1);
}


int Dictionary::lookup(string& target)
//lookup is handed a string, and uses a binary search to try and find
//the string in the list.  If found, lookup returns the index from the
//dictionary.  Otherwise, it returns -1.
{

    //initializes beginning and end of search index
    int first = 0;
    int last = (int) this->words.size() - 1;

    while (first <= last)
    {
        //establishes mid point of array
        int mid = (first + last) / 2;
        string midValue = this->words[mid];
        if (target == midValue)
        //if target is found, return the index found at
        {
            return mid;
        }
        else if (target.compare(midValue) < 0)
        //if the target come before the mid value, search the first half
            last = mid - 1;
        else
         //otherwise, search the second half of the list
            first = mid + 1;
    }
    return -1;
    //target not found in the list
}

void Dictionary::writedictionary()
//writedictionary is used to write the dictionary class into an output file
//used to write the Sorted Dictionary as a text file, so the 90,000 word
//dictionary didn't have to be sorted every time
//
// it was used during development, and is kept here for you to see even
// though it is not used during runtime.
{
    int i = 0;
    string word;
    string dictname;
    ofstream fout;
    //ask for name of file to be written
    cout << "What would you like to name the new dictionary? \n";
    cin >> dictname;
    dictname += ".txt";
    fout.open(dictname);
    while (i < this->words.size())
        //prints entire dictionary to the generated file
    {
        word = this->words.at(i);
        fout << word << endl;
        i++;
    }
    fout.close(); //closes file
    if (!fout.is_open())
    {
        cout << "Sorted dictionary has been successfully closed";
    }
}


