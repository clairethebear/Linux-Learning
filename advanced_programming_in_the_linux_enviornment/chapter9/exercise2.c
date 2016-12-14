#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  FILE *fp;
  char c;
  int status;
  pid_t pid;
  pid_t session_id;

  if((pid = fork()) < 0) {
    printf("Fork error");
  } else if (pid == 0) {
    /* Set a new session */
    setsid();
  } else {
    exit(0);
  }

  printf("\n This is the child ID: %d \n", getpid());
  printf("\n This is the getpid (parent): %d \n", getppid());

  /*printf("\n This is getppid (child): %d",getppid()); */
  /* get the process group leader */
  session_id = getpgid(getpid());
  printf("\n This is the process group leader of process %d: %d \n", getpid(), session_id);

  char result = read(STDIN_FILENO, &c, 1);
  printf("%d\n\n", result);

  // Try to read to STDIN - this should 
  if(read(STDIN_FILENO, &c, 1) != 1){
      printf("\nread on controlling TTY\n");
      //fp = fopen("/tmp/test_controlling_terminal.txt", "w+");
      fprintf(fp, "Testing controlling terminal didnt work on STDIO\n");
      fclose(fp);
  }
  exit(0);

}
