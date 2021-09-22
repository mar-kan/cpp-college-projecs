#include <string>
#include <iostream>
#include "PostList.h"
#include "Post.h"
#include "Tree.h"
using namespace std;


PostList::PostList()                                            //constructor of post list
{
    head = nullptr;
    count = 1;                                                  //so that first id num = 1
}


void PostList::InsertPost(Post * addPost)                       //insert an object Post in list
{
    Node * temp = new Node;

    temp->post = addPost;
    count++;

    if (!head)
    {
        temp->prev = nullptr;
        temp->next = nullptr;

    }else
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
    }
    head = temp;
}


void PostList::PrintAllPosts()                                  //prints all posts of a thread
{
    Node * temp = new Node;
    temp = head;
    while (temp)
    {
        temp->post->PrintPostData();
        temp = temp->next;
    }
    cout << endl;
}


bool PostList::PrintPost(int num)                               //searches in list for post with post id = num
{
    Node *  temp = new Node;
    temp = head;

    while (temp)
    {
        if (temp->post->getId() == num)
        {
            temp->post->PrintPostData();
            return true;
        }
        temp = temp->next;
    }
    return false;
}


PostList::~PostList()                                           //destructor of PostList
{
    Node * curr = head;
    Node * temp;

    while (curr)
    {
        temp = curr;
        curr = curr->next;
        delete temp->post;                                      //calls post destructor
        delete temp;
    }
}


int PostList::getCount()                                        //getter for count of Posts
{
    return count;
}


void PostList::InsertToTree(Tree * tree)
{
    Node * temp = head;

    while (temp)
    {
        tree->InsertPosts(temp->post);

        temp = temp->next;
    }
}


