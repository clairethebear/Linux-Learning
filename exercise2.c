#include "apue.3e/include/apue.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>


int mydup2(int oldfd, int newfd);

int
main(int argc, char *argv[]) {
	/* declare the file descriptors */
	int fd1, fd2;

	/* check if the number of arguements is not equal to 2 */
	if (argc != 2){
		printf("Usage: %s file", argv[0]);
		close(0);
	}
	/* Check that the file can be opened */
	if ((fd1 = open(argv[1], O_RDONLY)) < 0) 
	{
        	printf("\nCan't open file `%s`", argv[1]);
		close(0);
    	}
	printf("\nThis is what a file descriptor 1 looks like %d", fd1);
	fd2 = mydup2(fd1, 42);
	printf("\nThis test is a file from command line %s", argv[1]);
}


int mydup2(int oldfd, int newfd)
{
	struct stat s;
 	printf("\nLooking at fd1 %d and fd2 %d", oldfd, newfd);	
	// Check if oldfd is a valid descriptor, fail if it's not.
    	if (fstat(oldfd, &s) < 0) {
		printf("making it inside the fstat statement");
        	return -1;
   	}

	/* find number of limited files allowed on the system and make sure the new file descriptor
	doesnt exceed this */


/*	int openmax = sysconf(_SC_OPEN_MAX);
	printf("\nThis is openmax %d", openmax);
	if (newfd < 0 || newfd > openmax) {
        	errno = EBADF;
        	return -1;
    	}
*/
	// If oldfd == newfd just return newfd.
    	if (oldfd == newfd) {
		printf("\nReturning duplicate fd %d", newfd);
		return newfd;
    	}
	// If newfd is open, close it.
    	if (fstat(newfd, &s) == 0) {
        	close(newfd);
    	}

	printf("making to before declaration");
	int to_close_ptr;
    	int *to_close = malloc(sizeof(int) * newfd);
	int current_try;
    	int i;

	while(1){
		//result of dup will return the result of the file descriptor that dup has found as a replacement. Populate the int valu current_try and see if this matches that fd2 value that we want.
		if ((current_try = dup(oldfd)) <0) {
			printf("duplication failed");
			close(0);
		}
		//check if the current_try matches the file descriptor that you specified in the function
		if (current_try == newfd){
			printf("This has made a match the fd2");
			for(i=0; i < to_close_ptr; ++i)	close(to_close[i]);
				// Free up the taken file descriptors
				printf("\nfree up memory taken by file descriptors");
				free(to_close);
				return newfd;
		} else {
			//add the current file descriptors to close to the array
			to_close[to_close_ptr++] = current_try;
			printf("\ncurrent_try %d", current_try);
		}
			
	}// end while loop
}

