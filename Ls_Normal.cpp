//
// Created by itcast on 17-11-27.
//

#include "Ls_Normal.h"

void Ls_Normal::list_dir()
{
    DIR *dir = opendir(".");
    struct dirent *file;
    struct stat sb;
    while(NULL != (file = readdir(dir)))
    {
        stat(file->d_name, &sb);
        list_file(sb, file->d_name);
    }
}