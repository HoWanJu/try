#include<stdio.h>

int function(char string1[],char string2[]);

 int main(void){
 	char a[100]={0};
 	char b[100]={0};
 	
 	printf("Enter char1:");
 	gets(a);
 	
 	printf("Enter char2:");
 	gets(b);
 	
 	function(a,b);
 	
 	return 0;
 }
 
 int function(char string1[], char string2[]){
 	int i;
 	int counter=0;
 	int j=0;
 	int k=0;
 	
 	//�p��string1���r����� 
 	while(string1[j]!='\0'){
 		j++;
	 }
	 
	//�p��string2���r����� 
	while(string2[k]!='\0'){
		k++;
	}
	
	//���פ��P�Ǧ^-1 
 	if(j!=k){
 		printf("-1");
	 }
	
	//����r�ꤺ�e 
	else{
		for(i=0;i<j;i++){
			if(string1[i]!=string2[i]) {
				counter++;
			}
		}
	printf("mismatched_char(%s,%s)=%d",string1,string2,counter);
	}
}
