/**
 * @file bounds.h
 * @author Meles Meles (mymeles)
 * bounds.h is a header file that contains all the 
 * fuctions prototypes used in bounds.c. It gives preview to 
 * the operation subtraction, addition, multiplication and 
 * division.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/** Defining standard eit status for overflowing operations */
#define OVERFLOW_EXIT_STATUS 100

/** Defining standard eit status for overflowing operations */
#define ZERO_OPERATION_EXIT_STATUS 101

/**
 * checkAdd is a fuction that checks if 2 numbers(type long) 
 * added together do not over flow. otherwise, if overflow happens then 
 * it will exit out of the program with an exit status of 100
 * 
 * @param a is a long type number
 * @param b is a long type number 
 */
void checkAdd( long a, long b );

/**
 * checkSub is a fuction that checks if 2 numbers(type long) 
 * subtracted together do not over flow. otherwise, if overflow happens then 
 * it will exit out of the program with an exit status of 100
 * 
 * @param a is a long type number
 * @param b is a long type number 
 */
void  checkSub( long a, long b );

/**
 * checkMul is a fuction that checks if 2 numbers(type long) 
 * multiplied together do not over flow. otherwise, if overflow 
 * happens then it will exit out of the program with an exit 
 * status of 100
 * 
 * @param a is a long type number
 * @param b is a long type number 
 */
void checkMul( long a, long b );

/**
 * checkDiv is a fuction that checks if 2 numbers(type long) 
 * divided together do not over flow. otherwise, if overflow happens then 
 * it will exit out of the program with an exit status of 100. in-addition 
 * if the program tries to divide with a value of zero then it will 
 * exit with a status of 101
 * 
 * @param a is a long type number
 * @param b is a long type number 
 */
void checkDiv( long a, long b );
