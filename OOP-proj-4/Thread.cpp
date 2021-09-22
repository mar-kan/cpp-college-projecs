#include <iostream>
#include <fstream>
#include "Thread.h"
#include "Post.h"
using namespace std;


Thread::Thread()
{
    fstream tFile, uFile;                                                           //insert data from files
    string filename, word;

    int i, randNum;

    filename = "topics";
    tFile.open(filename.c_str());

    randNum = rand()% 23 + 1;                                                       //24 lines of file topics
    for (i = 0; i <= 23; i++)                                                       //get random line of file
    {
        tFile >> word;
        if (i == randNum)
        {
            subject = word;
            break;
        }
    }

    filename = "usernames";
    uFile.open(filename.c_str());

    randNum = rand()% 96 + 1;                                                       //97 lines of file usernames
    for (i = 0; i <= 96; i++)                                                       //get random line of file
    {
        uFile >> word;
        if (i == randNum)
        {
            creator = word;
            break;
        }
    }

    dateThr = new Date();

    cout << "Thread with subject: " << subject << " has just been created!\n\n";

    myPosts = new PostList();                                                       //create this thread's post list

    randNum = rand()%5 + 2;                                                         //random small num of posts
    for (i = 0; i < randNum; i++)
    {
        Post * post = new Post(myPosts);                                            //create objects Post
        myPosts->InsertPost(post);                                                  //insert objects to list
    }

    tFile.close();
    uFile.close();
}


void Thread::PrintThreadData()                                                      //prints thread with subject = title
{
    cout << "Subject: " << subject << endl;
    cout << "Creator: " << creator << endl;
    dateThr->PrintDate();

    if (myPosts)
        myPosts->PrintAllPosts();
}


Thread::~Thread()                                                                   //destructor
{
    cout << "Thread with subject: " << subject << " is about to be destroyed.\n";
    cout << endl;

    subject.erase();
    creator.erase();
    delete dateThr;
}


string &Thread::getSubject()
{
    return subject;
}


void Thread::setSubject(const string &subject)
{
    Thread::subject = subject;
}


PostList *Thread::getMyPosts()
{
    return myPosts;
}
