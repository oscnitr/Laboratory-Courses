#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int depth = 0;
int main()
{
	int n,d;
	printf("\nEnter the value of n : ");
	scanf("%d",&n);
	printf("\nEnter the value of d : ");
	scanf("%d",&d);
	printf("\nPID of main process is %d\n",getpid());
	int i,j;
	pid_t p,q,r;
	
	for (i =0 ;i<n;i++)
	{
		printf("\nI am a 1st process.My PID : %d. My parent PID %d\n",getpid(),getppid());
		p = fork();
		if (p == 0)
		{
			
			printf("\nI am a child process. My PID : %d\t Parent's PID : %d \n",getpid(),getppid());	
			break;
		}
		else
		{	
			waitpid(q,0,0);		
		}
	}
		
		
		

	
}
