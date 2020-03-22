#include<stdio.h>
int main(void){
	int grade=0;
	int sum=0;
	float average=0;
	int passed=0;
	int failed=0;

	printf("Enter the grade:");
	scanf("%d",&grade);
		
	while(grade!=-1){

	if(grade>=60){
		printf("Pass\n");
		passed++;
		sum+=grade;
	}
	else{
		printf("Fail\n");
		failed++;
		sum+=grade;
	}
	
	printf("Enter the grade:");
	scanf("%d",&grade);
	
    }
    
    average=sum/(passed+failed);
    printf("Output:");
    printf("Average is %.2f\n",average);
    printf("Pass: %d\n",passed);
    printf("Fail: %d\n",failed);
}
