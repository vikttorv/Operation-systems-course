#include <stdio.h>
#define MATRIX_SIZE 1000
#include <assert.h>
int transpose(int strings_num, int bars_num, double matrix[ ][MATRIX_SIZE]);
int print_matrix(int strings_num, int bars_num, double matrix[ ][MATRIX_SIZE]);
int main( )
{
    printf("# Matrix transponation v.O.1a(c)Viktor\n");
    printf("# Enter strings_num and bars_num:\n");
    int code_scanf = 0xBEDA, strings_num = 0xBEDA, bars_num = 0xBEDA;
    char rubbish;
    code_scanf = scanf("%d %d", &strings_num, &bars_num);
    while (code_scanf != 2)
    {
        printf("Both arguments must have type double! Try again.\n"); 
        while ((rubbish = getchar( )) != '\n');          
        code_scanf = scanf("%d %d", &strings_num, &bars_num);
    }

    double matrix[MATRIX_SIZE][MATRIX_SIZE];
    int ind_1 = 0xBEDA, ind_2 = 0xBEDA;
    printf("# Enter element of matrix:\n");
    for (ind_1 = 0; ind_1 < strings_num; ind_1++)       
    {
        for (ind_2 = 0; ind_2 < bars_num; ind_2++)
        { 
            code_scanf = scanf("%lg", &matrix[ind_1][ind_2]);
            if (code_scanf != 1)
            {
                printf("# You enter incorrect element number %d! Try to enter this string again:\n", ind_2 + 1);
                ind_2 = -1;
                while ((rubbish = getchar( )) != '\n'); 
            }
        }
    }
    printf("\n");
    printf("\n");
    printf("Matrix:\n");
    print_matrix(strings_num, bars_num, matrix);
    transpose(strings_num, bars_num, matrix);
    printf("\n");
    printf("\n");    
    printf("Transpose matrix:\n");
    print_matrix(bars_num, strings_num, matrix); 
    return 0;
}



int print_matrix(int strings_num, int bars_num, double matrix[ ][MATRIX_SIZE])
{
    int string_ind, bar_ind;
    for (string_ind = 0; string_ind < strings_num; string_ind++)
    {	
        for (bar_ind = 0; bar_ind < bars_num; bar_ind++)
        {
            printf("%-3lg ", matrix[string_ind][bar_ind]);
        }
        printf("\n");
    }
    return 0;
}



int transpose(int strings_num, int bars_num, double matrix[ ][MATRIX_SIZE])
{
	double transpose_matrix[bars_num][strings_num];
    int string_ind, bar_ind;
    for (string_ind = 0; string_ind < strings_num; string_ind++)
    {	
        for (bar_ind = 0; bar_ind < bars_num; bar_ind++)
        {
            transpose_matrix[bar_ind][string_ind] = matrix[string_ind][bar_ind];
        }
    }
    for (string_ind = 0; string_ind < bars_num; string_ind++)
    {	
        for (bar_ind = 0; bar_ind < strings_num; bar_ind++)
        {
            matrix[string_ind][bar_ind] = transpose_matrix[string_ind][bar_ind];
        }
    }
    return 0;
    
}
