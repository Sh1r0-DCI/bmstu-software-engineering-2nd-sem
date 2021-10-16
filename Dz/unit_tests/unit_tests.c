#include <stdio.h>
#include <assert.h>
#include "../constants.h"
#include "../error_codes.h"
#include "../in_out.h"
#include "../funcs.h"

void array_input_tests(void)
{
    FILE *f_0 = fopen("u_0.txt", "r");
    FILE *f_1 = fopen("u_1.txt", "r");
    FILE *f_2 = fopen("u_2.txt", "r");
    FILE *f_3 = fopen("u_3.txt", "r");
    FILE *f_4 = fopen("u_4.txt", "r");
    
    int a_0[ARRAY_LEN];
    int a_1[ARRAY_LEN];
    int a_2[ARRAY_LEN];
    int a_3[ARRAY_LEN];
    int a_4[ARRAY_LEN];
    
    int n_0 = 0;
    int n_1 = 0;
    int n_2 = 0;
    int n_3 = 0;
    int n_4 = 0;
    
    int result;
    
    printf("\narray_input UNIT TESTS:\n");
    
    result = array_input(f_0, a_0, &n_0);
    assert(result == FILE_DOES_NOT_EXIST);
    printf("Несуществующий файл\n");

    result = array_input(f_1, a_1, &n_1);
    assert(result == NO_ELS_IN_FILE);
    printf("Пустой Файл\n");
    
    result = array_input(f_2, a_2, &n_2);
    assert(result == OK);
    output_array(a_2, n_2);
    printf("    количество элементов равно %d\n", n_2);
    
    result = array_input(f_3, a_3, &n_3);
    assert(result == INPUT_ERROR);
    printf("Неверный символ в файле\n");
    
    result = array_input(f_4, a_4, &n_4);
    assert(result == INPUT_ERROR)  ;
    printf("Неверный символ в файле\n");
    
    fclose(f_0);
    fclose(f_1);
    fclose(f_2);
    fclose(f_3);
    fclose(f_4);
}

void forming_new_array_tests(void)
{
    int a_1[] = { -33, -212, -3 };
    int a_2[] = { -10, 1, 5, 323, 14 };
    int a_3[] = { 2, 2, 22, -525, 888 };
    int a_4[] = { -1, -121, 231 };
    
    int pal_1[ARRAY_LEN];
    int pal_2[ARRAY_LEN];
    int pal_3[ARRAY_LEN];
    int pal_4[ARRAY_LEN];
    
    int n_1 = 3;
    int n_2 = 5;
    int n_3 = 5;
    int n_4 = 3;
    
    int k_1 = 0;
    int k_2 = 0;
    int k_3 = 0;
    int k_4 = 0;
    
    printf("\nforming_new_array UNIT TESTS:\n");
    
    k_1 = forming_new_array(a_1, pal_1, n_1);
    assert(k_1 == 2);
    output_array(pal_1, k_1);
    printf("    k = %d\n", k_1);
    
    k_2 = forming_new_array(a_2, pal_2, n_2);
    assert(k_2 == 3);
    output_array(pal_2, k_2);
    printf("    k = %d\n", k_2);
    
    k_3 = forming_new_array(a_3, pal_3, n_3);
    assert(k_3 == 4);
    output_array(pal_3, k_3);
    printf("    k = %d\n", k_3);
    
    k_4 = forming_new_array(a_4, pal_4, n_4);
    assert(k_4 == 0);
    printf("Пустой массив \n    k = %d\n", k_4);
}

void output_array_tests(void)
{
    int pal_1[] = { 1 };
    int pal_2[] = { 1, 2, 3, 4, 5 };
    
    int k_1 = 1;
    int k_2 = 5;
    
    printf("\noutput_array UNIT TESTS:\n");
    
    output_array(pal_1, k_1);
    printf("\n");
    assert(k_1 == 1);
    
    output_array(pal_2, k_2);
    printf("\n");
    assert(k_2 == 5);
}

void is_palindrome_tests(void)
{
    int number_1 = 1;
    int number_2 = 0;
    int number_3 = 11;
    int number_4 = -121;
    int number_5 = -1;
    int number_6 = -24;
    
    int result;
    
    printf("\nis_palindrome UNIT TESTS:\n");
    
    result = is_palindrome(number_1);
    assert(result == IS_PALINDROME);
    printf("%d\n", result);
    
    result = is_palindrome(number_2);
    assert(result == IS_PALINDROME);
    printf("%d\n", result);
    
    result = is_palindrome(number_3);
    assert(result == IS_PALINDROME);
    printf("%d\n", result);
    
    result = is_palindrome(number_4);
    assert(result == NOT_PALINDROME);
    printf("%d\n", result);
    
    result = is_palindrome(number_5);
    assert(result == NOT_PALINDROME);
    printf("%d\n", result);
    
    result = is_palindrome(number_6);
    assert(result == NOT_PALINDROME);
    printf("%d\n", result);
}

int main(void)
{
    array_input_tests();
    forming_new_array_tests();
    output_array_tests();
    is_palindrome_tests();
    return OK;
}
