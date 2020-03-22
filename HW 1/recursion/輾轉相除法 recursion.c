#include<stdio.h>

int GCD(int a , int b);

int main(void){
	
	int c;
	int d;
	
	printf("Enter 2 number:");
	scanf("%d %d",&c,&d);
	
	printf("(%d,%d)=%d",c,d,GCD(c,d));
	
  }
    int GCD(int a, int b){
	   
	if(b==0){
 	return a;
 }
 	else{
	 return GCD(b,a%b);
}
}
