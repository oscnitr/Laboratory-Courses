#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
#define n 5
int array[n];

void merge(int low,int mid,int high)
{
	int size_1=mid-low+1 +1;
	int size_2=high-mid +1;
	int left[size_1];	//Left Array
	int right[size_2];	//Right Array
	int i;
	for(i=0;i<size_1-1;i++)
		left[i]=array[low+i];
	left[i]=MAX;

	for(i=0;i<size_2-1;i++)
		right[i]=array[mid+1+i];
	right[i]=MAX;

	int j=0,k=0;

	for(i=low;i<=high;i++)		//Merge algorithm
	{
		if(left[j]<right[k])
			array[i]=left[j],j++;
		else array[i]=right[k],k++;
	}
}
void* divide_fun(void* datae)
{
	int *data=(int*)datae;

	int low=data[0];
	int high=data[1];
	if(low>=high) return;
	int mid=(low+high)/2;
	int rc;
	int threads[2];

	int data1[2];
	data1[0]=low;
	data1[1]=mid;
	rc=pthread_create(&threads[0],NULL,divide_fun,(void*)data1);	//Thread for left side array

	pthread_join(threads[0],NULL);

	int data2[2];
	data2[0]=mid+1;
	data2[1]=high;
	rc=pthread_create(&threads[1],NULL,divide_fun,(void*)data2);	//Thread for right side array
	pthread_join(threads[1],NULL);

	merge(low,mid,high);	//Calling merge function
}

int main()
{
	int i;
	printf("\nEnter elements of the array :\n");
		for ( i=0; i<n; i++ )
			scanf("%d",&array[i]);

	int p[2];
	p[0]=0;
	p[1]=n-1;

	int rc,thre[2];
	rc=pthread_create(&thre[0],NULL,divide_fun,(void*)p);
	pthread_join(thre[0],NULL);
	printf("\nFinal sorted array : \n");
	for(i=0;i<n;i++)	//Printing final array
		printf("%d ",array[i]);
	printf("\n");
}
