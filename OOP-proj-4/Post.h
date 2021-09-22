#ifndef POST_H
#define POST_H

#include <string>
#include "Date.h"
#include "PostList.h"
using namespace std;
class PostList;


class Post {

    int id;
    string title;
    string creator;
    Date * date;
    string text;

public:
    Post(PostList*);
    void PrintPostData();
    virtual ~Post();
    int getId();

    const string &getCreator();
};


#endif
