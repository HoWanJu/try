#include <stdio.h> 
#include <stdlib.h> 
// self-referential structure 
typedef struct list{
	char data; // each node contains a character 
    struct list *nextPtr; // pointer to next node 
	} List; //end structure "List" 
 
// Convert a string into a list, where each node contains a character in the string 
List *stringToList(char []);
// Print linked list. e.g. x --> y --> z --> NULL
void printList(List *); 
 
int main(void) {
	printList(stringToList("xyz")); 
}
	// Convert a string into a list, where each node contains a character in the string
List *stringToList(char s[]){ 
 
	// Create a node
	List *l = malloc(sizeof(List)); 
 
  	// Keep assigning 1st character to the node and linking to next nodes   
  	if(s[0] != '\0'){
		l->data = s[0];
		l->nextPtr = stringToList(++s);   
	}
	else{    
		// The last node, "nextPtr = NULL" 
		return(NULL);   
	}
	// Return the node we created.
	return(l); 
}
// Print linked list. e.g. x --> y --> z --> NULL 
void printList(List *lPtr){ 
	while(lPtr != NULL){
		printf("%c --> ", lPtr->data);
		lPtr = lPtr->nextPtr;   
	} 
	puts("NULL"); 
} 
