#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char** argv)
{
	struct passwd *pwdline;
	pwdline = getpwuid(atoi(argv[1]));
	puts(pwdline->pw_name);
	exit(0);
}