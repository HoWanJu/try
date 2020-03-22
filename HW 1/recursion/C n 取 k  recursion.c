#include<stdio.h>

long long int combn(int n) ;


int main(void){
  int N=0;
  int K=0;
  int result=0;
  
  printf("Please enter two  positive integers n and k (n choose k):\n");
  scanf("%d %d",&N,&K);
  
  result=combn(N)/((combn(K)*combn(N-K)));//combn(N,K)=先算N!再除以(K!乘(N-K!)) 
  
  printf("combn(%d,%d)=%lld",N,K,result);
}

long long int combn(int n){
	
	if(n==1){
		return 1;
	}
	else{
		return n*combn(n-1);//先算出n! 
	}
}


