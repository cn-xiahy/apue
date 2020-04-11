#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *envpath;
	envpath = getenv("PATH");
	puts(envpath);
}