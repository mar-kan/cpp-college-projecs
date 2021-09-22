#include "clone_encrypt_and_print.h"

void clone_encrypt_and_print(Object * obj)
{
    Object * clone = obj->Clone();
    String cl(obj->toString());
    clone = &cl;       // clone to string

    String o = cl;      //object to string done like that so that obj destructor isnt called

    if (!o.Equal(clone))
      exit(-1);

    int i, r;
    for (i=0; i<5; i++)                     //change 5 letters in random positions in cl
    {
        r = rand()% cl.Length();
        cl.UpdateAt(r, 'a');
    }
    cout << o.getStr() << endl;
    cout << cl.getStr() << endl;

    cl.Concat(o.getTString());
    cout << "Length is " << cl.Length() << endl;

    cout << cl.At(cl.Length()/2) << endl;

    cl.clearStr();
    cout << "Length is " << cl.Length() << endl;
}