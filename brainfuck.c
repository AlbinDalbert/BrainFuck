#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
char array[30000] = {0}; char *ptr = array;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
while (*ptr) {
++ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
while (*ptr) {
++ptr;
++*ptr;
++*ptr;
++ptr;
++*ptr;
++*ptr;
++*ptr;
++ptr;
++*ptr;
++*ptr;
++*ptr;
++ptr;
++*ptr;
--ptr;
--ptr;
--ptr;
--ptr;
--*ptr;
}
++ptr;
++*ptr;
++ptr;
++*ptr;
++ptr;
--*ptr;
++ptr;
++ptr;
++*ptr;
while (*ptr) {
--ptr;
}
--ptr;
--*ptr;
}
++ptr;
++ptr;
putchar(*ptr);
++ptr;
--*ptr;
--*ptr;
--*ptr;
putchar(*ptr);
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
++*ptr;
putchar(*ptr);
putchar(*ptr);
++*ptr;
++*ptr;
++*ptr;
putchar(*ptr);
++ptr;
++ptr;
putchar(*ptr);
--ptr;
--*ptr;
putchar(*ptr);
--ptr;
putchar(*ptr);
++*ptr;
++*ptr;
++*ptr;
putchar(*ptr);
--*ptr;
--*ptr;
--*ptr;
--*ptr;
--*ptr;
--*ptr;
putchar(*ptr);
--*ptr;
--*ptr;
--*ptr;
--*ptr;
--*ptr;
--*ptr;
--*ptr;
--*ptr;
putchar(*ptr);
++ptr;
++ptr;
++*ptr;
putchar(*ptr);
++ptr;
++*ptr;
++*ptr;
putchar(*ptr);
return 0;
}
