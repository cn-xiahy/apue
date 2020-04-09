#include <stdio.h>
#include <stdlib.h>
void f1(void)
{
	puts("f1begin");
}

void f2(void)
{
	puts("f2begin");
}

void f3(void)
{
	puts("f3begin");
}


int main()
{
	puts("begin");
	atexit(f1);
	atexit(f2);
	atexit(f3);
	puts("stop");
	exit(0);
}