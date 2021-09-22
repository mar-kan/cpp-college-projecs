#ifndef THREAD_H
#define THREAD_H

#include <string>
#include "Date.h"
#include "PostList.h"
using namespace std;

class PostList;

class Thread {

    string subject;
    string creator;
    Date * dateThr;
    PostList * myPosts;


public:
    Thread();
    void PrintThreadData();
    virtual ~Thread();

    string &getSubject();
    void setSubject(const string &subject);
    PostList * getMyPosts();
};


#endif
