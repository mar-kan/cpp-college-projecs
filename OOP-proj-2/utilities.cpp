#include "utilities.h"


string generateRandomName() //returns a random string
{
    string str("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    random_device rd;   //create generator
    mt19937 generator(rd());

    shuffle(str.begin(), str.end(), generator); //shuffle string's letters

    return str.substr(0, 15);   //returns first 15 letters of string
}