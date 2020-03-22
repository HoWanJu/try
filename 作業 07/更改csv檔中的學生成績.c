#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

//�w�q�@��struct���A���ǥ͸�� 
typedef struct student{
	char name[10];
	char phone[11];
	char grade;
}Student;

//�����ഫ��function 
char transform(int score){
	if(score>=80&&score<=100){
		return'A';
	}
	else if(score>=70&&score<=79){
		return'B';
	}
	else if(score>=60&&score<=69){
		return'C';
	}
	else if(score>=50&&score<=59){
		return'D';
	}
	else{
		return'E';
	}
}

//print�ǥ͸�ƪ�function 
void printFunction(Student X){
	printf("%s, %s, %c\n",X.name ,X.phone ,X.grade);
}
 
int main(void){
	FILE *file1=fopen("students.csv","r");
	FILE *file2=fopen("students.csv","r");
	FILE *file3=fopen("students2.csv","w");
	char string[30];
	char *tokenPtr;
	Student information;
	
	rewind(file1);
	rewind(file2);
	
	if(file1==NULL){
		puts("File could not be opened");
	}
	else{
		while((fgets(string,30,file1))!=NULL){
			fgets(string,30,file2);
			
			//�ϥ�strtok����
			//�W�r 
	    	tokenPtr=strtok(string,",");
	    	strcpy(information.name,tokenPtr);
	    	
	    	//������X 
	    	tokenPtr=strtok(NULL,",");
	    	strcpy(information.phone,tokenPtr);
	    
	    	//���Z 
	    	tokenPtr=strtok(NULL,",");
	    	information.grade=transform(atoi(tokenPtr));//�N�����ର��ƫ��A�ǤJ�ഫ���ƪ�function 
	    
	    	printFunction(information);
	    	
	    	//�g�J�s��csv�� 
			fprintf(file3,"%s, %s ,%c\n",information.name,information.phone,information.grade);
		}
		

	

	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	
	return 0;
} 
