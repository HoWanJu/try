#include<stdio.h>
#include<string.h>

typedef struct ClientData{
	char ID[20];
	char name[20];
	double balance;
}client; 

void display(client temp[]){//�i���U�ȸ�� 
	int i;
	for(i=0; i<100; i++){
		if(temp[i].balance == 0) break;
		printf("ID:%s     Name:%s     Balance:$%lf\n",temp[i].ID,temp[i].name,temp[i].balance);
	}
}

void init(client a[]){//�]�w�@�ӳ̪쪺structure������ϥΪ̿�J����ƥi�H�x�s�䤤 
	int i=0;
	for(i=0; i<100; i++){
		char nullch[20] = "";
		char *NULLch = &nullch[0];
		strcpy(a[i].ID, NULLch);
		strcpy(a[i].name, NULLch);
		a[i].balance = 0;
	} 
}

int main(void){
	struct ClientData CD[100];/*�ŧi�@���}�C�A�C�Ӹ�ƫ��A���OCilentData�A�@100��*/ 
	init(CD);
	int i;
	char ans;
	char tempString[100];
	int i_CD=0;
	
	printf("1:Enter a client.\n2:List all clients.\n3:End.\n");
	scanf("%c", &ans);
	while(ans!='3'){
		switch (ans){
			printf("%c", ans);
			case '1':
				printf("ID? Name? Balance?\n");
				scanf("%s %s %lf",CD[i_CD].ID,CD[i_CD].name,&CD[i_CD].balance);
				i_CD++;
				break;
			case '2':
				display(CD);
				break;
			case '3':
				break;
			default:
				printf("Please enter again. (y/n)\n");
				break;
		}
		printf("1:Enter a client?\n2:List all clients\n3:End.\n");
			fflush(stdin);//��stdin�����Ȧs���M��
			scanf("%c",&ans);
	}
}
