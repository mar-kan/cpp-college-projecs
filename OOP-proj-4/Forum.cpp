#include "Forum.h"
#include <string>
#include <iostream>
using namespace std;

Forum::Forum(string myTitle)                                                              //creates forum
{
    title = myTitle;
    myThreads = new ThreadList();                                                         //creates empty thread list

    cout << "Forum with title: " << title << " has just been created!\n";
}


void Forum::CreateThreads()                                                               //adds threads to forum
{
    int randNum, i;

    //myThreads = new ThreadList();

    randNum = rand() % 5 + 4;                                                             //small random num of Thread objects
    for (i = 0; i < randNum; i++)
    {
        Thread * addThread = new Thread;                                                  //create new object Thread
        myThreads->InsertThread(addThread);                                               //insert it to ThreadList
    }
}


void Forum::PrintForum()                                                                  //print all threads' subjects
{
    myThreads->PrintAllThreads();
}


void Forum::PrintOneThread(string title)                                                  //print thread with given title
{
    myThreads->PrintThreadByTitle(title);
}


void Forum::PrintRandomPosts()
{
    myThreads->SelectRandomThread();
}


Forum::~Forum()                                                                           //destructor
{
	delete myThreads;                                                                     //calls ThreadList destructor
	cout << "Forum with title: " << title << " is about to be destroyed.\n";
}


ThreadList *Forum::getMyThreads()
{
    return myThreads;
}
