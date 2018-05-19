#include "apue.h"
int main(void){
  printf("uid = %d, \npid=%ld,\ngid = %d\n", getuid(), (long)getpid(),getgid());
	exit(0);
}
