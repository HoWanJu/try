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
	// ���t�ƦC�D�M���� Sum = n*A1 + n*(n-2)/2;  
    // sum ���n�������ơA  
    // n �������s��۵M�ƭӼ�  
    // A1 ���s��۵M�Ƥ����Ĥ@��� 
	int i;
	int j;
	for(i=1;i<=sum/2;i++){
		int A1=i;
		int key=(2*A1-1)*(2*A1-1)+8*sum;//�ڸ������� 
		int root= sqrt(key);
		int ans=root-2*A1+1;//�������ơA�]���٭n���H2�A�G����2������ 
		
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
 
