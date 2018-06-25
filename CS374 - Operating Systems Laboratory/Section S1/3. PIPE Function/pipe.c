#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int g = 20;
int main()
{
	int l = 10,fd[2],num;
	char buf[10];
	if(pipe(fd) == -1)
	{
		perror("Pipe failure");
		exit(1);
	}
	printf("\nWriting to file descriptor in main : Test\n");
	write(fd[1],"Test",4);
	pid_t p = fork();
	
	if(p > 0)
	{		
		waitpid(p,0,0);
		
		printf("\nIn parent, Value of global variable g : %d ",g);
		printf("\nIn parent, Value of local variable l : %d ",l);
		num = read(fd[0],buf,4);
		buf[num] = '\0';
		printf("\nReading in parent process : %s\n",buf);
	}
	else if ( p==0 )
	{
		g = 25;
		l = 15;
		char buf1[10];
		printf("\nWriting to file descriptor in child : Task\n");
		write(fd[1],"Task",4);
		printf("\nIn child,Value of global variable g : %d",g);
		printf("\nIn child,Value of local variable l : %d \n",l);
		//num = read(fd[0],buf1,4);
		//buf1[num] = '\0';
		//printf("\nReading in child process : %s\n",buf1);
		
	}
	close(fd[0]);
	close(fd[1]);
	return 0;
}
