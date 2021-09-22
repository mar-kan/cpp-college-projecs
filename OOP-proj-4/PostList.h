#ifndef LIST_H
#define LIST_H


class Post;
class Tree;

class PostList                                          //doubly linked list that stores Post objects
{
    struct Node
    {
        Post * post;
        Node * next;
        Node * prev;
    };
    Node * head;                                        //pointer to first Post
    int count;

public:
    PostList();
    void InsertPost(Post *);
    bool PrintPost(int);
    void PrintAllPosts();
    virtual ~PostList();
    int getCount();

    void InsertToTree(Tree * tree);
};


#endif
