#include<stdio.h>

typedef struct list{
	char data[20];
	int pointed;
	struct list *nextPtr[5];
}Name; 

void OneWay( Name *a, Name *b );  
void TwoWay( Name *a, Name *b );  

int would_A_know_B(Name *a,Name *b); 
 
int main(void) {
	
	Name Peter={"Peter"};
	Name Tom={"Tom"};
	Name John={"John"};
	Name Jessica={"Jessica"};
	Name Jean={"Jean"};
	Name Mike={"Mike"};
	Name Mary={"Mary"};
	
	//The first structure is a
	Name *sPtr=&Peter;
	
	Peter.nextPtr[0]=&John;
	Peter.nextPtr[1]=&Tom;
	John.nextPtr[0]=&Peter;
	John.nextPtr[1]=&Tom;
	John.nextPtr[2]=&Jessica;
	Tom.nextPtr[0]=&Peter;
	Tom.nextPtr[1]=&John;
	Tom.nextPtr[2]=&Jessica;
	Jessica.nextPtr[0]=&Tom;
	Jessica.nextPtr[1]=&Jean;
	Jessica.nextPtr[2]=&Mike;
	Jean.nextPtr[0]=&Jessica;
	Mike.nextPtr[0]=&Mary;
	Mary.nextPtr[0]=&Mike;
	
	//雙向認識與單向認識的分別
	OneWay( &John, &Jessica );
	OneWay( &Jessica, &Mike );
	TwoWay( &Peter, &Tom );
	TwoWay( &Peter, &John );
	TwoWay( &Tom, &John );
	TwoWay( &Tom, &Jessica );	
	TwoWay( &Jean, &Jessica );	
	TwoWay( &Mike, &Mary );	 

	printf(" Weather Mary would know John?(1:yes/2:no)\n %d",would_A_know_B( &Mary, &John ));
}

// a與b單向認識 
void OneWay( Name *a, Name *b ){ 

	int i = 0;	
	while( a->nextPtr[i] != NULL ){
		i++;
	}
	a->nextPtr[i] = b; 
}

// a與b互相認識
void TwoWay( Name *a, Name *b ){ 
	OneWay( a, b );		
	OneWay( b, a );
}

int would_A_know_B(Name *a,Name *b){
	
 	//判斷是否互相認識 
 	int yes, no;
 	yes = 1;
 	no = 2;
 	
	if( a->data == b->data){
		return yes; 		
	}
	else{
		return no;
	}	
}


