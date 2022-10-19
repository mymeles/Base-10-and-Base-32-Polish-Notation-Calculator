/**
 * @file base32.c
 * @author Meles Meles (mymeles)
 * Base32.c is a file that reads number from the standard input in base32 
 * and writes a number in base32 to the standard put put.
 */

#include "base.h"
#include "bounds.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/** A constant definition of the character zero */
#define ZERO_ASCII_VALUE 48

/** A constant definition of the character nine */
#define NINE_ASCII_VALUE 57

/** A constant ASCII definition of the character 'A' */
#define ASCII_CHAR_VALUE_A 65 

/** A constant ASCII definition of the character 'V' */
#define ASCII_CHAR_VALUE_V 86

/** Defining the base of the number that is read */
#define BASE_THIRTY_TWO 32

/** defining the value 9 as a constant */
#define BASE_32_NUM_NINE 9

/** defining the value 10 as a constant */
#define ALPHABET_DIFFERENCE 10


/**
 * This method isNum2 checks if a character is a number from zero to nine(0-9).
 * 
 * @param ch is type character that is validated weather it is a 
 * number or not in base32.
 * @return _Bool  true if ch is a number from 0-9 or else false
 */
static _Bool isNum2(char ch)
{
   return ch >= ZERO_ASCII_VALUE && ch <= NINE_ASCII_VALUE;
   
}

/**
 * validBase is a function that checks the input for Base32 is 
 * valid input. 
 * @param ch is a character. 
 * @return _Bool if the character is valid input for base32 or else false. 
 */
static _Bool validBase(char ch)
{
   return isNum2(ch) || (ch >= ASCII_CHAR_VALUE_A && ch <= ASCII_CHAR_VALUE_V);
}

/**
 * char_to_digit is a fuction that translates integer values into
 * ASCII value characters
 * 
 * @param ch is a character 
 * @return integer v value of equivalent ASCII character. 
 */
static int char_to_digit(char ch)
{
   if (isNum2(ch)) {
      return ch - ZERO_ASCII_VALUE;
   }
   else {
      return ALPHABET_DIFFERENCE + (ch - ASCII_CHAR_VALUE_A);
   }
}

/**
 * digit_to_char is a fuction that translates integer values into
 * ASCII value characters
 * 
 * @param ch is an integer value  
 * @return char value of equivalent ASCII integer. 
 */
static char digit_to_char(int ch)
{
   if (ch >= 0 && ch <= BASE_32_NUM_NINE) {
      return ch + ZERO_ASCII_VALUE;
   }
   else {
      return ASCII_CHAR_VALUE_A + (ch - ALPHABET_DIFFERENCE);
   }
}

long readNumber()
{
   // // Value we've parsed so far.
   long value = 0;
   _Bool sign = false;

   //   // Get the next input character.
   char ch = getchar();
   if (ch == '-') {
      sign = true;
      ch = getchar();
   }
   //   // Keep reading as long as we're seeing digits.
   while (validBase(ch)) {  // ch is a digit in base 32
      // Convert from ASCII code for the next digit into the value
      // of that digit.  For example 'A' -> 10 or '7' -> 7
      long d = char_to_digit(ch);
      // Slide all digits we've read so far one place value to the
      // left.
      checkMul(value, BASE_THIRTY_TWO);
      value = value * BASE_THIRTY_TWO;
      //     // Add this digit as a new, low-order digit.
      checkAdd(value, BASE_THIRTY_TWO);
      value = value + d;
      //     // Get the next input character.
      ch = getchar();
   }
   // ch was one character past the end of the number.  Put it back on
   // the input stream so it's there for other code to parse (see notes
   // below about ungetc()).
   ungetc(ch, stdin);
   if (sign) {
      //checkMul(value, -1);
      return value * -1;
   }
   return value;
}

void printNumber(long val)
{
   if(val == LONG_MIN){
      printf("-8000000000000");
      return;
   }
   if (val < 0) {
      putchar('-');
      val = 0 - val;
   }
   if (val == 0) {
      putchar(digit_to_char(val));
      return;
   }
   if (val < BASE_THIRTY_TWO) {
      char print = digit_to_char(val);
      putchar(print);
      return;
   }
   long d = val % BASE_THIRTY_TWO;
   checkDiv(val, BASE_THIRTY_TWO);
   long val_new = val / BASE_THIRTY_TWO;
   printNumber(val_new);
   char ch = digit_to_char(d);
   putchar(ch);
}
