#include<stdio.h>

int gcd(int number1, int number2);
int lcm(int Number1, int Number2);

int main(void){
	int a=0;
	int b=0;
	
	printf("Enter 2 numbers:");
	scanf("%d %d",&a,&b);
	
	printf("lcm(%d,%d)=%d",a,b,lcm(a,b));
	
	return 0;
} 

//�p��̤j���]�� 
int gcd(int number1, int number2){

	if(number2==0){
		return number1;
	}
	else{
		return gcd(number2,number1%number2);
	}
}

//�p��̤p������ 
int lcm(int Number1, int Number2){
	return Number1/gcd(Number1,Number2)*Number2;
}
