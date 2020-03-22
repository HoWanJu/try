#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"

int main (int argc,char *argv[]){
	int selection=0;
	
	printf("Please select a number\n");
	printf("1:+,2:-,3:*,4:/\n");
	scanf("%d",&selection);
	
		switch (selection){
			
			case 1:
				plus(argv[1],argv[2]);
				break;
			
			case 2:
				minus(argv[1],argv[2]);
				break;
				
			case 3:
				multiply(argv[1],argv[2]);
				break;
				
			case 4:
				divide(argv[1],argv[2]);
				break;
				
			default:
				printf("%d","Incorrect selection entered.\n");
				puts("Enter a new selection.\n");
				break;
		}
}