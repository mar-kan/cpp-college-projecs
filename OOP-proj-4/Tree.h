#ifndef TREE_H
#define TREE_H

#include <string>
#include "Post.h"
#include "Thread.h"
using namespace std;


class Tree {

    struct Node
    {
        string creator;                                                                //key
        PostList * myPosts;
        Node * leftChild;
        Node * rightChild;
    };
    Node * root = nullptr;

public:
    Tree(/*Post **/);
    void InsertPosts(Post *);
    void PrintTree(Node *);                                                           //prints all tree
    void DeleteTree(Node *);                                                          //deletes hole tree
    virtual ~Tree();
    Node * getRoot();

    void setRoot(Node *root);
};


#endif
