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
			break;//�Ŧr�����X�j�� 
		}
		if(a[i]!=a[i+1]){
			//�p�G�U�@�Ӧr�����>max�h�����U�@�Ӧr����׳̪� 
			if(counter>max){
				max=counter;
				longest=temp;
			}
			//counter�k��1�A�r��Ȧs��temp 
				temp=a[i+1];
				counter=1;
		}
		//�W�Ӧr������U�@�Ӫ��ܡAcounter++ 
		else{
			counter++;
		}	
	}
	printf("The longest identical character is %c, the length is %d.",longest,max);
}
