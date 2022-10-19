/**
 * @file base.h
 * @author Meles Meles(mymeles)
 * base.h is a header file that contains the fuction 
 * prototypes for the base.c file. It reads and writes file in 
 * either base10 or base32 since it is a header file for base10.c and 
 * base32.c.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/** Exit status indicating that the program was given invalid input. */
#define FAIL_INPUT 102

/** defining the ascii value of '0' as a constant*/
#define ZERO_ASCII_VALUE 48

/** defining the ascii value of '9' as a constant*/
#define NINE_ASCII_VALUE 57

/** defining the ascii value of 'A' as a constant*/
#define ASCII_CHAR_VALUE_A 65

/** defining the ascii value of 'V' as a constant*/ 
#define ASCII_CHAR_VALUE_V 86

/**
 * Read a number from standard input in the current base, terminating unsuccessfully
 * if it's not in the right format or if there's an overflow.
 * @return the number read in.
 */ 
long readNumber();

/**
 * Print the given value to standard output in the current base.
 * @param val the value to print.
 */ 
void printNumber( long val );

