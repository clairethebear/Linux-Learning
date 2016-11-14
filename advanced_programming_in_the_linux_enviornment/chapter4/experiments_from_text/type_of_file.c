#include "apue.3e/include/apue.h"

int
main(int argc, char *argv[])
{

    int         i;
    struct stat buf;
    char        *ptr;

    //Loop over every arguement
    for (i = 1; i < argc; i++) {
	//Print the arguement we are looking at
        printf("%s: ", argv[i]);


	printf("Printing the state of stat BEFORE it has been populated with lstat %d", buf);
	//Check if there are any errors when looking at the 
	//non symbolic file.
	//The reason for using lstat instead of just stat was for
	//detection of symbolic links.
        if (lstat(argv[i], &buf) < 0) {
            printf("lstat error");
            continue;

         }
	 printf("Printing the state of stat after it has been populated with lstat %d", buf);
	 //If the file is a regulat file
         if (S_ISREG(buf.st_mode))
            ptr = "regular";
	 //If the file is a directory
         else if (S_ISDIR(buf.st_mode))
            ptr = "directory";
 	 //If its a special character file
         else if (S_ISCHR(buf.st_mode))
            ptr = "character special";
	 //If its a block special character
         else if (S_ISBLK(buf.st_mode))
            ptr = "block special";
	 //If its a FIFO file
         else if (S_ISFIFO(buf.st_mode))
            ptr = "fifo";
 	 //If its a symbolic link
         else if (S_ISLNK(buf.st_mode))
            ptr = "symbolic link";
	 //If its a socket file
         else if (S_ISSOCK(buf.st_mode))
            ptr = "socket";
         //If its a unknown file
	 else
            ptr = "** unknown mode **";
         printf("%s\n", ptr);
  }
   exit(0);
}
