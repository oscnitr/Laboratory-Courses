#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
	int fd[2],num;
	char buf[10];
	pid_t p,p1;
	if (pipe(fd) == -1 ) //PIPE
	{
		perror("Pipe failure");
		exit(1);
	}
	p = fork(); //1st child
	
	if(p == 0)
	{	
		//printf("\nIn 1st  child\n");
		//close(1);
		dup2(fd[1],1);
		//printf("\nAfter dup\n");
		execl("/bin/ls","ls","-l",NULL);
	}
	
	else if (p > 0)
	{
		waitpid(p,0,0);
		close(fd[1]);
		//num = read(fd[0],buf,9);
		//buf[num] = '\0';
		//puts(buf);
		p1 = fork(); //2nd child
		if ( p1 > 0 )
		{
			waitpid(p1,0,0);
		}
		else if(p1 == 0)	//INside 2nd
		{	
			dup2(fd[0],0);
			close(fd[1]);
			printf("\nExecuting exec for wc command\n");
			execlp("wc","wc","-l",NULL);
		
		}
		else
		{
			printf("\n2nd child creation failed");
			exit(1);
		}	
	
	}
	else
	{
		printf("\n1st child creation failed");
		exit(1);
	}

}
