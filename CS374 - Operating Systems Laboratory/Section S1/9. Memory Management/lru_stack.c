#include<stdio.h>
#include<stdlib.h>

int i,j,k;
int str[20],frames[10],m,n,counter = 0,stack[10],top=-1,bottom = -1,index = 0,available = 0,flag=0,pg_fault=0,victim_pg;

void push(int value)
{
	if(top == -1)
	{
		top = 0;
		bottom = 0;
		stack[top] = value;
	}
	else if(top<n)
	{	
		top++;
		stack[top] = value;
	}

}

void modify(int value)
{
	for(i=0;i<n;i++)
	{
		if(stack[i] == value)
			break;
	}
	for(j=i;j<top;j++)
	{
		stack[j] = stack[j+1];
	}
	stack[j] = value;
}

int pop()
{
	int victim = stack[0];
	for(i=0;i<n-1;i++)
		stack[i] = stack[i+1];
	stack[top] = -1;
	top--;
	return victim;
}

lru_func()
{
	printf("\nPage \tFrame Status\t\tPage Fault\tVictim Page\tStack status");
	while(counter<m)
	{
		printf("\n%d\t",str[counter]);

		flag = 0;
		for(i=0;i<n;i++)		//If page is present in frame
		{
			if(frames[i] == str[counter])	//Check if page is present in frame
			{
				modify(str[counter]);	//Modify the stack values
				flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			for(i=0;i<n;i++)
				printf("%d  ",frames[i]);
			printf("\t\t--\t\t--\t\t");
			for(i=0;i<n;i++)
				printf("%d  ",stack[i]);
			counter++;
			continue;
			
		}

		available = 0;
		index = -1;
		for(i=0;i<n;i++)
		{
			if(frames[i] == -1)	//Check if frame free
			{
				available = 1;
				index = i;
				break;
			}
		}
		if( flag == 0 && available == 1 )	//If page is not present but frame is free
		{
			frames[index] = str[counter];
			pg_fault++;
			push(str[counter]);	//PUSH into stack

			for(i=0;i<n;i++)
				printf("%d  ",frames[i]);
			printf("\t\t%d\t\t--\t\t",pg_fault);
			for(i=0;i<n;i++)
				printf("%d  ",stack[i]);
			counter++;
			continue;
		}
		
		else if(flag == 0 && available == 0 )	//If page is not present and frame is also not free
		{
			victim_pg = pop();	//POP from stack.
			
			for(i=0;i<n;i++)
			{
				if(frames[i] == victim_pg)
				{
					frames[i] = str[counter];
					push(str[counter]);		//PUSH new page to stack
					pg_fault++;
					
				}
			}
			
			for(i=0;i<n;i++)
				printf("%d  ",frames[i]);
			printf("\t\t%d\t\t%d\t\t",pg_fault,victim_pg);	//Print the victim page
			for(i=0;i<n;i++)
				printf("%d  ",stack[i]);
			counter++;
			continue;
		
		}

		counter++;	
		
	}
}

int main()
{
	
	printf("\nEnter the length of string : ");	//Length of string
	scanf("%d",&m);
	printf("\nEnter the input string : ");		//Input the string
	for(i=0;i<m;i++)
		scanf("%d",&str[i]);
	
	printf("\nEnter no. of frames : ");		//Input the frames
	scanf("%d",&n);

	printf("\nGiven string is : ");			//Print the string
	for(i=0;i<m;i++)
		printf("%d ",str[i]);
	
	for(i=0;i<10;i++)
	{
		frames[i] = -1;
		stack[i] = -1;
	}
	lru_func();
	printf("\n\nTotal no. of page faults : %d\n",pg_fault);	//Total no. of faults.


}
