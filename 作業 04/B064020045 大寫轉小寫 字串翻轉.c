#include<stdio.h>

//�ŧifunction 
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
	
	//�ϥ�ASCII�X�N�p�g�ন�j�g 
	for(B=0,C=0;C<=strlen(c)-1;B++,C++){
 		if(c[C]>='a'&&c[C]<='z'){
		   b[B]=c[C]-32;
		   printf("%c",b[B]);
 	    }
 		
		 //�Y��r�����j�g�h���ݧ��� 
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
 	
 	//�ϥ�ASCII�X�N�j�g�ন�p�g 
 	for(B=0,C=0;C<=strlen(c)-1;B++,C++){
 		if(c[C]>='A'&&c[C]<='Z'){
		   b[B]=c[C]+32;
 		   printf("%c",b[B]);
 	  }
 	  
 	   //�Y��r�����p�g�h���ݧ��� 
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
 	
 	//�N��r�ꤤ�r���A�ˡA�G��r�ꤤ�r���ݻ���A�s�r�ꤤ�r���ݻ��W 
 	for(B=0, C=strlen(c)-1; C>=0; B++,C--){
 		b[B]=c[C];
 		printf("%c",b[B]);
	 }
	printf("\n");
}
