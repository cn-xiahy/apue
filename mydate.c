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
 extern char *optarg;
int main(int argc ,char**argv)
{
	if(argc < 2)
	{
		printf("usage..");
		exit(1);
	}
	char buf[BUFSIZE];
	char fmtstr[BUFSIZE];
	fmtstr[0]='\0';
	time_t rettime;
	time_t tloc;
	struct tm *tm;
	int opt;
	rettime = time(&tloc);
    tm = localtime(&rettime);
	while((opt=getopt(argc,argv,"y:mdH:MS"))!=-1)
		switch(opt)
		{
			case 'H':
			if(strcmp(optarg,"12") == 0)
			 strncat(fmtstr,"%I(%P) ",BUFSIZE);
			else if(strcmp(optarg,"24") == 0)
				strncat(fmtstr,"%H ",BUFSIZE);
			break;
			case 'y':
			if(strcmp(optarg,"ct"))
			 strncat(fmtstr,"%y",BUFSIZE);
			else if(strcmp(optarg,"nct"))
				 strncat(fmtstr,"%Y",BUFSIZE);
			break;
		}
	
	
	strftime(buf,BUFSIZE,fmtstr,tm);
	puts(buf);

	
}