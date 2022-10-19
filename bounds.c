/**
 * @file bounds.c
 * @author Meles Meles (mymeles)
 * bounds.c is a bounds checking class for the operation, addition, 
 * subtraction, multiplication, and division. if any operation over flows 
 * from the data type Long(the max and the min) it will exit out with a 
 * an exit status of 100. and an exit status of 101 if the program tries to 
 * divide with zero. 
*/

#include "bounds.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void checkAdd(long a, long b)
{
   long add = a + b;
   if ((a > 0 && b > 0) && add < 0) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if ((a < 0 && b < 0) && add > 0) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if ((a < 0 && b > 0)) {
      if (a >= LONG_MIN && b <= LONG_MAX && add > 0) {
         exit(OVERFLOW_EXIT_STATUS);
      }
   } 
   else if(a < 0 && b > 0){
      if(LONG_MIN - b > a){
         exit(OVERFLOW_EXIT_STATUS);
      }
   }else if(a == 0 && b == LONG_MIN){
      exit(OVERFLOW_EXIT_STATUS);
   }
}

void checkSub(long a, long b)
{
   long sub = a - b;
   if (a > 0 && b > 0) {
      if (a >= b && sub < 0) {
         exit(OVERFLOW_EXIT_STATUS);
      }
      else if (b >= a && sub > 0) {
         exit(OVERFLOW_EXIT_STATUS);
      }
   }
   else if (a < 0 && b < 0) {
      if (a <= b && sub > 0) {
         exit(OVERFLOW_EXIT_STATUS);
      }
      else if (a >= b && sub < 0) {
         exit(OVERFLOW_EXIT_STATUS);
      }
   }
   else if (a < 0 && b > 0) {
      if(LONG_MIN - b < a) {
         exit(OVERFLOW_EXIT_STATUS);
      }
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if (a > 0 && b < 0 && sub <= 0) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if(a == 0 && b == LONG_MIN){
      exit(OVERFLOW_EXIT_STATUS);
   }
}

void checkMul(long a, long b)
{
   long x = LONG_MAX / b;
   long y = (LONG_MIN) / b;
   if (a > 0 && b > 0 && a > x) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if (a < 0 && b < 0 && a <= x) { // not sure about this piece of code
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if (a < 0 && b > 0 && a < y) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if (a > 0 && b < 0 && a > (y)) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if ((a == LONG_MIN && b == -1) || (b == LONG_MIN && a == -1)) {
      exit(OVERFLOW_EXIT_STATUS);
   }
}

void checkDiv(long a, long b)
{
   if (a == LONG_MIN && b == -1) {
      exit(OVERFLOW_EXIT_STATUS);
   }
   else if (b == 0) {
      exit(ZERO_OPERATION_EXIT_STATUS);
   }
}
