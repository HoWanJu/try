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
	
	//��a(�Ĥ@�Ӧr��)�Pb(�ĤG�Ӧr��)����m������i��swap 
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
	
	//�p��r����� 
	while(string[i]!='\0'){
		i++;
	}
	
	//reverse(�Ĥ@�Ӧr��,�̫�@�Ӧr��)
	reverse(string,string+i-1);
}


