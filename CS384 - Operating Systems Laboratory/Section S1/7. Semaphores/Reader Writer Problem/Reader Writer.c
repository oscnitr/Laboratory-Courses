#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#define size 6
sem_t order,rdcnt,access;
int rdcount=0;
void *writef(void *ptr)
{
	int p=(int)ptr;
	int i;
	
	sem_wait(&order);
		sem_wait(&access);
	sem_post(&order);
		printf("\nWriter %d writing\n",p+1);
	sem_post(&access);
		printf("\nWriter %d over\n",p+1);
	
}
void *readf(void *ptr)
{
	int p=(int)ptr;
	int i;
	
	sem_wait(&order);
	sem_wait(&rdcnt);
		rdcount++;
	if(rdcount==1)
		sem_wait(&access);
	sem_post(&rdcnt);
	sem_post(&order);
		printf("\nReader %d reading\n",p+1);
		sleep(1);
	sem_wait(&rdcnt);
		rdcount--;
	printf("\nReader %d over\n",p+1);
	if(rdcount==0)
		sem_post(&access);	
	sem_post(&rdcnt);
		
}
int main()
{
	int i,rc;
	
	sem_init (&order,0,1);
	sem_init (&rdcnt,0,1);
	sem_init (&access,0,1);
	pthread_t read[size];
	pthread_t write[size];
	for(i=0;i<size;i++)
	{
		rc=pthread_create(&write[i],NULL,writef,(void *)i);
		if(rc)
		{break;}
	}
	for(i=0;i<size;i++)
	{
		rc=pthread_create(&read[i],NULL,readf,(void *)i);
		if(rc)
		{break;}
	}
	for(i=0;i<size;i++)
		pthread_join(write[i],NULL);
	for(i=0;i<size;i++)
		pthread_join(read[i],NULL);
	
	
}
