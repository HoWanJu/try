#include<stdio.h>
#include<math.h>

int listSumOfTwoSqrt(int n);

int main(void){
	int number;//使用者輸入的值 
	
	printf("Enter the number:");
	scanf("%d",&number);
	
	listSumOfTwoSqrt(number);//呼叫函式 
	
} 

int listSumOfTwoSqrt(int n){
	
	int a;
	int b;
	int c=sqrt(n);//將輸入值得開根號代入C 
	int found=0; //計算找到的數字有多少 
		  
	for(a=1;a<=c/2+1;a++){//a的範圍為開根號除2再加1，為了不避免算到重覆數字 
		for(b=1;b<=c;b++){
			if(a*a+b*b==n){
				printf("%d^2+%d^2=%d\n",a,b,n);
				found++;
			}
		}
	}
	
	if(found==0){
		printf("Not Found!!");
	}
}
