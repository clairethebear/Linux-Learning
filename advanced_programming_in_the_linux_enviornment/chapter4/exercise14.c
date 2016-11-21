#include "apue.3e/include/apue.h"
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int
main() {
  char cwd[256];
  int i = 0;
  char* dir;
  char* new_dir;

  while(i < 4) {
    //Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL)
      perror("getcwd() error");
    else
      printf("current working directory is: %s\n", cwd);

    new_dir = (char*)malloc(strlen(dir) * sizeof(char));
    new_dir = strcat(cwd, "test");
    //Create a folder named text  
    if(mkdir(strcat(new_dir, "test"), 00777) != 0)
      printf("Folder creation did not work");

    //Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL)
      perror("getcwd() error");
    else
      printf("current working directory is: %s\n", cwd);

    //Change directory to new folder test
    chdir("test");

    //get new current working directory
    if (getcwd(cwd, sizeof(cwd)) == NULL)
      perror("getcwd() error");
    else
      printf("current working directory after chdir is: %s\n", cwd);
    printf("\n Current size of the directory tree is %d \n", sizeof(cwd));
    
    ++i;
  }//end while loop

  return 0;
}


