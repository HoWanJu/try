#include<stdio.h>
#define SIZE 100

char function(char a[]);

int main(void){
	char a[SIZE]={0};
	printf("Enter a sring:");
	scanf("%s",a);
	function(a);
}

char function(char a[]){
	int max=0;
	int i;
	char longest;
	char temp=a[0];
	int counter=1;
	int j;
	
	for(i=0;i<SIZE;i++){
		if(a[i+1]==NULL){
			break;//空字元跳出迴圈 
		}
		if(a[i]!=a[i+1]){
			//如果下一個字串長度>max則換成下一個字串長度最長 
			if(counter>max){
				max=counter;
				longest=temp;
			}
			//counter歸為1，字串暫存於temp 
				temp=a[i+1];
				counter=1;
		}
		//上個字元等於下一個的話，counter++ 
		else{
			counter++;
		}	
	}
	printf("The longest identical character is %c, the length is %d.",longest,max);
}
