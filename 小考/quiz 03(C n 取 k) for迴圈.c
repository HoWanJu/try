#include<stdio.h>
#include<math.h>
long combn(int n,int k);

int main(void){
	int num1=0;
	int num2=0;

	printf("Enter two numbers:");
	scanf("%d %d",&num1,&num2);

	printf("combn(%d,%d)=%ld",num1,num2,combn(num1, num2)); 
}

long combn(int n,int k){
	int i;
	long result=1;
	
	if(k>n-k){
		k=n-k;
	}
	
	for(i=0;i<k;i++){
		result=result*(n-i)/(i+1);
	}
	return result;
}  
