#include<stdio.h>

typedef struct list{
	char data[20];
	struct list *nextPtr[3];
}Name; 

//���F�T�{���Ц��S���X���ӳ]�m�@��function���ը䤤�@�쪺������� 
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
	
	//�Ĥ@�]��Peter 
	Name *sPtr=&Peter;

	//�}�l����|���� 
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
	while(counter!=3){//�ѩ�nextPtr�}�C��counter�@�w�p��3 
		if(test.nextPtr[counter]!=NULL){
			printf("%s knows %s\n",test.data,test.nextPtr[counter]->data);
		}
		counter++;
	}
}


