#include<stdio.h>

//宣告function 
char uppercased(char c[]);
char lowercased(char c[]);
char reversed(char c[]);

 int main(void){
 	char before [100] = {0};
 	
 	printf("Enter a string:\n");
 	gets (before);
 	
	printf("Your input is: %s \n",(before));
 	
 	uppercased(before);
 	
 	lowercased(before);
 	
 	reversed(before);
 } 
 
 char uppercased(char c[]){
 	int C , B;
 	char b [100] = {0};
 	
	printf("The string after uppercased is ");
	
	//使用ASCII碼將小寫轉成大寫 
	for(B=0,C=0;C<=strlen(c)-1;B++,C++){
 		if(c[C]>='a'&&c[C]<='z'){
		   b[B]=c[C]-32;
		   printf("%c",b[B]);
 	    }
 		
		 //若原字元為大寫則不需改變 
 		else{
		   b[B]=c[C];
		   printf("%c",b[B]);
		}
	}
	printf("\n");
 	return 0;
 }
 	  
 char lowercased(char c[]){
	int C , B;
 	char b [100] = {0};
 	
 	printf("The string after lowercased is: ");
 	
 	//使用ASCII碼將大寫轉成小寫 
 	for(B=0,C=0;C<=strlen(c)-1;B++,C++){
 		if(c[C]>='A'&&c[C]<='Z'){
		   b[B]=c[C]+32;
 		   printf("%c",b[B]);
 	  }
 	  
 	   //若原字元為小寫則不需改變 
 	  else{
 	  	b[B]=c[C];
 	  	printf("%c",b[B]);
	   }
	}
	printf("\n");
 	return 0;
 }

char reversed(char c[]){
	int C , B;
 	char b [100] = {0};
	
	printf("When we make your input string reversed: ");
 	
 	//將原字串中字元顛倒，故原字串中字元需遞減，新字串中字元需遞增 
 	for(B=0, C=strlen(c)-1; C>=0; B++,C--){
 		b[B]=c[C];
 		printf("%c",b[B]);
	 }
	printf("\n");
}
