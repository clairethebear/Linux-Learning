#include "apue.3e/include/apue.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";


int create_file_with_holes() {
    int fd;
    int destination_fd;

    //Create a file called file.hole
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
        printf("creat error");

    //Write buf1 to the file
    if (write(fd, buf1, 10) != 10)
        printf("buf1 write error");
    /* offset now = 10 */

    //Write the file holes into the file
    if (lseek(fd, 100, SEEK_SET) == -1)
        printf("lseek error");
    /* offset now = 16384 */

    //Write buf2 to the end of the file
    if (write(fd, buf2, 10) != 10)
        printf("buf2 write error");
    /* offset now = 16394 */

}

enum {SUCCESS, FAIL, MAX_LENGTH = 1 };

int error_msg(char *filename) 

{
	printf("An error occurred with %s.\n", filename);
	return FAIL;
}


int main(void)
{
  FILE *file_ptr1, *file_ptr2;
  char filename1[] = "review_backup.txt";
  char filename2[] = "file.hole";
  int result = SUCCESS;
  
  //Create  a file with foles called file.hole
  create_file_with_holes();

  if ( (file_ptr1 = fopen(filename1, "w")) == NULL ) 

  {
    result = error_msg(filename1);
  }
  else 

  {
    if ( (file_ptr2 = fopen(filename2, "r")) == NULL ) 

    {
      result = error_msg(filename2);
    }
    else 

    {
      int num;
      char buffer[MAX_LENGTH + 1];
      char* str = "\0";
      while(!feof(file_ptr2)) 
      {
        num = fread(buffer,sizeof(char), MAX_LENGTH, file_ptr2);
        buffer[num*sizeof(char)] = '\0';
        printf("%s.",buffer);

	int i=0;
	while (i<1)
	{
        	if( buffer[i] == *str )
			printf("\n Equal \n");
		else
        		if (fwrite(buffer, sizeof(char), num, file_ptr1)!=num) 
        		{
          			result = error_msg(filename1);
          			break;
        		}
	++i;
	}//end of nested while
      } //end of while
/*      printf("\n");
      if (fclose(file_ptr2)!=0) {
        result = error_msg(filename2);
      }*/
    }
    if (fclose(file_ptr1)!=0) {
      result = error_msg(filename1);
    }
  }
  return result;

}

