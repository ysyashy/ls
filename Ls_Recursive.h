#ifndef LS_LS_RECURSIVE_H
#define LS_LS_RECURSIVE_H
#include "ls.h"

class Ls_Recursive : public Ls
{
protected:
    virtual void list_dir();
public:
    Ls_Recursive(char *path) : Ls(path)
    {

    }
    ~Ls_Recursive(){}
};


#endif //LS_LS_RECURSIVE_H
