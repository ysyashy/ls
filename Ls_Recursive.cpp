//
// Created by itcast on 17-11-27.
//

#include "Ls_Recursive.h"


void Ls_Recursive::list_dir()
{
    printf(">> %s\n", get_current_dir_name());
    //printf("list_dir() is called.\n");
    DIR *dir = opendir(".");
    struct dirent *file;
    struct stat sb;
    while(NULL != (file = readdir(dir)))
    {
        if(DT_DIR == file->d_type)
        {
            if(strcmp(file->d_name, ".")==0 || strcmp(file->d_name, "..")==0)
                continue;
            chdir(file->d_name);
            list_dir();
            chdir("..");
        }
        else
        {
            stat(file->d_name, &sb);
            list_file(sb, file->d_name);
        }
    }

}