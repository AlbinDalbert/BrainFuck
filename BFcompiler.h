#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]);

//FILE *GenerateCIntermediateFile(char *code);

int recursive_loop_grammer_check(char *code);

int grammer_check(char *code);

void correct_usage();
/*
This whole compiler is purely based on the description of the language on it's Wikipedia at the time of coding. 
But here I will write the specifications (copied from wikipedia).
---------------------------------------------------------------------------------------

  >   Increment the data pointer (to point to the next cell to the right).

  <   Decrement the data pointer (to point to the next cell to the left).

  +   Increment (increase by one) the byte at the data pointer.

  -   Decrement (decrease by one) the byte at the data pointer.

  .   Output the byte at the data pointer.

  ,   Accept one byte of input, storing its value in the byte at the data pointer.

  [   If the byte at the data pointer is zero, 
      then instead of moving the instruction pointer forward to the next command, 
      jump it forward to the command after the matching ] command.

  ]   If the byte at the data pointer is nonzero, 
      then instead of moving the instruction pointer forward to the next command, 
      jump it back to the command after the matching [ command.

---------------------------------------------------------------------------------------

C specifications:
---------------------------------------------------------------------------------------
  >   ++ptr;

  <   --ptr;

  +   ++*ptr;

  -   --*ptr;

  .   putchar(*ptr);

  ,   *ptr = getchar();

  [   while (*ptr) {

  ]   }
---------------------------------------------------------------------------------------

To make a fully working compiler. We will first design a grammer for the language, 
which should be very easy in for this language.

Because of the nature of the language, there is a lot we don't need to do, 
and we can simply check if the C translation will be acceptable by the C compiler.

*/