#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>

#define MAX 10000
#define SIZE 8
int array[SIZE];

void merge(int low, int mid, int high)
{
	int size_1 = mid -low+1+1;
	int size_2 = high - mid +1;
	int left[size_1];
	int right[size_2];
	int x,y = 0,z = 0;
	for ( x = 0 ; x < size_1 - 1 ; x++ )
		left[x] = array[low + x];
	left[x] = MAX;
	
	for ( x = 0 ; x < size_2 - 1 ; x++ )
		left[x] = array[mid+1 + x];
	left[x] = MAX;

	for ( x = low ; x <= high ; x++ ) 
	{
		if(left[y] < right[z] )
		{	
			array[x] = left[y];
			y++;
		}
		else
		{
			array[x] = right[z];
			z++;
		}
	}
}



void* divide_fun (void *id)
{
	int*index = (int*)id;
	int low = index[0];
	int high = index[1];
	if ( low >= high )
		return;
	int mid = ( low + high ) / 2;
	int rc1,rc2;
	pthread_t pt1[2];

	int index1[2];		//Lower index elements
	index1[0]=low;
	index1[1]=mid;
	rc1=pthread_create(&pt1[0],NULL,divide_fun,(void*)index1);
	if(rc1)
	{
		printf("\nThread creation failed with error code : %d\n",rc1);	//Checking if failed
		exit(0);
	}
	pthread_join(pt1[0],NULL);	//Waiting for child thread

	int index2[2];		//Higher index elements
	index2[0]=mid+1;
	index2[1]=high;
	rc2=pthread_create(&pt1[1],NULL,divide_fun,(void*)index2);
	if(rc2)
	{
		printf("\nThread creation failed with error code : %d\n",rc2);	//Checking if failed
		exit(0);
	}
	pthread_join(pt1[1],NULL);	//Waiting for child thread

	merge(low,mid,high);	//Call merge function
}

	

int main()
{
	int i,j,k;
	printf("\nEnter elements of the array :\n");
	for ( i=0; i<SIZE; i++ )
		scanf("%d",&array[i]);

	int index[2];
	index[0]=0;
	index[1]=SIZE-1;
	int rc;
	pthread_t pt[2];
	rc=pthread_create(&pt[0],NULL,divide_fun,(void*)index);
	pthread_join(pt[0],NULL);
	printf("Sorted array is :\n");
	for(i=0;i<SIZE;i++)
		printf("%d\t",array[i]);
	
}
	
	
