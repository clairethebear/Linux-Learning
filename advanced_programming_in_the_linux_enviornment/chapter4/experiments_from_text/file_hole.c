#include <stdbool.h> 
#define _GNU_SOURCE // Linux
#include "apue.3e/include/apue.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";
bool is_all_zeros(char *buffer, size_t len);

int
main(void)
{
    int fd;
    int destination_fd;


    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        printf("creat error");

    if (write(fd, buf1, 10) != 10)
        printf("buf1 write error");
    /* offset now = 10 */

    if (lseek(fd, 100, SEEK_SET) == -1)
        printf("lseek error");
    /* offset now = 16384 */

    if (write(fd, buf2, 10) != 10)
        printf("buf2 write error");
    /* offset now = 16394 */

    FILE *fptr;
    char * buffer = 0;
    long length;
    int size;
    off_t file_end, hole_start, hole_end;


    // Figure out block size of the target file.
    struct stat st;
    fstat(fd, &st);
    size_t buffer_size = st.st_blksize;
    
    // Make a buffer of that size.
    char *buffer_for_size;
    if ((buffer_for_size = malloc(sizeof(char) * buffer_size)) == NULL) {
        printf("Cannot allocate a buffer");
    }


    if ((destination_fd = creat("_COPY_OF_file.hole", FILE_MODE)) < 0)
       printf("creat error");


    size_t nread;
/*    do {
        ssize_t m = 0;
        nread = 0;
        // Read a block (or less).
        do {
            m = read(fd, buffer_for_size + nread, buffer_size - nread);
            nread += m;
        } while (nread < buffer_size && m != 0);
 
        // If it's a full block with zeros..
        if (nread == buffer_size && is_all_zeros(buffer, nread)) {
            // ..lseek past it.
            lseek(destination_fd, nread, SEEK_CUR);
        } else {
            // Write buffer to the target file.
            size_t nwritten = 0;
            while (nwritten < nread) {
                m = write(destination_fd, buffer + nwritten, nread - nwritten);
                nwritten += m;
            }
        }
    } while (read >0);
*/
    
    hole_start = lseek(fd, 0, SEEK_HOLE);
    hole_end = lseek(fd, 0, SEEK_DATA);
    file_end = lseek(fd, 0, SEEK_END);    
    printf("Hole from Hole start %lld to Hole End %lld to File end %lld\n",
                    (long long)hole_start, (long long) hole_end, (long long)file_end);


    if ((fptr = fopen("file.hole", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }

    if (fptr)
    {
	//Seek to the end of the file and return the position of the offset
        fseek (fptr, 0, SEEK_END);
  	//Store the length of the file pointer
        length = ftell (fptr);
        fseek (fptr, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer)
        {
            fread (buffer, 1, length, fptr);
        }   
        fclose (fptr);
    }
    printf("This is a buffer %s", buffer);
    size = strlen(buffer);

/*
    if ((fd = creat("_COPY_OF_file.hole", FILE_MODE)) < 0)
       printf("creat error");
    if (write(fd, buffer, 10) != 10)
        printf("buf1 write error");
*/

    exit(0);
}


bool is_all_zeros(char *buffer, size_t len) {
/*    for (int i = 0; i < len; ++i) {
        if (buffer[i] != '\0') {
            return false;
        }
    }
    return true;
*/}

