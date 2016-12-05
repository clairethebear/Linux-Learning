#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int globvar = 6;

int main(void)
{
  int var;
  int status;
  pid_t pid;

  var = 88;
  printf("before fork\n");
  if ((pid = vfork()) <0) {
    printf("vfork error\n");
    return -1;
  } else if (pid ==0) {
    globvar++;
    var++;
    //Exit does not perform any flushing of the I/O buffer
    //_exit(0);
    exit(0);
  }

  if (wait(&status) == pid) /* wait for first child */
  {
    printf("First child terminated");
    /* parent continues here */
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
  }
  exit(0);
}//end main
