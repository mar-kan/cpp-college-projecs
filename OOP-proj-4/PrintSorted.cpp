#include <string>
#include <iostream>
#include "PrintSorted.h"
#include "Tree.h"
using namespace std;


void PrintSorted(Forum * forum)
{
    Tree * tree = new Tree();

    forum->getMyThreads()->InsertToTree(tree);                                      //creates tree

    tree->PrintTree(tree->getRoot());                                               //prints tree

    delete(tree);
}


