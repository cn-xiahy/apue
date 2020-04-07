#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFSIZE 1024

int main(int argc ,char**argv)
{
	if(argc < 2)
	{
		printf("usage..");
		exit(1);
	}
	FILE* fd;
	char buf[BUFSIZE];
	time_t rettime;
	time_t tloc;
	struct tm *tm;
	int count=0;
	fd = fopen(argv[1],"a+");
	while(fgets(buf,BUFSIZE,fd)!=NULL)
		count++;
	while(1)
	{
	rettime = time(&tloc);
    tm = localtime(&rettime);
	fprintf(fd,"%-4d%d-%d-%d %d:%d:%d\n",++count,\
		tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,\
		tm->tm_hour,tm->tm_min,tm->tm_sec);
		fflush(fd);
		sleep(1);
	}
	fclose(fd);
	
}