#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>

#define m 2
#define n 3

typedef struct node{		
	int (*ptr1)[m][n];
	int (*ptr2)[m][n];
	int (*ptr3)[m][n];
	int row;
}th_data;
	

void *run_add(void * th_d)	
{
	th_data *dptr = th_d;
	int p,q,r;
	r = dptr->row;
	for(p = 0 ; p < n ; p+=2)
		(*dptr->ptr3)[r][p] = (*dptr->ptr1)[r][p] - (*dptr->ptr2)[r][p]; 
	
	pthread_exit(NULL);
}
void *run_add_2(void * th_d)	
{
	th_data *dptr = th_d;
	int p,q,r;
	r = dptr->row;
	for(p = 1 ; p < n ; p+=2)
		(*dptr->ptr3)[r][p] = (*dptr->ptr1)[r][p] - (*dptr->ptr2)[r][p]; 
	
	pthread_exit(NULL);
}
int main(void)
{
	int A[m][n],B[m][n],C[m][n],i,j,k,l,x;
	pthread_t pt1,pt2;
	printf("\nEnter the values of 1st matrix :\n");		
	for ( i=0 ; i<m ; i++ )
		for ( j=0 ; j<n ; j++ )
			scanf("%d",&A[i][j]);
	
	printf("\nEnter the values of 2nd matrix :\n");		
	for ( i=0 ; i<m ; i++ )
		for ( j=0 ; j<n ; j++ )
			scanf("%d",&B[i][j]);
	th_data d,e;
	d.ptr1 = &A;
	d.ptr2 = &B;
	d.ptr3 = &C;
	for ( k=0;k<m;k++)
	{
		d.row = k;
	if((d.row % 2)==0)
		x = pthread_create(&pt1,NULL,run_add,&d);
	else
		x = pthread_create(&pt2,NULL,run_add_2,&d);		
		if(x)
		{
			printf("\nThread creation failed with error code : %d\n",x);	
			exit(0);
		}
		pthread_join(pt1,NULL);	//Waiting for child thread
		pthread_join(pt2,NULL);
	}
	
	printf("\nThe solution matrix : \n");	
	for ( i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",C[i][j]);		
		printf("\n");
	}
	pthread_exit(NULL);		

}
