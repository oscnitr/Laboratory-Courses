#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t ch[5];
void *eat(void *ptr)
{
	int p=(int)ptr;
 int i;
 if(p%2==0 && p!=4)
    {
      sem_wait(&ch[p+1]);
      sem_wait(&ch[p]);
            printf("Philosopher %d EATING\n",p);
      sem_post(&ch[p]);
      sem_post(&ch[p+1]);
    }
  else if(p==4)
   {  sem_wait(&ch[0]);
      sem_wait(&ch[p]);
            printf("Philosopher %d EATING\n",p);
      sem_post(&ch[p]);
      sem_post(&ch[0]);
   }
    
  else
    {
      sem_wait(&ch[p]);
      sem_wait(&ch[p+1]);
            printf("Philosopher %d EATING\n",p);
      sem_post(&ch[p+1]);
      sem_post(&ch[p]);
    }
 
   pthread_exit(NULL);
}

int main()
{
	int i,rc;
	for(i=0;i<5;i++)
	sem_init (&ch[i],0,1);
	pthread_t phil[5];
	for(i=0;i<5;i++)
	{
		rc=pthread_create(&phil[i],NULL,eat,(void *)i);
		if(rc)
		{break;}
	}
	for(i=0;i<5;i++)
		pthread_join(phil[i],NULL);
	
}


