#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	printf("%dbegin\n",getpid());
	flush(NULL);//important
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		printf("child%dend\n",getpid());
	}
	else
	{
		sleep(1);
		printf("parent%dend\n",getpid());
	}
		printf("end\n");
	// getchar();
	
}