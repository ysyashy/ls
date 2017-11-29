#ifndef LS_LS_H
#define LS_LS_H

#include <iostream>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>


class Ls
{
protected:
    char file_name[1024];
    char *file_mod(__mode_t f_mode);
    char *time2str(__time_t );
    char *real_name(char *full_name);
    void list_file(struct stat sb, char *name)
    {
        printf("%s %3d %5s %5s %8d %s %s\n",
               file_mod(sb.st_mode), sb.st_nlink, getpwuid(sb.st_uid)->pw_name, getgrgid(sb.st_gid)->gr_name,
               sb.st_size, time2str(sb.st_mtim.tv_sec), name);
    }
    virtual void list_dir() = 0;
public:
    Ls(char *);
    void ls();
    virtual ~Ls(){}
};
/*
struct stat {
    dev_t     st_dev;         *//* ID of device containing file *//*
    ino_t     st_ino;         *//* inode number *//*
    mode_t    st_mode;        *//* protection *//*
    nlink_t   st_nlink;       *//* number of hard links *//*
    uid_t     st_uid;         *//* user ID of owner *//*
    gid_t     st_gid;         *//* group ID of owner *//*
    dev_t     st_rdev;        *//* device ID (if special file) *//*
    off_t     st_size;        *//* total size, in bytes *//*
    blksize_t st_blksize;     *//* blocksize for filesystem I/O *//*
    blkcnt_t  st_blocks;      *//* number of 512B blocks allocated *//*

    *//* Since Linux 2.6, the kernel supports nanosecond
       precision for the following timestamp fields.
       For the details before Linux 2.6, see NOTES. *//*

    struct timespec st_atim;  *//* time of last access *//*
    struct timespec st_mtim;  *//* time of last modification *//*
    struct timespec st_ctim;  *//* time of last status change *//*

#define st_atime st_atim.tv_sec      *//* Backward compatibility *//*
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};*/
#endif
