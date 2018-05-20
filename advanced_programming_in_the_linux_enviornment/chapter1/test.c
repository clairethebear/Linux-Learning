#include "apue.3e/include/apue.h"

int main(void)
{
	int 	c;
	while ((c = getc(stdin)) != EOF)
		printf("This is working");

	printf("This is working");
}
