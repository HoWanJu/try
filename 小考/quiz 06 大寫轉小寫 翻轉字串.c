#include<stdio.h>
#include<string.h> 

//�ŧifunction 
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
	
	//�ϥ�ASCII�X�N�p�g�ন�j�g 
	for(i=0;i<=strlen(c)-1;i++){
 		if(c[i]>='a'&&c[i]<='z'){
		   b[i]=c[i]-32;
		   printf("%c",b[i]);
 	    }
 		
		 //�Y��r�����j�g�H�~�h���ݧ��� 
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
 	
 	//�ϥ�ASCII�X�N�j�g�ন�p�g 
 	for(i=0;i<=strlen(c)-1;i++){
 		if(c[i]>='A'&&c[i]<='Z'){
		   b[i]=c[i]+32;
 		   printf("%c",b[i]);
 	  }
 	  
 	   //�Y��r�����j�g�H�~�h���ݧ��� 
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
 	
 	//�N��r�ꤤ�r���A�ˡA��r�ꤤ�r������A�s�r�ꤤ�r�����W 
 	for(B=0, i=strlen(c)-1; i>=0; B++,i--){
 		b[B]=c[i];
 		printf("%c",b[B]);
	 }
	printf("\n");
}
