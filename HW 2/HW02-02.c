#include<stdio.h>

typedef struct list{
	char data[20];
	struct list *nextPtr[3];
}Name; 

//為了確認指標有沒有出錯而設置一個function測試其中一位的社交網絡 
char printList(struct list test); 
 
int main(void) {
	
	//Add new structures
	Name Peter={"Peter"};
	Name Tom={"Tom"};
	Name John={"John"};
	Name Jessica={"Jessica"};
	Name Jean={"Jean"};
	Name Mike={"Mike"};
	Name Mary={"Mary"};
	
	//第一設為Peter 
	Name *sPtr=&Peter;

	//開始其社會網絡 
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
	
	printList(Peter);
}

char printList(struct list test){
	int counter=0;
	while(counter!=3){//由於nextPtr陣列的counter一定小於3 
		if(test.nextPtr[counter]!=NULL){
			printf("%s knows %s\n",test.data,test.nextPtr[counter]->data);
		}
		counter++;
	}
}


