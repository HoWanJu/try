#include<stdio.h>

int Fabonacci(int n);

int main(void){
    
    int number;
    int i;
    
    printf("Enter the number:");
    scanf("%d",&number);
    
    for(i=1;i<=number;i++){
    printf("F%d=%d\n",i,Fabonacci(i));
    }
    
}

int Fabonacci(int n){
    int a=0;//Fn 
    int b=1;//F1
    int c;//F3
    int i;//for°j°éªºÅÜ¼Æ 
    
    if(0==n||1==n){
        return n;
    }
    
    else{
      for(i=2;i<=n;i++){
        c=a+b;//Fn = Fn-1 + Fn-2
        a=b;
        b=c;
        }
		return c;
	}
    
}
