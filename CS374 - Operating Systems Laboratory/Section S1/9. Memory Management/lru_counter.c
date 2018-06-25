#include<stdio.h>
#include<stdlib.h>

int i,j,k;
int str[20],m,n,frames[10][10];
int counter=0,pg_fault=0,flag = 0,index = 0,available = 0,min_counter = 999,min_index = -1,value =-1;

void lru_func()
{
	printf("\nPage \tFrame Status\t\tPage Fault\tVictim Page");
	while(counter<m)
	{
		printf("\n%d\t",str[counter]);		//Printing the page referenced

		flag = 0;
		for(i=0;i<n;i++)		//If page is present in frame
		{
			if(frames[i][0] == str[counter])
			{
				frames[i][1] = counter;
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			for(i=0;i<n;i++)
				printf("%d  ",frames[i][0]);
			printf("\t\t--\t\t--");
			counter++;
			continue;
			
		}
		available = 0;
		index = -1;
		for(i=0;i<n;i++)
		{
			if(frames[i][0] == -1)
			{
				available = 1;
				index = i;
				break;
			}
		}
		if( flag == 0 && available == 1 )	//If page is not present but frame is free
		{
			frames[index][0] = str[counter];
			frames[index][1] = counter;
			pg_fault++;
			for(i=0;i<n;i++)
				printf("%d  ",frames[i][0]);
			printf("\t\t%d\t\t--",pg_fault);
			counter++;
			continue;
		}
		else if(flag == 0 && available == 0 )	//If page is not present and frame is also not free
		{
			min_counter = frames[0][1];
			min_index = 0;
			value = frames[0][0];
			for(i=1;i<n;i++)
			{
				if(frames[i][1] < min_counter)
				{
					min_counter = frames[i][1];
					min_index = i;
					value = frames[i][0];
				}
			}
			frames[min_index][0] = str[counter];
			frames[min_index][1] = counter;
			pg_fault++;
			for(i=0;i<n;i++)
				printf("%d  ",frames[i][0]);
			printf("\t\t%d\t\t%d",pg_fault,value);
			counter++;
			continue;
		
		}

		counter++;	
			
		
	}
}
int main()
{
	
	printf("\nEnter the length of string : ");
	scanf("%d",&m);
	printf("\nEnter the input string : ");
	for(i=0;i<m;i++)
		scanf("%d",&str[i]);
	
	printf("\nEnter no. of frames : ");
	scanf("%d",&n);

	printf("\nGiven string is : ");
	for(i=0;i<m;i++)
		printf("%d ",str[i]);
	
	for(i=0;i<10;i++)
	{
		frames[i][0] = -1;
		frames[i][1] = -1;
	}
	lru_func();
	printf("\n\nTotal no. of page faults : %d\n",pg_fault);


}
