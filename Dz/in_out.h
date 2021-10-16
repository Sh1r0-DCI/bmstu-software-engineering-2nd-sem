/*! \defgroup <in_out> (The module for reading the file and outputting the result)
 @{
 */
/**
 * \file in_out.h
 * \brief File with the code of the input and output
 * \version 1.0
 * \date 28.10.2020
 @}
 */
#ifndef _IN_OUT_H_

#define _IN_OUT_H_

int array_input(FILE *f, int *numbers, int *pn);
void output_array(int *numbers, int n);

#endif