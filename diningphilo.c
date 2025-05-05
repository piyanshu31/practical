#include <stdio.h>
#include <pthread.h>
#include<unistd.h>

#define N 5
pthread_mutex_t forks[N];

void *philosopher(void * num)
{
    int id = *(int * )num;
    int left = id;
    int right = (id+1)%N;

    while(1)
    {
        printf("philosopher %d is thinking \n ", id);
        sleep(1);

        pthread_mutex_lock(&forks[left]);
        pthread_mutex_lock(&forks[right]);

        printf("philosopher %d is eating \n ",id);
        sleep(1);

        pthread_mutex_unlock(&forks[right]);
        pthread_mutex_unlock(&forks[left]);
    }
    return NULL;
}

int main()
{
    pthread_t threads[N];
    int ids[N];

    for(int i=0; i<N; i++)
        pthread_mutex_init(&forks[i],NULL);

    for(int i=0;i<N;i++)
    {
        ids[i]=i;
        pthread_create(&threads[i],NULL,philosopher,&ids[i]);
    }

    for(int i=0; i<N;i++)
        pthread_join(threads[i],NULL);
}
