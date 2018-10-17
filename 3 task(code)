#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>


const int SUCCESS = 0;
const int ERROR = -1;
const int STAT_ERROR = -2;
const int READ_ERROR = -3;
const int OPEN_ERROR = -4;


char* get_logfile(char* filename, int* size_logfile);
int url_func(char* filename);


int main(int argc, char* argv[ ])
{
    if (argc >= 2)
    {
        url_func(argv[1]);
        int error_url_func = errno;
        switch(error_url_func)
        {
            case SUCCESS:
                return EXIT_SUCCESS;
            case OPEN_ERROR:
                fprintf(stderr, "You entered incorrect name of logfile!!!\n");
                return EXIT_FAILURE;                
            case STAT_ERROR:
                fprintf(stderr, "Error: url_func(%s): get_logfile( ): stat( )\n", argv[1]);
                return EXIT_FAILURE;
            case READ_ERROR:
                fprintf(stderr, "Error: url_func(%s): get_logfile( ): read( )\n", argv[1]);
                return EXIT_FAILURE;
            default:
                printf("Strange error_url_func = %d\n", error_url_func);
                return EXIT_FAILURE;
        }   

    }
    else
    {
    	printf("Too few arguments for programe url!!!\n");
    	return EXIT_FAILURE;
    }
}


int url_func(char* filename)
{
    assert(filename);


    char* logfile = nullptr;
    int size_logfile = 0xBEDA;
    if ((logfile = get_logfile(filename, &size_logfile)) == nullptr)
    {
    	return ERROR;
    }
    

    for (int ind = 0; ind < size_logfile - 7; ind++)
    {
        if (logfile[ind] == 'h' && logfile[ind + 1] == 't' && logfile[ind + 2] == 't'
        &&  logfile[ind + 3] == 'p' && logfile[ind + 4] == ':' && logfile[ind + 5] == '/' && logfile[ind + 6] == '/')
        {
            int ind1 = ind;
            while (logfile[ind1] != ' ' &&  logfile[ind1] != '\n' && logfile[ind1] != '\t')
            {
                putchar(logfile[ind1++]);
            }
            putchar('\n');
        } 
    }	
    
    
    errno = SUCCESS;
    return SUCCESS;
   
}


char* get_logfile(char* filename, int* size_logfile)
{
    assert(filename);
    assert(size_logfile);


    int fd = 0xBEDA;
    if ((fd = open(filename, O_RDONLY)) <= 0)
    {
    	errno = OPEN_ERROR;
    	return nullptr;
    }

    struct stat buffer = {0}; // Buffer for find size of file.
    if (stat(filename, &buffer) == -1)
    {
        errno = STAT_ERROR;
        *size_logfile = 0xBEDA;
        return nullptr;
    }
    *size_logfile = buffer.st_size;
    char* logfile = (char*)calloc(buffer.st_size, sizeof(char));
    

    if (read(fd, logfile, buffer.st_size) == -1)
    {
    	errno = READ_ERROR;
    	return nullptr;
    }


    close(fd);
    return logfile;
}
