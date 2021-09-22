#include <iostream>
#include "Tree.h"
using namespace std;

Tree::Tree(/*Post * post*/)
{
    root = nullptr;
    //InsertPosts(post);
}


void Tree::InsertPosts(Post * post)
{
    bool found = false;
    Node * temp = new Node();                                                         //node to be added

    temp->creator = post->getCreator();

    if (!root)
        setRoot(temp);

    Node * curr = root;                                                               //node for traversial

    while (curr->leftChild && temp->rightChild)
    {
        if (temp->creator > curr->creator)
            curr = curr->rightChild;
        else if (temp->creator < curr->creator)
            curr = curr->leftChild;
        else                                                                          //creator already exists
        {
            found = true;
            break;
        }

        if (found)
        {
            curr->myPosts->InsertPost(post);
            delete temp;
        }

        else
        {
            if (curr->leftChild)
                curr->rightChild = temp;
            else
                curr->leftChild = temp;

            temp->myPosts = new PostList;
            temp->myPosts->InsertPost(post);
        }

    }
    temp->leftChild = nullptr;
    temp->rightChild = nullptr;
}


void Tree::PrintTree(Node * curr)                                                     //inorder recursive traversal
{
    if (!curr)
        return;

    cout <<"Printing posts of creator: " <<curr->creator << endl;

    if (curr->myPosts)
        curr->myPosts->PrintAllPosts();

    PrintTree(curr->leftChild);

    cout <<"Printing posts of creator: " <<curr->creator << endl;

    if (curr->myPosts)
        curr->myPosts->PrintAllPosts();

    PrintTree(curr->rightChild);
}


void Tree::DeleteTree(Tree::Node * curr)                                                //delete hole tree
{
    if (!curr)
        return;

    DeleteTree(curr->leftChild);
    delete curr->myPosts;
    DeleteTree(curr->rightChild);
    delete curr->myPosts;
    delete(curr);
}


Tree::~Tree()                                                                           //destructor
{
    DeleteTree(root);
}


Tree::Node *Tree::getRoot()                                                            //getter for tree root
{
    return root;
}


void Tree::setRoot(Tree::Node *root)
{
    Tree::root = root;
}
