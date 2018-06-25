#include<stdlib.h>
#include<pthread.h>
#include<errno.h>
#include<semaphore.h>

sem_t mutex1,mutex2,mutex3,rsem,wsem;	//Semaphore declaration
int rdcount=0;
int wrcount=0;

void *reader_func(void *id)	//Reader function
{
	//Entry section
	int i = (int)id;
	sem_wait(&mutex3);
	sem_wait(&rsem);
	sem_wait(&mutex1);
	rdcount++;
	if(rdcount == 1)
		sem_wait(&wsem);
	sem_post(&mutex1);
	sem_post(&rsem);
	sem_post(&mutex3);

	//Critical Section
	printf("\nReader no. %d is now in critical section.\n",i);
	sleep(1);
	printf("\nReader no. %d is leaving critical section.\n",i);
	
	//Exit Section
	sem_wait(&mutex1);
	rdcount--;
	if(rdcount == 0)
		sem_post(&wsem);
	sem_post(&mutex1);
	
}	

void *writer_func(void *id)	//Writer Function
{
	//Entry Section
	int i = (int)id;
	sem_wait(&mutex2);
	wrcount++;
	if(wrcount == 1)
		sem_wait(&rsem);
	sem_post(&mutex2);
	sem_wait(&wsem);
	
	//Critical Section
	printf("\nWriter no. %d is now in critical section.\n",i);
	sleep(1);
	printf("\nWriter no. %d is leaving critical section.\n",i);

	//Exit Section
	sem_post(&wsem);
	sem_wait(&mutex2);
	wrcount--;
	if(wrcount == 0)
		sem_post(&rsem);
	sem_post(&mutex2);
}

int main()
{
	sem_init(&mutex1,0,1);	//Semaphore intialisation
	sem_init(&mutex2,0,1);
	sem_init(&mutex3,0,1);
	sem_init(&rsem,0,1);
	sem_init(&wsem,0,1);

	int j,k,l,rd=1,wr=1,x;
	pthread_t tid[10];
	for(j=0;j<10;j++)
	{
		l = rand() % 2;
		if(l == 0)
		{
			int x = pthread_create(&tid[j],NULL,reader_func, (void*)rd++);	//Thread creation
			printf("\nReader is created\n");
			if(x)	//Error checking
				break;
			
		}
		else 
		{
			int x = pthread_create(&tid[j],NULL,writer_func, (void*)wr++);	//Thread creation
			printf("\nWriter is created\n");
			if(x)
				break;
			
		}
	}
	for(k=0;k<10;k++)
		pthread_join(tid[k],NULL);	//Wait for other threads
}

