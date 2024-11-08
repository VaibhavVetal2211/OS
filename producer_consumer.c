#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define maxItems 5
#define buffersize 5

int buffer[buffersize];
int in = 0;
int out = 0;
pthread_mutex_t mutex ;
sem_t empty;
sem_t full;


void *producer( void*pno)
{
    int item ;
   for(int i=0;i<maxItems;i++)
   {
         item = rand();
            sem_wait(&empty); //empty -1

            pthread_mutex_lock(&mutex);

            buffer[in] = item;
            printf("Producer %d inserted item %d at %d\n" ,*((int*)pno),buffer[in],in );
            in = (in+1) % buffersize ;

            pthread_mutex_unlock(&mutex);

            sem_post(&full);   // full+1


   }
}

void *consumer(void*cno)
{
        for(int i=0;i<maxItems;i++)
        {
            sem_wait(&full);  //full-1
            pthread_mutex_lock(&mutex);
            int item = buffer[out];
            
            printf("Consumer %d removes item %d from %d \n",*((int *)cno) , buffer[out] , out);  
            out = (out + 1) % buffersize;

            pthread_mutex_unlock(&mutex);

            sem_post(&empty); //empty+1
        }
}

int main()
{
    pthread_t pro[5] , con[5];
    pthread_mutex_init(&mutex,NULL);

    sem_init(&empty , 0 , buffersize);
    sem_init(&full , 0 , 0);

    int a[5] = {1,2,3,4,5};

    for(int i=0;i<5;i++)
    {
        pthread_create(&pro[i],NULL,(void *)producer ,(void *) &a[i] );

    }

    for(int i=0 ; i<5;i++)
    {
        pthread_create(&con[i],NULL,(void *)consumer , (void * ) &a[i]);
    }

    for(int i=0;i<5;i++)
    {
        pthread_join(pro[i] , NULL);
    }

    for(int i=0;i<5;i++)
    {
        pthread_join(con[i] , NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy( &empty);
    sem_destroy(& full);

    return 0;


}
