#include "apue.3e/include/apue.h"
#include <fcntl.h>

int
main(void)
{
    //Create the file tempfile with read, write permissions
    if (open("tempfile", O_RDWR) < 0)
        printf("open error");
    //Try to unlink the file (remove the symlinks) for deletion
    if (unlink("tempfile") < 0)
        printf("unlink error");
    printf("file unlinked\n");
    sleep(15);
    printf("done\n");
    exit(0);
}

