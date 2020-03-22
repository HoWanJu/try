#include <stdio.h>
#include <stdlib.h>
void  multiply(char *x,char *y){
	long a,b =0;
	a=strtol(x,NULL,10);
	b=strtol(y,NULL,10);
	printf("Ans = %d\n",a*b);
}