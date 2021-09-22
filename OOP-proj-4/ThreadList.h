#ifndef THREADLIST_H
#define THREADLIST_H

#include <string>
#include "Thread.h"
using namespace std;

class Thread;

class ThreadList                                          //doubly linked list that stores Thread objects
{
    struct Node
    {
        Thread * thread;
        Node * next;
        Node * prev;
    };
    Node * head;                                          //pointer to first Post

public:
    ThreadList();
    void InsertThread(Thread *);
    void PrintThreadByTitle(string);
    void PrintAllThreads();
    void SelectRandomThread();
    virtual ~ThreadList();

    void InsertToTree(Tree *tree);
};


#endif