#include<stdio.h>
#include<string.h>

int main(void){
	FILE *file1=fopen("file1.txt","r");
	FILE *file2=fopen("file2.txt","r");
	char string[30];
	int i;
	int number=1;
	
	//find file1
	if(file1==NULL){
		puts("File could not be opened.");
	}
	
	//find file2
	else if(file2==NULL){
		puts("File could not be opened.");
	}
	else{
		//get the content of file1 
		while((fgets(string,30,file1))!=NULL){
			//count the words in file1
			for(i=0;i<strlen(string);i++){
				if(string[i]==32||string[i]==0){ 
				number++; 
				}
			}
		printf("file1.txt has %d words\n",number);	
		}
		//get the content of file2
		while((fgets(string,30,file2))!=NULL){
			number=0; 
			//count the words in file2
			for(i=0;i<strlen(string);i++){
				if(string[i]==32||string[i]==0){ 
				number++; 
				}
			}
		printf("file2.txt has %d words\n",number);	
		}
	}
} 
