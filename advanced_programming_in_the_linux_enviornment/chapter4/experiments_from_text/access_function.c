#include "apue.3e/include/apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    //If the arguement is not equal to 2 then send an error
    //This is done so that the interpreter only takes in a number of defined arguements from command line and we are able to deal with them.
    //IE: not take in 6 when we only want 2 arguments
    if (argc != 2)
        printf("\nusage: a.out <pathname>");
    //Check if you have read permission
    if (access(argv[1], R_OK) < 0)
        printf("\naccess error for %s", argv[1]);
    else
        printf("\nread access OK\n");
    //Check if you are able to open the file with read only
    if (open(argv[1], O_RDONLY) < 0)
        printf("\nopen error for %s", argv[1]);
    else
        printf("\nopen for reading OK\n");
    exit(0);
}


