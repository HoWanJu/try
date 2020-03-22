#include<stdio.h>
int indexOf(char x[], char y[]);
int main(void){
	char string[100]={0};
	char find[100]={0};
	printf("Enter the string:");
	gets(string);
	printf("What do you want to find?");
	gets(find);
	printf("int indexOf(%s, %s)=%d",string,find, indexOf(string,find));
} 
int indexOf(char x[], char y[]){   // Iterators 
  int i = 0, j = 0; 
 
  while( x[i] != '\0'){  
    if(x[i] == y[j]){  
	    if(y[j + 1] == '\0'){  
		    return(i - j + 1); // Return the location index of the string y    
		}
		else{  
		++i; ++j;   
	   }
	}
	else{   
	  ++i; j = 0;   
	}  
  }   
  return(-1); // Return -1 if string y is not in string x 
} 

