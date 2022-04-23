#include "BFcompiler.h"
#define MAX_CODE_LENGTH 100000

void correctUsage(){
  fprintf(stderr, "Invalid Usage");
  fprintf(stderr, "\nBFcompiler BFCodeFile\n");
  exit(1);
}

int grammer_check(char *code){

  if (recursive_loop_grammer_check(code) == 0)
  {
    return 0;
  }

  return 1;
}

int recursive_loop_grammer_check(char *code){
  if (code[0] == '\0')
  {
    return 1;
  }

  if (code[0] == '[')
  {
    if (recursive_loop_grammer_check(code + 1) == 0)
    {
      return 0;
    }

    if (code[1] == ']')
    {
      return recursive_loop_grammer_check(code + 2);
    }
    else
    {
      return 0;
    }
  }
  else if (code[0] == ']')
  {
    return 0;
  }
  else
  {
    return recursive_loop_grammer_check(code + 1);
  }
}

//read file char by char and return a string
char *readFile(FILE *file){


  char *code_string = malloc(sizeof(char) * MAX_CODE_LENGTH);
  int i = 0;
  while(!feof(file)){
    code_string[i] = fgetc(file);
    i++;
  }
  code_string[i] = '\0';
  fclose(file);
  return code_string;
}

FILE *generateCIntermediateFile(char *code) {

  FILE *cCode = fopen("brainfuck.c", "w");
  fprintf(cCode, "#include <stdio.h>\n");
  fprintf(cCode, "#include <stdlib.h>\n");
  fprintf(cCode, "int main(int argc, char *argv[]){\n");
  fprintf(cCode, "char array[30000] = {0}; char *ptr = array;\n");
  while (*code != '\0') {
    switch (*code) {
    case '>':
      fprintf(cCode, "++ptr;\n");
      break;
    case '<':
      fprintf(cCode, "--ptr;\n");
      break;
    case '+':
      fprintf(cCode, "++*ptr;\n");
      break;
    case '-':
      fprintf(cCode, "--*ptr;\n");
      break;
    case '.':
      fprintf(cCode, "putchar(*ptr);\n");
      break;
    case ',':
      fprintf(cCode, "*ptr = getchar();\n");
      break;
    case '[':
      fprintf(cCode, "while (*ptr) {\n");
      break;
    case ']':
      fprintf(cCode, "}\n");
      break;
    default:
      break;
    }
    code++;
  }
  fprintf(cCode, "return 0;\n");
  fprintf(cCode, "}\n");

  return cCode;
}

// print file to stdout
void printFile(FILE *file){
  char c;
  while((c = fgetc(file)) != EOF){
    putchar(c);
  }
  fclose(file);
}

// ------ This is the main function ------

int main (int argc, char *argv[]) {

  FILE *code; 
  FILE *output;

  if (argc > 1)
  {
    code = fopen(argv[1], "r");
  }
  else {
    correctUsage();
  }

  if(code == NULL){
    fprintf(stderr, "Error opening file\n");
    exit(1);
  }
  
  if( argc == 2)
  {  
    output = stdout;
  }

  else {
    correctUsage();
  }

  char *code_string = readFile(code);

  if (1 == grammer_check(code_string))
  {
    fprintf(stderr, "Grammer check failed\n");
    exit(1);
  }

  // Generate the C code
  FILE *cBrainfuck = generateCIntermediateFile(code_string);

  printFile(cBrainfuck); // removing this line will cause the compiler to fail, I don't know why!

  // Compile the C code
  int status = system("gcc brainfuck.c -o brainfuck");

  if (status != 0)
  {
    fprintf(stderr, "Compilation failed\n");
    exit(1);
  }

  // Execute the C code
  status = system("./brainfuck");

  if (status != 0)
  {
    fprintf(stderr, "Execution failed\n");
    exit(1);
  }

  return 0;
}


