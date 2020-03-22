#include<stdio.h>

int main(void){
	int number=0;
	int a=0;
	int b=0;
	int c=0;
	int total=0;
	int i;
	int counter=-1;
	int quotient=0;
	int sum=0;
	int num=0;
	
	printf("Please enter an number:");
	scanf("%d",&number);
	
	num=number;
	
   c=number%10;
	
	do{
		quotient=number/10;
		number=quotient;
		counter++;
	}
	while(quotient!=0);
	
	for(i=1;i<=counter;i++){
	a=num/10;
	b=a%10;
	num=a;
	total+=b;
   }
   
   sum=total+c;
   
   printf("%d is the sum of digits.\n",sum);
}
