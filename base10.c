/**
 * @file base10.c
 * @author Meles Meles (mymeles)
 * 
 * base10.c is file that holds the fuctions of reading a number and 
 * writing a number to the standard input/output. If it can't read a number it will
 * exit with a value of 102
 */

#include "base.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

long readNumber(){
   long num_read;
   scanf("%ld", &num_read);
   // if(matches != 1){
   //    exit(FAIL_INPUT);
   // }
   return num_read;
}

void printNumber( long val ){
   printf("%ld", val);
}
