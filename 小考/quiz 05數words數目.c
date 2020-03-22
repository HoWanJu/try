#include <stdio.h>
#include <stdbool.h> 
 
int wordCount(char *); 
int isLetter(char); 
int isSpace(char); 
 
int main(void) {
	char str[500]={0};
    printf("Enter a string.");
    gets(str);
	printf("Total %d words.\n", wordCount(str) );
 } 
 
// WordCount function 
int wordCount(char *string){ 
    int wc = 0; // word count 
	char c; // character to check   
	int iter = 0; // string iterator  
	    
	// A flag to check if there's a space between letters.     
	// Here we consider consecutive characters as a "word".
	bool isWord = false;            
	
	while( (c = string[iter++]) != '\0'){
	    if(isLetter(c) &&  (! isWord)){       
		    isWord = true;         
		    ++wc;         
			}
		else{            // If there's a space between letters 
            if(isSpace(c))          
			    isWord = false;   
			}         
	}     
	return(wc); 
}
 // Function to check whether a char is an English letter
 int isLetter(char c){
    if( (c >= 65 && c <= 90) || (c >= 97 && c <= 122) ) return(1);    
	else return(0); 
}
 // Function to check whether a char is a SPACE 
 int isSpace(char c){
    if( c == 32 )return(1);  
	  else return(0); 
} 
