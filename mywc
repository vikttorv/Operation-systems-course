#include <stdio.h>
int main( )
{
    printf("# mywc v.O.1a(c)Viktor\n");
    char ch;
    int wordcount = 0, linecount = 0;
    bool isword = false;
    while ((ch = getchar( )) != EOF)
    {
        if (ch == '\n')
                linecount += 1;

        if (ch != '\n' && ch != '\t' && ch != ' ' && !(isword))
        {
                isword = true;
                wordcount += 1;
        }
        else if ( (ch == '\n' || ch == '\t' || ch == ' ') && isword )
            isword = false;
    }
    printf("The number of words in this file is %d.\n", wordcount);
    printf("The number of lines in this file is %d.\n", linecount);
    return 0;
}
