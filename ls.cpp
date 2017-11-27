#include <unistd.h>
#include "ls.h"

Ls::Ls(char *fileName)
{
    memset(file_name, 0, 1024);
    strcpy(file_name, fileName);
}
void Ls::ls()
{
    struct stat sb;
    memset(&sb, 0, sizeof(struct stat));
    if(-1 == stat(file_name, &sb))
    {
        perror("Error");
        exit(-1);
    }



    if(S_ISDIR(sb.st_mode))     /*是目录*/
    {
        //read_dir();
        if (-1 == chdir(file_name))
        {
            perror("chdir error in ls");
            exit(-1);
        }
        this->list_dir();
    }
    else        /*是普通文件*/
    {
        // -rw-rw-r-- 1 itcast itcast 25138 2017-11-27 09:42 stat.txt
        list_file(sb, strrchr(file_name, '/')+1);
    }
}



char * Ls::file_mod(__mode_t f_mode)
{
    /*
     * drwxrwxrwx
     * 12   0 0 0 0     八进制
     * type s u g o
     */
    char *ret = new char[11];
    memset(ret, '-', 10);   ret[10] = '\0';
    if(S_ISDIR(f_mode)) ret[0] = 'd';
    if(S_ISLNK(f_mode)) ret[0] = 'l';
    if(S_ISCHR(f_mode)) ret[0] = 'c';
    if(S_ISBLK(f_mode)) ret[0] = 'b';
    if(S_ISFIFO(f_mode))    ret[0] = 'p';

    if(S_IRUSR & f_mode)    ret[1] = 'r';
    if(S_IWUSR & f_mode)    ret[2] = 'w';
    if(S_IXUSR & f_mode)    ret[3] = 'x';

    if(S_IRGRP & f_mode)    ret[4] = 'r';
    if(S_IWGRP & f_mode)    ret[5] = 'w';
    if(S_IXGRP & f_mode)    ret[6] = 'x';

    if(S_IROTH & f_mode)    ret[7] = 'r';
    if(S_IWOTH & f_mode)    ret[8] = 'w';
    if(S_IXOTH & f_mode)    ret[9] = 'x';

    if(S_ISUID & f_mode) ret[3] = 'S';
    if(S_ISGID & f_mode) ret[6] = 'S';
    if(S_ISVTX & f_mode) ret[9] = 'T';
    return ret;
}

char *Ls::time2str(__time_t tim)
{
    // 0000-00-00 00:00
    char *ret = new char[32];
    memset(ret, 0, 32);

    struct tm * i_tm = localtime(&tim);
    sprintf(ret, "%04d-%02d-%02d %02d:%02d",
        1900+i_tm->tm_year, 1+i_tm->tm_mon, i_tm->tm_mday,
        1+i_tm->tm_hour, i_tm->tm_min);

    return ret;
}

char *Ls::real_name(char *full_name)
{
    char *ret = new char[1024];
    memset(ret, 0, 1024);

    int len = strlen(full_name);
    if(1 == len)
    {
        delete[] ret;
        return full_name;
    }
    else
    {
        int a = 1;
    }
    return ret;
}

