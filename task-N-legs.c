#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int legs[2] = {0};
const int MAX_IND = 100;

void* mythread(int *ind)
{
    legs[*ind]++;
    printf("Thread number %d, thid = %lu, legs[%d] = %d\n", *ind, pthread_self( ), *ind, legs[*ind]);
    return NULL;
}


int main(int argc, char* argv[ ])
{
    if (argc < 2)
    {
        printf("Too few arguments for this function!!!\n");
        return EXIT_FAILURE;
    }

    pthread_t thid = 0, mythid = 0;
    int code_error = 0, ind = 0, ind1 = 1;
    int N = atoi(argv[1]);
    while ((ind++) < MAX_IND)
    {
        legs[0]++;
        printf("Thread number %d, thid = %lu, legs[0] = %d\n", ind1, pthread_self( ), legs[0]);


        for (ind1 = 1; ind1 <= N; ind1++)
        {    
            code_error = pthread_create(&thid, (pthread_attr_t *)NULL, (void* (*)(void*))mythread, (void*)(&ind1));
            if (code_error != 0)
            {    
                printf ("Error on thread create, return value = %d\n", code_error);
                exit(-1);
            }
            pthread_join(thid, (void **)NULL);
        }
        ind1 = 1;
    }

    return EXIT_SUCCESS;
}
