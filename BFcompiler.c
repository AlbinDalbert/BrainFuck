#include "BFcompiler.h"

void correctUsage(){
  fprintf(stderr, "Invalid Usage");
  fprintf(stderr, "\nBFcompiler fileName [source code] outputFile\n");
  exit(1);
}

int main (int argc, char *argv[]) {
  // int *tape = callow(1,4096);

  FILE *code; 
  FILE *output;

  if (argc > 1)
  {
    code = fopen(argv[1], "r");
  }
  else {
    correctUsage();
  }
  
  if( argc == 2)
  {  
    output = stdout;
  }
  else if(argc == 3){
    output = fopen(argv[1], "w+");
  }
  else {
    correctUsage();
  }

  return 0;
}
