#include <stdio.h> 
#include <stdlib.h> 
// self-referential structure 
typedef struct list{
	char data; // each node contains a character 
    struct list *nextPtr; // pointer to next node 
	} List; //end structure "List" 
 
// Print linked list. 
void printReList(List *ptr); 
 
int main(void) {
	
	//Add new structures
	List a={'a'};
	List b={'b'};
	List c={'c'};
	
	//The first structure is a
	List *sPtr=&a;
	
	a.nextPtr=&b;
	b.nextPtr=&c;
	c.nextPtr=NULL;
	
	printReList(sPtr); 
}

void printReList(List *start){ 
	List *previous = NULL;
	List *current = start;
	List *next = start->nextPtr;
	
	while(next != NULL){
		current->nextPtr=previous;//reverse the pointer(�쥻���Vnext)
		previous=current;//�Ҧ����Ьҩ��Ჾ�@�� 
		current=next;
		next=next->nextPtr;  
	} 
	
	current->nextPtr=previous;
	start=current;//pointer start from curent
	
	printf("NULL"); 
	
	while(current!=NULL){
		printf("<--%c",current->data);
		current=current->nextPtr;
	}
} 
