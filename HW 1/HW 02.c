#include<stdio.h>
#include<math.h>
double dbinom (int k, int n, double p);

int main(void){
	int num1=0;
	int num2=0;
	double num3=0;
	
	printf("Enter three numbers");
	scanf("%d %d %lf",&num1,&num2,&num3);
	
	dbinom(num1,num2,num3);
} 

double dbinom(int k,int n,double p){
	long result_1=1;
	int i;
	double result_2=0;
	double ANS=0;
	
	if(k>n-k){
		k=n-k;
	}
	
	//先計算C n取k的部分 
	for(i=0;i<k;i++){
		result_1=result_1*(n-i)/(i+1);
	}
	
	//在計算後面機率的部分 
	result_2=(pow(p,k))*(pow((1-p),(n-k)));
	
	ANS=result_1*result_2;
	
	printf("dbinom(%d,%d,%.1f)=%f",k,n,p,ANS);
}
