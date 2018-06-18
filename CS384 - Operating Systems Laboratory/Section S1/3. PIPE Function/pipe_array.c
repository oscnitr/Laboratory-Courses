#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int j=0;
void main()
{
	int A[15],base,i,k,l,n,fd[2],num,x;
	pid_t p;
	if (pipe(fd) == -1 ) //PIPE
	{
		perror("Pipe failure");
		exit(1);
	}
	printf("\nEnter the no. of process chain : ");
	scanf("%d",&n);
	printf("\nEnter the base number : ");
	scanf("%d",&base);
	for (i=0;i<n;i++)
	{
		p = fork();
		if ( p == 0 )	
		{
			if( i == 0)
			{
				A[i] = base;	
			
				base++;
				
				printf("\nArray content : \n");
				for(k=0;k<=i;k++)
				{
					printf("%d\t",A[k]);
				}
				printf("\n");
				write(fd[1],&base,4);
				printf("\n%d.Writing to PIPE : %d\n",i+1,base);
			}
			else
			{
				num = read(fd[0],&x,4);
				printf("\nReading : %d\n",num);
				A[i] = x;
				//j++;
				x++;
				printf("\nArray content : \n");
				for(l=0;l<=i;l++)
				{
					printf("%d\t",A[l]);
				}
				printf("\n");
				write(fd[1],&x,4);
				printf("\n%d.Writing to PIPE : %d\n",i+1,x);
			}
			
		}
		else
		{
			waitpid(p,0,0);	
			
			break;
			
		}
	}
	
	

}
