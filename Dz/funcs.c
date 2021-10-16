/*! \defgroup <funcs> (The module working with functions)
 @{
 */
/**
 * \file funcs.c
 * \brief File with the code of the functions used in program
 * \version 1.0
 * \date 28.10.2020
 @}
 */
#include <assert.h>
#include "funcs.h"
#include "error_codes.h"
#include "constants.h"

/**
 * \brief is_palindome - Checking if the number is palindrome or not
 * \param number the number being checked
 * \return error code
 */
int is_palindrome(int number)
{
    int rev_num = 0, num_duplicate = number;
    while (num_duplicate > 0)
    {
        rev_num = rev_num * 10 + num_duplicate % 10;
        num_duplicate /= 10;
    }
    if (rev_num == number)
        return IS_PALINDROME;
    else
        return NOT_PALINDROME;
}

/**
 * \brief forming_new_array - Forming array of palindromes
 * \param numbers source array of numbers
 * \param palindromes new array of palindromes
 * \param num_len size of source array
 * \return size of new array of palindromes
 */
int forming_new_array(int *numbers, int *palindromes, int num_len)
{
    int j = 0;
    for (int i = 0; i < num_len; i++)
    {
        if (is_palindrome(numbers[i]))
            palindromes[j++] = numbers[i];
    }
    return j;
}