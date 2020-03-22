#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

//定義一個struct型態的學生資料 
typedef struct student{
	char name[10];
	char phone[11];
	char grade;
}Student;

//分數轉換的function 
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

//print學生資料的function 
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
			
			//使用strtok分割
			//名字 
	    	tokenPtr=strtok(string,",");
	    	strcpy(information.name,tokenPtr);
	    	
	    	//手機號碼 
	    	tokenPtr=strtok(NULL,",");
	    	strcpy(information.phone,tokenPtr);
	    
	    	//成績 
	    	tokenPtr=strtok(NULL,",");
	    	information.grade=transform(atoi(tokenPtr));//將指標轉為整數型態傳入轉換分數的function 
	    
	    	printFunction(information);
	    	
	    	//寫入新的csv檔 
			fprintf(file3,"%s, %s ,%c\n",information.name,information.phone,information.grade);
		}
		

	

	}
	fclose(file1);
	fclose(file2);
	fclose(file3);
	
	return 0;
} 
