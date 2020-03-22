#include<stdio.h>
#include"hello.h"

int main(void){
	int number=0;
	printf("Enter the number:");
	scanf("%d",&number);
	
	printf("%d",sum(number));
} 