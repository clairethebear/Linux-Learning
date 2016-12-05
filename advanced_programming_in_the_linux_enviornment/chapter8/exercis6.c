#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
  int status;
  pid_t pid;

  /* Create a zombie process */
  if((pid = fork()) < 0) {
    printf("Fork error");
  } else if (pid == 0) {
    exit(0);
  }

  if ((status = system("date")) < 0)
    printf("system error");

  /* Check the process */
  if ((status = system("ps aux | grep \'Z\'")) < 0)
    printf("System error");

  exit(0);

}


int system(const char *cmdstring){
  pid_t pid;
  int status;


  if(cmdstring == NULL)
    return(1);

  if((pid = fork()) <0) {
    status = -1;
  } else if (pid == 0) {
      execl("/bin/sh", "sh", "-c", cmdstring, NULL);
      _exit(127);
  } else {
      while (waitpid(pid, &status, 0) < 0) {
        if ( errno != EINTR) {
          status = -1;
          break;
        }
     }
   }
  return(status);
}
