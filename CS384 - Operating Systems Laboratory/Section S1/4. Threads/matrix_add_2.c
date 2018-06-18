#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>

#define m 2
#define n 3

typedef struct node{		//Structure for pointer arrays
	int (*ptr1)[m][n];
	int (*ptr2)[m][n];
	int (*ptr3)[m][n];
	int row;
	int col;
}th_data;
	

void *run_add(void * th_d)	//Thread function 
{
	th_data *dptr = th_d;
	int p,q,r,c;
	r = dptr->row;
	c = dptr->col;

	(*dptr->ptr3)[r][c] = (*dptr->ptr1)[r][c] + (*dptr->ptr2)[r][c]; 	//Addition
	
	pthread_exit(NULL);
}

void * fun_row( void *th_d1)		
{
	pthread_t pt1[n];
	th_data *dptr1 = th_d1;
	int l,y;
	for ( l=0;l<n;l++)
	{
		dptr1->col = l;
		y = pthread_create(&pt1[l],NULL,run_add,dptr1);	//Thread creation for n columns
		if(y)
		{
			printf("\nThread creation failed with error code : %d\n",y);	//Checking if failed
			exit(0);
		}
		pthread_join(pt1[l],NULL);	//Waiting for child thread
	
	}

}

int main(void)
{
	int A[m][n],B[m][n],C[m][n],i,j,k,l,x;
	pthread_t pt[m];
	printf("\nEnter the values of 1st matrix :\n");		//Input for 1st matrix
	for ( i=0 ; i<m ; i++ )
		for ( j=0 ; j<n ; j++ )
			scanf("%d",&A[i][j]);
	
	printf("\nEnter the values of 2nd matrix :\n");		//Input for 2nd matrix
	for ( i=0 ; i<m ; i++ )
		for ( j=0 ; j<n ; j++ )
			scanf("%d",&B[i][j]);
	th_data d;
	d.ptr1 = &A;
	d.ptr2 = &B;
	d.ptr3 = &C;
	for ( k=0;k<m;k++)
	{
		d.row = k;
		x = pthread_create(&pt[k],NULL,fun_row,&d);	//Thread creation for m rows
		if(x)
		{
			printf("\nThread creation failed with error code : %d\n",x);	//Checking if failed
			exit(0);
		}
		pthread_join(pt[k],NULL);	//Waiting for child thread
	
	}
	printf("\nThe solution matrix : \n");	
	for ( i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",C[i][j]);		//Displaying the output matrix
		printf("\n");
	}
	pthread_exit(NULL);

}
