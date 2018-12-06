#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int legs[2] = {0};
const int MAX_IND = 1000;

void* mythread(void *dummy)
{
    legs[1]++;
    printf("Second thread: legs[1] = %d\n", legs[1]);
    return NULL;
}


int main( )
{
    pthread_t thid = 0, mythid = 0;
    int result = 0, ind = 0, step = 0;

    while ((ind++) < MAX_IND)
    {
        result = pthread_create(&thid, (pthread_attr_t *)NULL, mythread, NULL);
        if (result != 0)
        {    
            printf ("Error on thread create, return value = %d\n", result);
            exit(-1);
        }


        legs[0]++;
        printf("First thread: legs[0] = %d\n", legs[0]);
        pthread_join(thid, (void **)NULL);
    }


    return EXIT_SUCCESS;
}
