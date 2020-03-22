#include<stdio.h>
int sum(int n);

int main(void){
	int number=0;
	printf("Enter the number:");
	scanf("%d",&number);
	
	printf("%d",sum(number));
} 

int sum(int n){
	if(n==0){
		return 0;
	}
	
	if(n<0){
		return (-n%10+sum(-n/10));
	}
	
	else{
		return n%10+sum(n/10);
	}
}
