//
// Created by itcast on 17-11-27.
//

#ifndef LS_LS_NORMAL_H
#define LS_LS_NORMAL_H


#include "ls.h"

class Ls_Normal : public Ls
{
protected:
    virtual void list_dir();
public:
    Ls_Normal(char *path) : Ls(path)
    {
    }
    virtual ~Ls_Normal(){}
};


#endif //LS_LS_NORMAL_H
