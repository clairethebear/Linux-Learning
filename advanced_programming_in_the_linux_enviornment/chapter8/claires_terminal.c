#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


int process_command(char* line);
int execute_command(char* tokens_buffer[]);

int main(void) {
 
  char *line = NULL;
  size_t linecap = 0;
  ssize_t linelen;
  printf("Welcome to Claires Shell\n$ ");
  while ((linelen = getline(&line, &linecap, stdin)) > 0){
    if(line[linelen-1] == '\n'){
      line[linelen-1] = '\0';
    }
    if(process_command(line) != 0){
      printf("Error with function process command\n");
    }
    printf("$ "); 
  }
  return 0;
}

char* tokens_buffer[1024];

int process_command(char* line){
  char *p = strtok (line, " ");
  int i = 0;
  while(p != NULL){
    tokens_buffer[i] = p;
    ++i;
    p = strtok (NULL, " ");
  }
  tokens_buffer[i] = NULL;
  return execute_command(tokens_buffer);
}

int execute_command(char* tokens_buffer[]){
  pid_t pid;
  
  pid = fork();
  if(pid < 0){
    return -1;
  } 
  if (pid == 0){
    execvp(tokens_buffer[0], tokens_buffer);
    printf("Exec failed\n");
    return -1;
  }
  waitpid(pid, NULL, 0); 
  return 0;
}
