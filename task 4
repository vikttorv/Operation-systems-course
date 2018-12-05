#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char* argv[ ])
{
	if (argc == 1)
	{
		return EXIT_SUCCESS;
	}

    int code_fork = 0;
    for (int ind = 1; ind <= argc - 1; ind++)
    {

        code_fork = fork( );
        if (code_fork)
        {
        	wait(0);
        	printf("\n\n\n");
        }        
        else
        {
            int code_exe = execl(argv[ind], argv[ind], NULL);
            if (code_exe == -1)
            {
            	printf("Exec error!!!\n");
            	exit(-1);
            }
        }
    }


    return EXIT_SUCCESS;
}
