// Kevin Mattappally and Han Tang
// 02/14/2018
// Clientprogram.cpp
// This program is an example of an ADT dictionary, in which different names of
// people are stored in as well as their phone numbers. With this dictionary
// we will be able to search for someone as well as remove and insert someone
// into the dictionary.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Dictionary.h"
#include "Item.h"
#include "Key.h"

using namespace std;

void openInputFile(ifstream& infile);
void sendToDictionary(ifstream& infile, Dictionary& newDictionary);
void sendToKey(ifstream& infile, Key& newKey);
void searchForItem(Dictionary& newDictionary, Key& newKey);
void removeItem(Dictionary& newDictionary, Key& newKey);
void printDictionary(Dictionary& newDictionary);

int main()
{
    ifstream infile;
    Dictionary mine;
    Key newKey;
    Item newItem;
    
    openInputFile(infile);
    
    // a)
    cout << "First, inserting four items to unique addresses into the hash table..." << endl;
    sendToDictionary(infile, mine);
    printDictionary(mine);
    // b)
    cout << "Next, inserting three items which share a common hashAddress in the hash table..." << endl;
    sendToDictionary(infile, mine);
    printDictionary(mine);
    // c)
    sendToKey(infile, newKey);
    searchForItem(mine, newKey);
    // c)
    sendToKey(infile, newKey);
    searchForItem(mine, newKey);
    // d)
    sendToKey(infile, newKey);
    removeItem(mine, newKey);
    printDictionary(mine);
    
    // e)
    sendToKey(infile, newKey);
    searchForItem(mine, newKey);
    return 0;
}

// checks to see if the input file is opened successfully
// pre: infile has been assigned an input file
// post: if the input file fails to open, then
//      ERROR in opening the file is printed,
//      otherwise the file has been open successfully
void openInputFile(ifstream& infile)
{
    infile.open("Input.dat");
    if (infile.fail())
    {
        cout << "ERROR in opening Input.dat !!!" << endl;
        exit(1);
    }
}

// takes in input from an input file and puts it into the dictionary
// pre: infile has been assigned an input file
// post: the contents of the infile has been
//      inserted into newDictionary
void sendToDictionary(ifstream& infile, Dictionary& newDictionary)
{
    infile >> newDictionary;
}

// takes in input from an input file and assigns it to a key
// pre: infile has been assigned an input file
// post: the input of the infile which is a
//      7-digit number has been assigned to newKey
void sendToKey(ifstream& infile, Key& newKey)
{
    infile >> newKey;
}

// searches for a key / phone number in the dictionary
// pre: newDictionary is assigned to a dictionary and
//     newKey is assigned to a 7-digit phone number
// post: if isFound is true, then desiredItem is set
//      to the Item that corresponds with the phone number set to newKey,
//      otherwise, item not found is printed out.
void searchForItem(Dictionary& newDictionary, Key& newKey)
{
    bool isFound;
    Item desiredItem;
    
    cout << "Now searching for desired phone number-> " << newKey << endl;
    newDictionary.search(newKey, desiredItem, isFound);
    if (not isFound)
        cout << "Desired item not found...\n";
    else
        cout << "Desired item found-> " << desiredItem << endl;
}

// helps to remove an item from the dictionary
// pre: newdictionary contains the to be removed item and
//      newKey is assigned to a 7-digit phone number
// post: newKey is removed from newDictionary
void removeItem(Dictionary& newDictionary, Key& newKey)
{
    bool isDone;
    
    cout << "Attempting to remove desired item-> " << newKey << endl;
    newDictionary.remove(newKey, isDone);
    if(not isDone)
        cout << "The desired item was not removed...\n";
    else
        cout << "The desired item was removed...\n";
}

// prints out the dictionary
// pre: newDictionary is assigned to a dictionary object
// post: newDictionary is printed out.
void printDictionary(Dictionary& newDictionary)
{
    cout << newDictionary << endl;
}


