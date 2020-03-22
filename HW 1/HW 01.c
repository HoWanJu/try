#include<stdio.h>
#include<math.h>
double leibnin(int a);

int main(void){
	int number;
	printf("Enter a number to calculate PI:");
	scanf("%d",&number);
	
	leibnin(number);
	
}
double leibnin(int a){
	double total=0;
	double pi=0;
	int i;
	
	//≠p∫‚PI 
	for(i=0;i<=a;i++){
		pi=(pow((-1),i))/(2*i+1);
		total+=pi;
	}
	total=total*4;
	printf("%lf",total);
}
