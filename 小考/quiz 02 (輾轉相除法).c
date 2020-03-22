#include<stdio.h>
int main(void){
	int a, b, gcd;  
	
	a = 64; b = 30;  
	
	printf("gcd(%d,%d) = ",a,b);  
	
	while(a>0&&b>0){
	
	if(a>b){
	  a=a%b;
      }

    else{
	  b=b%a;
      }
  }
	
	if(a==0){
		gcd=b;
		}
	
	else{
		gcd=a;
	}
 
    printf("%d\n", gcd);
    return(0);  
}
