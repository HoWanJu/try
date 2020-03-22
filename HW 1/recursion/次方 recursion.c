#include<Stdio.h>
long power(int base,int exp);

int main (void){
	int num1=0;
	int num2=0;
	printf("Power(base,exp)=");
	scanf("%d %d",&num1,&num2);
	printf("Sum is %ld",power(num1,num2));
}

long power(int base,int exp){
	if(base==0){
		return 0;
	}
	if(exp==0){
	    return 1;
	}
	if(exp<0){
		return 0;
	}
	else{
		return (base*power(base,exp-1));
	}
}
