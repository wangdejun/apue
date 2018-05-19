#include "apue.h"

int main(void){
  int n;
  int fd[2];
  pid_t pid;
  char line[MAXLINE];

  if(pipe(fd) < 0)
    printf("pipe error");

  if((pid = fork())<0){
    printf("fork error");
  }else if(pid>0){
    printf("1.in the Parent process!");
    close(fd[0]);
    write(fd[1], "Hello World!\n", 12);
  }else{
    printf("2.in the Child process!");
    close(fd[1]);
    n = read(fd[0], line, MAXLINE);
    write(STDOUT_FILENO, line, n);
  }
  exit(0);
}
