#include<Stdio.h>
long sum(int number);

int main (void){
	int num=0;
	printf("Please enter the number:");
	scanf("%d",&num);
	printf("Sum is %ld",sum(num));
}

long sum(int number){
	if(number<=0){
		return 0;
	}
	if(number%2==0){
		return -number+sum(number-1);
	}
	else{
		return number+sum(number-1);
	}
}
