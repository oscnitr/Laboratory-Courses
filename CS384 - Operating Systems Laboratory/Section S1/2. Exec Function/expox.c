#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void main(int argv,const char* arg[])
{
	int t;
	double x = atof(arg[1]);
	double n = atof(arg[2]);
	pid_t p = fork();
	if(p == 0)
	{
		t = getpid();
		printf("Child(PID = %d) \n",t);
		execl("/home/administrator/115CS0228/expoxch","./expoxch",arg[1],arg[2],NULL);


	}
	else
	{
		waitpid(p,0,0);
		printf("Parent(PID = %d) : done\n",getpid());
	}

}
