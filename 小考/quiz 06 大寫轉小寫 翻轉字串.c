#include<stdio.h>
#include<string.h> 

//宣告function 
char uppercased(char c[]);
char lowercased(char c[]);
char reversed(char c[]);

 int main(void){
 	char original [100] = {0};
 	
 	printf("Please enter a line:\n");
 	gets (original);
 	
 	uppercased(original);
 	
 	lowercased(original);
 	
 	reversed(original);
 } 
 
 char uppercased(char c[]){
 	int i;
 	char b[100]={0};
	
	printf("Uppercased: ");
	
	//使用ASCII碼將小寫轉成大寫 
	for(i=0;i<=strlen(c)-1;i++){
 		if(c[i]>='a'&&c[i]<='z'){
		   b[i]=c[i]-32;
		   printf("%c",b[i]);
 	    }
 		
		 //若原字元為大寫以外則不需改變 
 		else{
		   b[i]=c[i];
		   printf("%c",b[i]);
		}
	}
	printf("\n");
 	return 0;
 }
 	  
 char lowercased(char c[]){
	int i;
	char b[100]={0};
	
 	printf("Lowercased: ");
 	
 	//使用ASCII碼將大寫轉成小寫 
 	for(i=0;i<=strlen(c)-1;i++){
 		if(c[i]>='A'&&c[i]<='Z'){
		   b[i]=c[i]+32;
 		   printf("%c",b[i]);
 	  }
 	  
 	   //若原字元為大寫以外則不需改變 
 	  else{
 	  	b[i]=c[i];
 	  	printf("%c",b[i]);
	   }
	}
	printf("\n");
 	return 0;
 }

char reversed(char c[]){
	int i , B;
 	char b [100] = {0};
	
	printf("String after reversed: ");
 	
 	//將原字串中字元顛倒，原字串中字元遞減，新字串中字元遞增 
 	for(B=0, i=strlen(c)-1; i>=0; B++,i--){
 		b[B]=c[i];
 		printf("%c",b[B]);
	 }
	printf("\n");
}
