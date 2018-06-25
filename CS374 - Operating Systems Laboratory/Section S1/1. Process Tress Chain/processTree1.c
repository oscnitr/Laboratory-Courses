#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int depth = 1;
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
	p = fork();
	if ( d == 1 && p == 0)
	{	printf("I am the 1st process with PID : %d \n" ,getpid());
		exit(0);
	}	
	//for (i =0 ;i<n;i++)
	{

		if (p == 0)
		{
			depth++;
			printf("\nI am a 1st process.My PID : %d. My parent PID %d\n",getpid(),getppid());
			
			for (j=0;j<n;j++)
			{	
				q = fork();
				if ( q == 0)
				{
					printf("\nI am a child process. My PID : %d\t Parent's PID : %d \n",getpid(),getppid());	
					if (depth<d)
					{
						j = -1;	
						depth+=1;
					}
					else
						break;
				}
				else
				{	
					waitpid(q,0,0);				
				}
			}
			//break;	
		}
		else
		{
			waitpid(p,0,0);	
			//p = fork();
			//break;
		
		}

		

	}
	
}
