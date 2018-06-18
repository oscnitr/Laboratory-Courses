#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#define size 5
sem_t l,r;
void *left(void *ptr)
{
	int p=(int)ptr;
	sem_wait(&l);
		printf("\nLeft process:%d\n Left foot moves left\nright foot moves left\n",p+1);
	sem_post(&r);
}
void *right(void *ptr)
{
	int p=(int)ptr;
	sem_wait(&r);
		printf("\nRight process:%d\n right foot moves right\nleft foot moves right\n",p+1);
	sem_post(&l);
	
}
int main()
{
	int i=0,rc;
	
	sem_init (&l,0,1);
	sem_init (&r,0,0);
	pthread_t leftfoot[size];
	pthread_t rightfoot[size];
	for(i=0;i<size;i++)
	{
		rc=pthread_create(&leftfoot[i],NULL,left,(void *)i);
		if(rc)
		{break;}
	}
	for(i=0;i<size;i++)
	{
		rc=pthread_create(&rightfoot[i],NULL,right,(void *)i);
		if(rc)
		{break;}
	}
	
	for(i=0;i<size;i++)
	pthread_join(leftfoot[i],NULL);
	for(i=0;i<size;i++)
	pthread_join(rightfoot[i],NULL);
}
