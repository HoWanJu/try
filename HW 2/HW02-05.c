#include<stdio.h>

char printTextFile(const char *fileName);

int main(int agrc,char *agrv[]){
	printTextFile(agrv[1]);
	return 0;
}

char printTextFile(const char *fileName){
	
	FILE *fptr=fopen(fileName,"r");//ÅªÀÉ 
	
	if(fptr!=NULL){
		char str[30];
		char a;	
		rewind(fptr);
		while((a = fgetc(fptr))!=EOF){
			printf("%c",a);
		}
	}
	else{
		puts("File could not be opened");
	}
	fclose(fptr);
} 
