#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[ ] )
{
    if (argc != 2)
    {
    	printf("This program gets only one argument!\n");
        return 1;
    }
    else
    {
        printf("# MSupervis2 v.0.1Viktor\n");
        int n = atoi(argv[1]);
        if (n <= 0 && strcmp(argv[1], "0"))
        {
        	printf("Incorrect argument!\n");
        	return 1;
        }
        int ind, delay;
        pid_t pid;
        for (ind = 0; ind < n; ind++)
        {
            pid = fork( );
            if (pid != 0)
            {
            	wait(0);
            }
            else
            {
            	srand(time(NULL));
            	printf("I'm %d child. I'm ready!\n", ind + 1);
                delay = 3 + (rand( ) % 3);
                sleep(delay);
                srand(time(NULL));
                if (ind == 3)
                    printf("I awake. Arrr...\n");
                printf("It's time to terminate! My code is %d\n\n", rand( ) % 2);
                return 0;
            }

        }

        return 0;    
    }


}
