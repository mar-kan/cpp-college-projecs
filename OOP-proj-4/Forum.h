#ifndef FORUM_H
#define FORUM_H

#include <string>
#include "ThreadList.h"
using namespace std;


class Forum {

    string title;
    ThreadList * myThreads;                     //points to list Thread

public:
    Forum(string);
    void CreateThreads();
    void PrintForum();
    void PrintOneThread(string);
    void PrintRandomPosts();
    void PrintPosts();
    virtual ~Forum();

    ThreadList *getMyThreads();
};


#endif
