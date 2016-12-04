#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
  /*Create a child process */
  pid_t pid;
  int statloc;  

  pid = fork();
  if(pid < 0){
    printf("Fork error\n");
    exit(EXIT_FAILURE);
  }
  if(pid == 0){
    // child
    return(14);
  } else {
    // parent
    if(wait(&statloc)<0){
      printf("wait failure\n");
      exit(EXIT_FAILURE);
    }
    if(WIFEXITED(statloc)){
      printf("The WEXITSTATUS is: %d\n", WEXITSTATUS(statloc));
    }
  }

  return 0;
}
