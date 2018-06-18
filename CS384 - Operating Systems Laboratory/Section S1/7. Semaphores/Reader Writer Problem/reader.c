#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#define FIFO_NAME "myfile1.txt"

int main(void)
{
	char s[300];
	int num,fd;
	mkfifo(FIFO_NAME,0666);
	printf("\nWaiting for writers...\n");

	while(1)	
	{
		fd = open(FIFO_NAME,O_RDONLY);
		//printf("\nGot a writer\n");
		if ((num = read(fd,s,300)) == -1)
			perror("reading failure");
		
		else
		{	
			
			s[num] = '\0';
			printf("Reader read %d bytes : %s \n",num,s);
		}
		if ( strcmp(s,"BYE") == 0 )
			exit(0);
		close(fd);
	}
	
	return 0;
}
