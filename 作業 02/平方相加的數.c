#include<stdio.h>
#include<math.h>

int listSumOfTwoSqrt(int n);

int main(void){
	int number;//�ϥΪ̿�J���� 
	
	printf("Enter the number:");
	scanf("%d",&number);
	
	listSumOfTwoSqrt(number);//�I�s�禡 
	
} 

int listSumOfTwoSqrt(int n){
	
	int a;
	int b;
	int c=sqrt(n);//�N��J�ȱo�}�ڸ��N�JC 
	int found=0; //�p���쪺�Ʀr���h�� 
		  
	for(a=1;a<=c/2+1;a++){//a���d�򬰶}�ڸ���2�A�[1�A���F���קK��쭫�мƦr 
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
