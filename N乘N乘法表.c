 #include <stdio.h> 
int print_multiplication_table(int number); 

int main() 
{ 
  int n; 
  printf("ENTER A NUMBER:"); 
  scanf("%d",&n); 
  
  print_multiplication_table(n);
}

int print_multiplication_table(int number){
	int i=0,j=0;
	while(i<number) { 
	i=i+1; 
	j=0; //加上這一行，將變數 j 歸零 
	  while(j<number) { 
	    j=j+1;  
		printf("%d\t",i*j); 
		} 
		printf("\n");
   }
 } 
