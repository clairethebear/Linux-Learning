#include "apue.h"

int
main(void)
{
	printf("Hello worlds from process ID %ld\n", (long)getpid());
	exit(0);
}
