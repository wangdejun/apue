#include "apue.h"
#include <sys/wait.h>

int main(void)
{
  char line[MAXLINE];
  FILE  *fpin;
  printf("pre-A");
  if((fpin = popen("myuclc", "r")) == NULL)
    printf("popen error");
  
  for(;;){
    fputs("prompt> ", stdout);
    fflush(stdout);
    printf("A");
    
    if(fgets(line, MAXLINE, fpin) == NULL)
      printf("B");
      break;
    if(fputs(line, stdout)==EOF)
      printf("fputs error to pipe.");
  }

  if(pclose(fpin) == -1)
    printf("pclose error");

  putchar('\n');

  exit(0);
}
