#include<stdio.h>

unsigned long long fibonacci(unsigned int n);

int main (void)
{
	unsigned int a;
	
	printf("Enter an integer:");
	scanf("%u",&a);
	
	unsigned long long int result = fibonacci(a);
	
	printf("Fibonacci(%u)=%llu\n",a,result);
 } 
 
  unsigned long long int fibonacci(unsigned int n)
 {
 
  if (0==n||1==n){
 	return n;
 }	
  else{
 	return fibonacci(n-1)+fibonacci(n-2);
 }
 }
