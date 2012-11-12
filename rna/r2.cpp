#include <stdio.h>
#include <ctype.h>

int main()
{
  int c;

  while ( (c = getchar()) != EOF )
    printf("%c", toupper(c)=='T'? 'U' : c);

  printf("\n");
}
