#include "apue.3e/include/apue.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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