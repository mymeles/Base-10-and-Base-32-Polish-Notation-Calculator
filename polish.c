/**
 * @file polish.c
 * @author Meles Meles(mymeles)
 * 
 * polish.c is a file that preforms calculation on numbers, represented in either 
 * base10 or base32. it preforms the operations such as, subtraction, addition, 
 * division, multiplication and exponents. If the program reads invalid input, it 
 * exits with a status of 102, if over flow happens program exits out with a 
 * status of 100 or 101 if a number is being divided by 0. otherwise, if the 
 * program exits successfully then it returns with a value of 1. 
 */
#include <stdio.h>
#include <stdbool.h>
#include "bounds.h"
#include "base.h"

/**
 * exponent is a fuction that computes the value a to the power of b. 
 * @param base is a long type that is the base of the exponent
 * @param power is a long type that is the power of the exponents 
 * @return an integer of the computed value of a to the power of b 
 */
static long exponent(long base, long power){
   if ( power !=  0 ){ 
      long a = base;
      checkSub(power, -1);
      long b = exponent(base, power-1);
      checkMul(a, b);
      return a*b;
   } else {
      return 1;
   }
}

/**
 * This method isNum checks if a character is a number from zero to nine(0-9).
 * 
 * @param ch is type character that is validated weather it is a 
 * number or not.
 * @return _Bool  true if ch is a number from 0-9 or else false
 */
static _Bool isNum(char ch)
{
   return ch >= ZERO_ASCII_VALUE && ch <= NINE_ASCII_VALUE;
}

/**
 * This method isChar checks if a character is from value 'A' to 'V'.
 * 
 * @param ch is type character that is validated weather it is a 
 * number or not in base32.
 * @return _Bool  true if ch is a number from 0-9 or else false
 */
static _Bool isChar(char ch)
{
   return ch >= ASCII_CHAR_VALUE_A && ch <= ASCII_CHAR_VALUE_V;
}

/**
 * isValidInput is a fuction that checks if the inputs read from the 
 * standard input is a valid one. 
 * @param ch is a char type read from the standard input
 * @return _Bool true if the character is valid, else false.
 */
static _Bool isValidInput(char ch)
{
   return isChar(ch) || isNum(ch) || ch == '~' || ch == '+' || ch == '*' || 
   ch == '/' || ch == ' ' || ch == '-' || ch == '\n' || ch == '^';
}

/**
 * parseExpression is a function that parses through a polish expression 
 * and computes the value and returns it. It reads the polish expression 
 * from the standard input and parses though it character by character. 
 * It preforms the operation addition, subtraction, multiplication, division
 * and exponentiation. It checks for overflow in the operations and when it 
 * occurs it exits the program with an exit status of 101. Also, if the input 
 * read is not a valid character or valid polish expression it exits the 
 * program with a status of 102. 
 * 
 * @return type long of the computed value from the polish expression. 
 */
static long parseExpression()
{
   long a, b = 0;
   char ch = getchar();
   if (ch == EOF || !isValidInput(ch)){
      exit(FAIL_INPUT);
   }
   if (isNum(ch) || ch == '-') {
      ungetc(ch, stdin);
   }

   while (ch == ' ' || ch == '\n') {
      ch = getchar();
      if (!isValidInput(ch)) {
         exit(FAIL_INPUT);
      }
      if (isNum(ch)) {
         ungetc(ch, stdin);
         break;
      }
      if (ch != ' ') {
         if (ch == '~' || ch == '+' || ch == '*' || ch == '/' || ch == '^') {
            break;
         }
         else {
            ungetc(ch, stdin);
            break;
         }
      }
   }
   if (ch == '+'){
      a = parseExpression();
      b = parseExpression();
      checkAdd(a, b);
      return a + b;
   }
   else if (ch == '~') {
      a = parseExpression();
      b = parseExpression();
      checkSub(a, b);
      return a - b;
   }
   else if (ch == '*') {
      a = parseExpression();
      b = parseExpression();
      checkMul(a, b);
      return a * b;
   }
   else if (ch == '/') {
      a = parseExpression();
      b = parseExpression();
      checkDiv(a, b);
      return a / b;
   }
   else if (ch == '^'){
      a = parseExpression();
      b = parseExpression();
      long c = 0;
      if(b < 0){
         checkMul(-1, b);
         c = exponent(a, -1*b);
         checkDiv(1, c);
         return 1/c;
      }else{
         return exponent(a, b);
      }    
   } 
   else {
      ch = getchar();
      if (!isValidInput(ch) || ch == EOF) {
         exit(FAIL_INPUT);
      }
      else{
         ungetc(ch, stdin);
      }
      return readNumber();
   }
}

/**
 * main is the start of the program. It uses the parseExpression() fuction to 
 * evaluate the polish expressions read from the standard input either in base32 or base10 
 * until it reaches EOF. 
 * @return program exit status 
 */
int main()
{
   long print = parseExpression();
   printNumber(print);
   putchar('\n');
   char ch = getchar();
   while (ch != EOF) {
      if (ch != '\n' && ch != ' ') {
         ungetc(ch, stdin);
         printNumber(parseExpression());
         putchar('\n');
      }
      ch = getchar();
   }
   return EXIT_SUCCESS;
}
