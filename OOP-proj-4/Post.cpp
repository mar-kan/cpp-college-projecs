#include <iostream>
#include <fstream>
#include "Post.h"
using namespace std;


Post::Post(PostList * postlist)                                                          //constructor of list of posts
{
    int i, j;

    id = postlist->getCount();
    date = new Date();

    fstream uFile, wFile;                                                                //insert data from files
    string filename, word;
    int randNum;

    for (i = 0; i <= 10; i++)
    {
        wFile.open(filename.c_str());

        for (j = 0; j < 500; j++)                                                        //500 lines of file words
        {
            filename = "words";
            wFile >> word;

            randNum = rand()%500 + 1;
            if (j == randNum)
            {
                title += " " + word;
                break;
            }
        }
        wFile.close();
    }

    for (i = 0; i <= 20; i++)
    {
        wFile.open(filename.c_str());

        randNum = rand()%500;
        for (j = 0; j <= 499; j++)                                                       //500 lines of file words
        {
            wFile >> word;
            if (j == randNum)
            {
                text += " " + word;
                break;
            }
        }
        wFile.close();
    }

    filename = "usernames";
    uFile.open(filename.c_str());

    randNum = rand()% 96 + 1;                                                            //97 lines of file usernames
    for (i = 0; i <= 96; i++)                                                            //get random line of file
    {
        uFile >> word;
        if (i == randNum)
        {
            creator = word;
            break;
        }
    }
    uFile.close();

    cout << "New post has just been created with: \n";
    PrintPostData();
}


void Post::PrintPostData()                                                               //print data of a post
{
    cout << "Post ID number: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Creator: " << creator << endl;
    date->PrintDate();
    cout << "Text: " << text << endl << endl;
}


Post::~Post()                                                                            //destructor
{
    cout << "Post number: " << id << " is about to be destroyed\n";
    delete date;
    creator.erase();
    title.erase();
    text.erase();
}


int Post::getId()                                                                        //getter for id
{
    return id;
}


const string &Post::getCreator()
{
    return creator;
}
