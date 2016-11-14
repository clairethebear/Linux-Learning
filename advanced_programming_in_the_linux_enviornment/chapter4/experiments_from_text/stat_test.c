#include <stdio.h>
#include <sys/stat.h>


int main(){

	int result_from_stat;
	int result_from_fstat;
	int result_from_lstat;
	struct stat s;


	//print the stat structure
	printf("Printing file size from stat struct %d", s.st_size);
	int stat(const char *restrict pathname, struct stat *restrict buf);
	printf("This is the result from stat %d", result_from_stat);

	int fstat(int filedes, struct stat *buf);

	int lstat(const char *restrict pathname, struct stat *restrict buf);
}
