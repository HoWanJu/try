#include <stdio.h>

void bubbleSort(int a[],int SIZE);
void swap(int *number1Ptr,int *number2Ptr);

int main (void){
	int size=0;
	int i;
	int array[100]={0};	
	
	//使用者輸入想要的陣列長度 
	printf("Enter the size of array:");
	scanf("%d",&size);

    //輸入陣列的值 
	for(i=0;i<size;i++){
		printf("array[%d]=",i);
		scanf("%d",&array[i]);
	}
	
	//original array 
	for(i=0;i<size;i++){
		printf("%d",array[i]);
	}
	
	printf("\n");
	 
	bubbleSort(array,size);
	
}

void bubbleSort(int a[],int SIZE){ 
	int j;
	int pass;
	
	for(pass=0;pass<SIZE-1;++pass){
		for(j=0;j<SIZE-1;++j){
				if(a[j]>a[j+1]){
					swap(&a[j],&a[j+1]);//呼叫swap function 
				}
		}
		
		//print the result
		for(j=0;j<SIZE;++j){
		printf("%d",a[j]);
		} 
		printf("\n");
	}
}

 void swap(int *number1Ptr,int *number2Ptr){
 	int hold;
 	hold= *number1Ptr;
 	*number1Ptr= *number2Ptr;
 	*number2Ptr= hold;
 }
