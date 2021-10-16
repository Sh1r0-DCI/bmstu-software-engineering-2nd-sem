/*! \defgroup <main> (The Main module)
  @{
  */
/**
 * \file main.c
 * \brief File with the main code
 * \version 1.0
 * \date 28.10.2020
 @}
 */
#include <stdio.h>
#include "in_out.h"
#include "constants.h"
#include "error_codes.h"
#include "funcs.h"

/*!
 * \brief main - ouput palindrome numbers found in a file.
 * \return error code
 */
int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    FILE *f = fopen(argv[1], "r");
    int numbers[ARRAY_LEN], palindromes[ARRAY_LEN];
    int exit_code, num_len, pal_len/*Длины массива всех элементов и массива палиндромов*/;
    if ((exit_code = array_input(f, numbers, &num_len)) == FILE_DOES_NOT_EXIST)
        printf("File doesn't exist.\n");
    else if (exit_code == INPUT_ERROR)
        printf("Unexpected symbol in a file.\n");
    else if (exit_code == NO_ELS_IN_FILE)
        printf("No elements in a file.\n");
    else if (!(pal_len = forming_new_array(numbers, palindromes, num_len)))
    {
        exit_code = NO_PALINDROMES_IN_ARRAY;
        printf("No palindromes in array.\n");
    }
    else
        output_array(palindromes, pal_len);
    return exit_code;
}