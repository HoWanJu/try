#include<stdio.h>

int listSumOfConNum(int z);

int main(void){
	int sum=0;
	
	printf("Enter the number:\n");
	scanf("%d",&sum);
	
	listSumOfConNum(sum);
} 

int listSumOfConNum(int z){
	int a,b;
	int now_sum;
	int counter=0;//計算有沒有找到 
	for(a=1;a<z;a++){
		now_sum=0;
		for(b=a;b<z;b++){
			now_sum+=b;//從首相開始加的總和 
			if(now_sum>z){
				break;
			}
			else if(now_sum==z){//如果總和等於輸入的數值則輸出 
				printf("Sum of %d to %d is %d\n",a,b,z);
				counter++;
				break;
			} 
		}
	}
	if(counter==0){
		printf("Not Found!\n");
	}
}
