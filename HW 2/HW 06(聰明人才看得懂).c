#include<stdio.h>
#include<math.h>

int listSumOfConNum(int z);

int main(void){
	int number=0;
	printf("Enter the number:\n");
	scanf("%d",&number);
	listSumOfConNum(number);
}
int listSumOfConNum(int sum){
	// 单畉计―㎝そΑ Sum = n*A1 + n*(n-2)/2;  
    // sum 璶╊だ俱计  
    // n ╊だ硈尿礛计计  
    // A1 硈尿礛计い材计 
	int i;
	int j;
	for(i=1;i<=sum/2;i++){
		int A1=i;
		int key=(2*A1-1)*(2*A1-1)+8*sum;//腹ず计 
		int root= sqrt(key);
		int ans=root-2*A1+1;//ゲ案计临璶埃2珿ゲ2计 
		
		if(root*root!=key){
			continue;
		} 
		else if(ans%2!=0){
			continue;
		}
		
		else{
				printf("Sum of %d to %d is %d %d",i,i+ans/2-1,sum);
			printf("\n");	
		}
  
	}
		
}
 
