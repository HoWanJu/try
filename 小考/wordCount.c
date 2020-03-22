#include <stdio.h> 
#include <ctype.h> 
 
int main(int argc , char *argv[]) { 
	FILE *fptr[argc-1];
	char tempStr[1000];  
	int wc = 0,i; 
 
	for(i = 1; i < argc;i++)  
	{
		if( (fptr[i] = fopen(argv[i],"r")) == NULL) 
			printf("Error, the file %s is not opened!\n", argv[i]);   
		else   
		{ 
			wc = 0;    
			while(fgets(tempStr, 1000,fptr[i]))    
			{
				wc = wc+ wordCount(tempStr);    
			}
			printf("File %s has %d words.\n", argv[i],wc);    
			fclose(fptr[i]);   
		} 
 	} 
} 
 
int wordCount(char str[]) 
{  
	int wc = 0,i; 
	int isWord = 0;
	while( str[i] != '\0')  
	{   
		if (isalpha(str[i]) && isWord == 0)   
		{
			isWord = 1;
			wc ++;   
		} 
		else   
		{   
			if(isspace(str[i]))    
			{ 
			    isWord = 0;    
			}   
		} 
		i++;  
	}  
	return(wc); 
} 
