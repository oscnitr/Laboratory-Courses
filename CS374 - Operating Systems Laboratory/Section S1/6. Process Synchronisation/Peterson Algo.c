#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<errno.h>
#include<time.h> 

int turn;
int flag[2];
int count = 300;

void *thread_fun (void *x)
{
	int i = (int)x;

	//Entry section
	flag[i] = 1;
	turn = 1-i;
	while(flag[1-i] == 1 && turn == 1-i);

	//Critical Section
	if( i == 0 )
	{
		int a = count;
		a = a - 50;
		sleep(1);
		count = a;
		printf("\nFor thread %d, Value of count : %d\n",i,count);
	}
	else if( i == 1)
	{
		int a = count;
		a = a - 100;
		sleep(1);
		count = a;
		printf("\nFor thread %d, Value of count : %d\n",i,count);
	}

	//Exit Section
	flag[i] = 0;
	
}

int main()
{
	int j,rc;
	pthread_t pt[2];
	flag[0] = 0;
	flag[1] = 0;
	srand(time(NULL));
	turn=rand()%2;
	for ( j = 0 ; j < 2 ; j++ )
	{
		rc = pthread_create(&pt[j],NULL,thread_fun,(void*)turn);	//Thread creation
		if(rc)
		{
			printf("\nThread creation failed with error code : %d\n",rc);	//Checking if failed
			exit(0);
		}
		pthread_join(pt[j],NULL);	//Waiting for child thread
		printf("\nIn main, Value of count = %d\n",count);
	}
		
}
