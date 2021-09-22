#include <iostream>
#include "ThreadList.h"
using namespace std;


ThreadList::ThreadList()                                                           //create empty list
{
    head = nullptr;
}


void ThreadList::InsertThread(Thread * addThread)                                  //insert object thread
{
    Node * temp = new Node;

    temp->thread = addThread;

    if (!head)
    {
        temp->prev = nullptr;
        temp->next = nullptr;
        temp->thread->setSubject("Κανόνες και χρήσιμες πληροφορίες");       //change first thread's subject

    }else
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
    }
    head = temp;
}


void ThreadList::PrintThreadByTitle(string title)
{
    Node * temp = new Node;
    temp = head;

    while (temp)
    {
        if (temp->thread->getSubject() == title)
            temp->thread->PrintThreadData();

        temp = temp->next;
    }
    cout << endl;
    delete temp;
}


void ThreadList::PrintAllThreads()
{
    Node * temp = new Node;
    temp = head;

    cout << "Printing All Threads:\n";
    while (temp != nullptr)
    {
        temp->thread->PrintThreadData();
        temp = temp->next;
    }
    delete temp;
}


ThreadList::~ThreadList()
{
    Node * curr = head;
    Node * temp;

    while (curr != nullptr)
    {
        temp = curr;
        curr = curr->next;

        delete temp->thread->getMyPosts();                                         //calls Post Destructor for every Threads' Post list
        delete temp->thread;
        delete temp;
    }
}


void ThreadList::SelectRandomThread()
{
    Node * temp = head;
    int i, count;
    int num = rand() % 9;                                                          //max num of threads

    for (i = 0; i <= num; i++)                                                     //select random thread
    {
        if (temp)
            temp = temp->next;
    }
    if (!temp)                                                                     //if num invalid temp = head
        temp = head;

    count = temp->thread->getMyPosts()->getCount();

    for (i = 0; i < 10; i++)                                                       //print 10 random posts
    {
        num = rand() % count + 1;
        temp->thread->getMyPosts()->PrintPost(num);
    }

}


void ThreadList::InsertToTree(Tree *tree)
{
    Node * temp = head;

    while (temp)
    {
        temp->thread->getMyPosts()->InsertToTree(tree);

        temp = temp->next;
    }
}