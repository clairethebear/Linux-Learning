#include "apue.3e/include/apue.h"

#define BUFFSIZE 4096

void err_sys(const char* x) 
{ 
    perror(x); 
    exit(1); 
}


int
main(void)
{
	int	n;
	char 	buf[BUFFSIZE];
	
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			err_sys("write_error");
	
	if (n < 0)
		err_sys("read error");
	exit(0);

}



