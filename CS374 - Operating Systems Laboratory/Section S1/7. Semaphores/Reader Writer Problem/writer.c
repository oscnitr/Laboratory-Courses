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
	printf("\nWaiting for readers...\n");
	
	while(1)
	{

		fd = open(FIFO_NAME,O_WRONLY);
		//printf("\nGot a reader. Enter some stuff - \nWRITER : ");
		printf("WRITER : ");
		gets(s);
		if((num = write(fd,s,strlen(s))) == -1)
			perror("writing error");
		//else
			//printf("\nWriter wrote %d bytes\n",num);
		if(strcmp(s, "BYE") == 0)
			exit(0);			
	
		//close(fd);

	}
	close(fd);
	printf("\nAfter while loop\n");
	return 0;
}
