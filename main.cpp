#include <iostream>
#include "Ls_Normal.h"
#include "Ls_Recursive.h"

int main(int argc, char *argv[])
{
    bool isRecursive = false;
    char *path = new char[1024];
    Ls *ls = nullptr;

    memset(path, 0, 1024);

    char ch;
    while(-1 != (ch = getopt(argc, argv, "Rh")))
    {
        if(ch == 'R')
        {
            isRecursive = true;
            break;
        }
        if(ch == 'h')
        {
            printf("Usage: ./ls [file_name] -R\n");
            delete path;
            return 0;
        }
    }

    if((isRecursive && argc<3) || (!isRecursive && argc<2))
    {
        strcpy(path, ".");
    }
    else
    {
        strcpy(path, argv[1]);
    }

    if(isRecursive)
    {
        ls = new Ls_Recursive(path);
    }
    else
    {
        ls = new Ls_Normal(path);
    }
    ls->ls();
    delete ls;
    delete[] path;
    return 0;
}