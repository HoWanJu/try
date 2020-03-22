#include<stdio.h>
#define SIZE 100 

void reverse(char *a ,char *b);

void revPrint(char* string);

int main(void){
	char original[SIZE]={0};
	
	printf("Enter a string:");
	gets(original);
	revPrint(original);
	printf("The reversed string is: %s",original);
	
	return 0;
}

void reverse(char *a, char *b){
	
	//用a(第一個字元)與b(第二個字元)的位置做比較進而swap 
	if(a>=b){
		return;
	}
	else{
		char temp=*a; 
		*a=*b; 
		*b=temp; 
		
		reverse(a+1,b-1); 
	}
}

void revPrint(char *string){
	int i=0;
	
	//計算字串長度 
	while(string[i]!='\0'){
		i++;
	}
	
	//reverse(第一個字元,最後一個字元)
	reverse(string,string+i-1);
}


