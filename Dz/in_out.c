/*! \defgroup <in_out> (The module for reading the file and outputting the result)
 @{
 */
/**
 * \file in_out.c
 * \brief File with the code of the input and output
 * \version 1.0
 * \date 28.10.2020
 @}
 */
#include <stdio.h>
#include <assert.h>
#include "in_out.h"
#include "error_codes.h"
#include "constants.h"

/**
 * \brief array_input - Array read from a file function
 * \param f file pointer
 * \param a array of integers
 * \param pn number of elements in array pointer
 * \return error code
 */
int array_input(FILE *f, int *numbers, int *pn)
{
    int rc, *p_numbers = numbers;
    *pn = 0;
    if (f == NULL)
        return FILE_DOES_NOT_EXIST;
    for (int i = 0; (rc = fscanf(f, "%d", p_numbers++)) == THERE_IS_A_NUMBER; i++)
        (*pn)++;
    fclose(f);
    if (rc != THERE_IS_A_NUMBER && rc != EOF)
        return INPUT_ERROR;
    if (*pn == 0)
        return NO_ELS_IN_FILE;
    return OK;
}

/**
 * \brief output_array - Outputting an array
 * \param arr array of integers to output
 * \param n number of elements in array
 */
void output_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}