//Kanellaki Maria Anna - 1115201400060


#include <string>
#include <iostream>
#include "Forum.h"
#include "PrintSorted.h"
using namespace std;

int main()
{
    srand(time(0));

    Forum *forum = new Forum("Αντικειμενοστραφής Προγραμματισμός");                         //create forum

    forum->CreateThreads();                                                                 //create threads in forum

    //forum->PrintForum();                                                                    //prints all forum's threads

    //forum->PrintOneThread("Κανόνες και χρήσιμες πληροφορίες");

    //forum->PrintRandomPosts();                                                              //print random posts

    PrintSorted(forum);

    delete (forum);                                                                         //delete everything
    return 0;
}

