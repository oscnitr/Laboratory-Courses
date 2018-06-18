#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#define N 5
int arr[N];
int front=-1,rear=-1;
sem_t mutex,freebuffer,nloadedbuffer;
void printbuf()
{
	int i;
	for ( i=0;i<5;i++)
	{printf("%d ",arr[i]);}
}

void *prod(void *ptr)
{
	int p=(int)ptr;
int i;
for(i=0;i<4;i++)
{
	sem_wait(&freebuffer);
	sem_wait(&mutex);
		printf("\nProducer %d\n",p+1);
		rear=(rear+1)%N;
		arr[rear]=i+1;
		printbuf();
	sem_post(&mutex);
	sem_post(&nloadedbuffer);
sleep(1);
}
}

void *cons(void *ptr)
{
	int p=(int)ptr;
int i;
for(i=0;i<4;i++)
{
	sem_wait(&nloadedbuffer);
	sem_wait(&mutex);
		printf("\nConsumer %d\n",p+1);		
		front=(front+1)%N;
		arr[front]=0;
		printbuf();
	sem_post(&mutex);
	sem_post(&freebuffer);
	sleep(1);
}
}

int main()
{
	sem_init (&mutex,0,1);
	sem_init (&freebuffer,0,N);
	sem_init (&nloadedbuffer,0,0);
	pthread_t p[3];
	pthread_t c[3];
	int i,rc;
	for(i=0;i<3;i++)
	{
		rc=pthread_create(&p[i],NULL,prod,(void *)i);
		if(rc)
		{break;}
	}
	for(i=0;i<3;i++)
	{
		rc=pthread_create(&c[i],NULL,cons,(void *)i);
		if(rc)
		{break;}
	}
	for(i=0;i<3;i++)
		pthread_join(p[i],NULL);
	for(i=0;i<3;i++)
		pthread_join(c[i],NULL);
}


