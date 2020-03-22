#include<stdio.h>

int fib(int n);

int main(void){
    
    int number;
    int i;
    
    printf("Enter the number:");
    scanf("%d",&number);
    
    for(i=0;i<=number;i++){
    printf("F%d=%d\n",i,fib(i));
    }
    
}

int fib(int n)
{
    int pre =1 ;
    int i = n;
    n = 0;
    int sum = 0;
    while (i > 0) {
        i--;
        sum = n + pre;
        pre = n;
        n = sum;
    }
    return n;
}
