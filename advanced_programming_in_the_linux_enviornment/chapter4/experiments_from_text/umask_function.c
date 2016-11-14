#include "apue.3e/include/apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int
main(void)
{
    umask(0);
    //Create a file called foo with read,write permissions for user, group and other.
    if (creat("foo", RWRWRW) < 0)
        printf("creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    //Create a file called bar with read,write permissions for user, group and other.
    if (creat("bar", RWRWRW) < 0)
        printf("creat error for bar");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    exit(0);
}

