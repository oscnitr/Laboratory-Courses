#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#define FIFO_NAME1 "myfile7.txt"
#define FIFO_NAME2 "myfile8.txt"

int main(void)
{
	char s1[300],s2[300];
	int num1,num2,fd1,fd2;
	pid_t p;
	p = fork();
	if(p > 0)	//Parent to write to USER_2
	{
		mkfifo(FIFO_NAME1,0666);
		printf("\nWaiting for reader of USER_2...\n");	
		while(1)
		{

			fd1 = open(FIFO_NAME1,O_WRONLY);
			//printf("\nGot a reader. Enter some stuff - \nWRITER : ");
			printf("\nUSER_1 : \n");
			gets(s1);
			if((num1 = write(fd1,s1,strlen(s1))) == -1)
				perror("writing error");
			//else
				//printf("\nWriter wrote %d bytes\n",num);
			if(strcmp(s1, "BYE") == 0)
				break;			
	
			close(fd1);

		}
		close(fd1);
	waitpid(p,0,0);	
	}
	else if (p == 0)	//Child to read from USER_2
	{
		mkfifo(FIFO_NAME2,0666);
		//printf("\nWaiting for writer of USER_2...\n");

		while(1)	
		{
			fd2 = open(FIFO_NAME2,O_RDONLY);
			//printf("\nGot a writer\n");
			if ((num2 = read(fd2,s2,300)) == -1)
				perror("reading failure");
		
			else
			{	
			
				s2[num2] = '\0';
				printf("\nUSER_2 : %s \n",s2);
			}
			if ( strcmp(s2,"BYE") == 0 )
				exit(0);
			close(fd2);
		}
	}
}
