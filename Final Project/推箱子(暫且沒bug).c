#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int welcome(); //�D��� 
int printmap(); //��ܦa�� 
int gamechoice(); //�C���ɪ���� 

int find(); //���ۤv 
int monster(); //�p��X�ө��~ 
int finished(); //�p��X�Ӧ��\ 

int up(); //����(�W) 
int down(); //����(�U)
int right(); //����(�k)
int left(); //����(��)

int back(char step); //��^�W�@�B 
int back_up(); //����(�W)����^ 
int back_down(); //����(�U)����^
int back_right(); //����(�k)����^
int back_left(); //����(��)����^

void billboard(); //�Ʀ�] 
void write_Billboard(); //���Ƽg�i�Ʀ�] 
void read_Billboard(); //��ܱƦ�]��� 
void search_Billboard(); //�j�M�Ʀ�] 

void OpenData(); //�}���x�s���� 
void SaveData(); //�x�s�C������ 

int counter=0; //�C���B�� 
int total_step=0; //�`�B�� 
int level = 1; //���d
int boxmoved = 0; //�c�l�O�_�Q���� 
 
int x = 0, y = 0; //�a�Ϯy��
 
int map[10][10] = {0}; //�a�Ϫ�l��

int copyMap[10][10] = {0}; //�x�s���a�ثe�C���i�צa�� 
 
int nowmap[10][10] = {0}; //�x�s�{�b���d�a�� 

//�Ĥ@���a�� 
int map1[10][10] = {{0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
					{1, 1, 1, 0, 0, 1, 1, 1, 1, 0},
					{1, 0, 0, 3, 0, 0, 0, 0, 1, 0},
					{1, 4, 0, 0, 0, 0, 4, 0, 1, 1},
					{1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 0, 0, 4, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 2, 0, 0, 3, 3, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					};
					
//�ĤG���a��		
int map2[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 2, 4, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 3, 0, 3, 0, 1},
					{1, 1, 0, 3, 0, 0, 1, 0, 0, 1},
					{0, 1, 0, 1, 1, 0, 1, 0, 0, 1},
					{1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
					{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 4, 1, 1, 0, 0, 1, 0, 1},
					{1, 0, 0, 0, 4, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					};
					
//�ĤT���a��
int map3[10][10] = {{1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
					{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
					{1, 0, 0, 1, 1, 1, 0, 3, 0, 1},
					{1, 0, 3, 0, 0, 1, 0, 0, 4, 1},
					{1, 0, 0, 3, 0, 0, 1, 0, 4, 1},
					{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
					{1, 2, 1, 1, 0, 0, 4, 0, 0, 1},
					{1, 0, 1, 0, 3, 0, 0, 0, 0, 1},
					{1, 0, 4, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					};
					
//�ĥ|���a�� 
int map4[10][10] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
					{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 1, 0, 3, 4, 4, 3, 0, 1, 0},
					{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 1, 2, 0, 0, 0, 0, 0, 1, 0},
					{0, 1, 0, 0, 3, 0, 3, 4, 1, 0},
					{0, 1, 0, 0, 4, 3, 4, 0, 1, 0},
					{0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
					{0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
					};
					
//�Ĥ����a�� 
int map5[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 0, 4, 2, 0, 1, 1, 0, 4, 1},
					{1, 4, 0, 0, 0, 1, 0, 0, 0, 1},
					{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 4, 1, 3, 1, 3, 1, 3, 1, 1},
					{1, 0, 3, 0, 0, 0, 0, 0, 0, 1},
					{1, 0, 0, 3, 0, 1, 0, 0, 0, 1},
					{1, 4, 0, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
					};	
 
//���a���
typedef struct player{
	char date[12];
	char name[16];
	int round;
	int total_step;
}Player;

int main(void){	

	int a, b; //�p��c�l�M���~�ƶq 
	char choice; //���a����� 
	
	system("title main");
	
	memcpy(map, map1, sizeof(map1)); //�C���a�Ϭ��Ĥ@��
	memcpy(nowmap, map1, sizeof(nowmap)); //�{�b���d�a�Ϭ��Ĥ@�� 
	
	welcome(); //�D����
	
	//���a��ܱƦ�]��� 
	while((choice = getch()) == 'b')
	{
		system("cls"); //�M�� 
		billboard(); //�Ʀ�]��� 
		system("cls"); //�M�� 
		fflush(stdin); //�M�żȦs 
		welcome(); //�D��� 
	} 
	
	//���a��ܶ}�ҤW���C�� 
	if(choice == 'o')
	{
		OpenData();
	} 
	
	a = monster(); //�p����~�ƶq 
	
	char prestep = 'r'; //�W�@�B  
	char nowstep = '0'; //�{�b�B  
	
	while(1){
		
		system("cls"); //�M�� 
		
		printmap(); //��ܦa�� 
		gamechoice(); //�C����� 
		
		b = finished(); //�p�⦨�\�ƶq 
		find(); //���ۤv����m 
		
		//�p�G�����ƶq������~�ƶq 
		if(a == b)
		{
			system("cls");
			printf("Good job!!!!\n");
			 
			total_step+=counter; //�N�B�ƥ[�` 
			counter=0; //�B���k�s 
			
			//�p�G�O�̫�@�� 
			if(level == 5)
			{
				puts("You win!!");
				printf("Do you want to save your infor on billboard?(y/n)\n");
				//���a��ܦs�J�Ʀ�] 
				if(getch() == 'y')
				{
					write_Billboard();
					puts("End!!");
					return 0;
				}
				
				else{
					system("cls");
					puts("End!!");
					return 0;
				}
			}
			
			//�p�G���O�̫�@�� 
			else
			{
				printf("Next level?(y/n)\n");
				//���a��ܤU�@�� 
				if(getch() == 'y')
				{
					level++;
					switch(level)
					{
						case 2:
							memcpy(map, map2, sizeof(map2)); //�a���ܦ��ĤG���a�� 
							memcpy(nowmap, map2, sizeof(nowmap)); //�{�b�a�Ϭ��ĤG���a�� 
							a = monster(); //�p�⥻�����~�ƶq 
							printf("�� g �}�l�s�C��\n");
							break;
						case 3:
							memcpy(map, map3, sizeof(map3)); //�a���ܦ��ĤT���a�� 
							memcpy(nowmap, map3, sizeof(nowmap)); //�{�b�a�Ϭ��ĤT���a��
							a = monster(); //�p�⥻�����~�ƶq 
							printf("�� g �}�l�s�C��\n");
							break;
						case 4:
							memcpy(map, map4, sizeof(map4)); //�a���ܦ��ĥ|���a��
							memcpy(nowmap, map4, sizeof(nowmap)); //�{�b�a�Ϭ��ĥ|���a��
							a = monster(); //�p�⥻�����~�ƶq 
							printf("�� g �}�l�s�C��\n");
							break;
						case 5:
							memcpy(map, map5, sizeof(map5)); //�a���ܦ��Ĥ����a��
							memcpy(nowmap, map5, sizeof(nowmap)); //�{�b�a�Ϭ��Ĥ����a��
							a = monster(); //�p�⥻�����~�ƶq 	
							printf("�� g �}�l�s�C��\n");
							break;	
					}
				}
				
				//�p�G���a����ܤU�@�� 
				else
				{
					printf("Do you want to save your infor on billboard?(y/n)\n");
					//���p���a��ܦs��Ʀ�] 
					if(getch() == 'y')
					{
						write_Billboard(); //�g�J�Ʀ�] 
						puts("End!!");
						return 0;
					}
					//���p���a��ܤ��s��Ʀ�] 
					else
					{
						system("cls"); //�M�� 
						puts("End!!");
						return 0;
					}
				}
			}
		}
		//���a���� 
		switch(nowstep = getch())
		{ 
		//�p�G�o�@�B���O��^�A�c�l�]���٨S���ʹL	
		if(nowstep != 'b')
		{
			boxmoved = 0;
		}
		//�V�W���� 
		case 'w':
			up();
			prestep = 'w'; //�W�@�B�� w 
			break;
		//�V�U����
		case 's':
			down();
			prestep = 's'; //�W�@�B�� s 
			break;
		//�V������		
        case 'a':	
			left(); 
			prestep = 'a'; //�W�@�B�� a
			break;
		//�V�k����
        case 'd':
			right(); 
			prestep = 'd'; //�W�@�B�� d 
			break;
		//���s�}�l 
        case 'r':
        	memcpy(map, nowmap, sizeof(nowmap)); //�N�{�b���d���쥻�a�ϩ�i�a�� 
			prestep = 'r'; //�W�@�B�� r 
			counter = 0; //�B���k�s 
			break;
		//��^�W�@�B 
		case 'b':
			back(prestep);
			prestep = 'b'; //�W�@�B�� b 
			boxmoved = 0; //�c�l�����ʳ]�������� 
			counter--; //�B�ƴ�@�B 
			break;
		//�C������	
		case 'j':
			system("cls"); //�M�� 
			puts("End!!");
			return 0;
		//�x�s�ثe�C���i��	
		case 'z':
			printf("�x�s��:)(y/n)\n");
			
			//�p�G���a����x�s 
			if(getch() == 'y')
			{
				SaveData(); //�x�s�C���i�� 
				system("cls");
				puts("End!!");
				return 0;
			}
			
			//�p�G���a������x�s 
			else
			{
				return 0;
			} 
			break;
		}	
	}
}

//�D��� 
int welcome(void)
{
	puts("*****************************************");
	puts("*   Welcome to the Blocking Monster!!   *");
	puts("*---------------------------------------*");
	puts("*  �бN�������צ�}�������~�L�k�X��   *");
	puts("*---------------------------------------*");
	puts("*           �� b �i�J�Ʀ�]���         *");
	puts("*---------------------------------------*");
	puts("*           �� o ���}�W���C���i��       *");
	puts("*---------------------------------------*");
	puts("*           �����N�ض}�l�s�C��          *");
	puts("*---------------------------------------*");
	
	return 0;
}

//�N�a����ܥX�� 
int printmap()
{
	for(x = 0; x < 10; x++)
	{
		for(y = 0; y < 10; y++)
		{
			if(map[x][y] == 0)
			{
				printf("  ");
			}
			if(map[x][y] == 1)
			{
				printf("��");
			}
			if(map[x][y] == 2)
			{
				printf("��");
			}
			if(map[x][y] == 3)
			{
				printf("��");
			}
			if(map[x][y] == 4)
			{
				printf("��");
			}
			if(map[x][y] == 5)
			{
				printf("��");
			}
		}
		printf("\n");
	}
	return 0;
}

//�C���ɪ����
int gamechoice()
{
	puts("");
	puts("-----------------------");
	puts("-------�C������--------");
	puts("-��w,s,a,d�ާ@�W�U���k-");
	puts("-----�� r ���s�}�l-----");
	puts("----�� b ��^�W�@�B----");
	puts("-----�� z �x�s�C��-----");
	puts("-----�� j �����C��-----");
	puts("-----------------------");
}

//���ۤv
int find()
{
	for(x = 0; x < 10; x++)
	{
		for(y = 0; y < 10; y++)
		{
			if(map[x][y] == 2)
			{
				return 0;
			}
		}
	}
} 

//�p����~���Ӽ�
int monster()
{
	int a = 0;
	for(x = 0; x < 10; x++)
	{
		for(y = 0; y < 10; y++)
		{
			if(nowmap[x][y] == 4)
			{
				a++;
			}
		}
	}
	return a;
}

//�p�⦨�\���ש��~�ƶq 
int finished()
{
	int b = 0;
	for(x = 0; x < 10; x++){
		
		for(y = 0; y < 10; y++)
		{
			if(map[x][y] == 5)
			{
				b++;
			}
		}
	}
	return b;
}

//����(�W) 
int up()
{	
	//���ۤv����m
    if(map[x][y] == 2) 
    {
    	counter++; //�B�ƼW�[ 
    	
    	//�P�_�W������l�O���O�Ū�
        if(map[x - 1][y] == 0)  
        {
        	map[x - 1][y] = 2;
            map[x][y] = 0;
            boxmoved = 0; //�c�l�S������ 
        }
        
        //�P�_�W������l�O���O�c�l,�W�W������l�O���O���~
        if(map[x - 1][y] == 3 && map[x - 2][y] == 4)  
        {
            map[x][y] = 0;
            map[x - 1][y] = 2;
            map[x - 2][y] = 5;
            boxmoved = 1; //�c�l������ 
        }
        
        //�P�_�W������l�O���O�c�l�A�W�W������l�O���O�ť� 
        if(map[x - 1][y] == 3 && map[x - 2][y] == 0) 
        {
        	map[x][y] = 0;
        	map[x - 1][y] = 2;
            map[x - 2][y] = 3;
            boxmoved = 1; //�c�l������ 
		}
    }
    return 0;
}

//����(�U)
int down()
 {
	//���ۤv
    if(map[x][y] == 2) 
    {
    	counter++; //�B�ƼW�[ 
    	
    	//�P�_�U������l�O�_�O�ť� 
         if(map[x + 1][y] == 0) 
         {
            map[x + 1][y] = 2;
            map[x][y] = 0;
            boxmoved = 0; //�c�l�S������ 
         }
         
         //�P�_�U������l�O���O�c�l�B�U�U������l�O���O���~ 
         if(map[x + 1][y] == 3 && map[x + 2][y] == 4) 
         {
             map[x][y] = 0;
             map[x + 1][y] = 2;
             map[x + 2][y] = 5;
             boxmoved = 1; //�c�l������ 
         }
         
         //�P�_�U������l�O���O�c�l�A�U�U������l�O���O�ť�
         if(map[x + 1][y] == 3 && map[x + 2][y] == 0) 
         {
         	map[x][y] = 0;
         	map[x + 1][y] = 2;
            map[x + 2][y] = 3;
            boxmoved = 1; //�c�l������
		 }
    }
    return 0;
}
 
//����(�k) 
int right()
{
	//���ۤv
	if(map[x][y] == 2){
		
		counter++; //�B�ƼW�[
		
		//�P�_�k�䪺��l�O�_�O�ť� 
		if(map[x][y + 1] == 0)
		{
			map[x][y + 1] = 2;
			map[x][y] = 0;
			boxmoved = 0; //�c�l�S������ 
		}
		//�P�_�k�䪺��l�O���O�c�l�B�k�k�䪺��l�O���O���~ 
		if(map[x][y + 1] == 3 && map[x][y + 2] == 4)
		{
			map[x][y] = 0;
			map[x][y + 1] = 2;
			map[x][y + 2] = 5;
			boxmoved = 1; //�c�l������ 
		}
		
		//�P�_�k�䪺��l�O���O�c�l�A�k�k�䪺��l�O���O�ť�
		if(map[x][y + 2] == 0 && map[x][y + 1] == 3)
		{
			map[x][y] = 0;
			map[x][y + 1] = 2;
			map[x][y + 2] = 3;
			boxmoved = 1; //�c�l������ 
		}
	}
	return 0;
}

//����(��)
int left()
{
	//���ۤv
	if(map[x][y] == 2)
	{
		counter++; //�B�ƼW�[	
		
		//�P�_���䪺��l�O�_�O�ť� 
		if(map[x][y - 1] == 0)
		{
			map[x][y - 1] = 2;
			map[x][y] = 0;
			boxmoved = 0; //�c�l�S������ 
		}
		
		//�P�_���䪺��l�O���O�c�l�B�����䪺��l�O���O���~
		if(map[x][y - 1] == 3 && map[x][y - 2] == 4)
		{
			map[x][y] = 0;
			map[x][y - 1] = 2;
			map[x][y - 2] = 5;
			boxmoved = 1; //�c�l������  
		}
		
		//�P�_���䪺��l�O���O�c�l�A�����䪺��l�O���O�ť�
		if(map[x][y - 2] == 0 && map[x][y - 1] == 3)
		{
			map[x][y] = 0;
			map[x][y - 1] = 2;
			map[x][y - 2] = 3;
			boxmoved = 1; //�c�l������  
		}
	}
	return 0;
}

//����(�W)����^
int back_up()
{
	//���ۤv����m
    if(map[x][y] == 2) 
    {
    	//�P�_�U������l�O���O�ť�
        if(map[x + 1][y] == 0)  
        {
            map[x + 1][y] = 2;
            map[x][y] = 0;
        }
        
        //�P�_�W����l���O�c�l�νc�l�O�_�Q����
        if(map[x - 1][y] == 3 && boxmoved == 1)  
        {
        	map[x][y] = 3;
            map[x - 1][y] = 0;
        }
        
        //�P�_�W����O���O�����νc�l�O�_�Q���� 
        if(map[x - 1][y] == 5 && boxmoved == 1) 
        {
        	map[x][y] = 3;
        	map[x - 1][y] = 4;
		}	
    }
    return 0;
}

//����(�U)����^
int back_down()
{
	//���ۤv
    if(map[x][y] == 2)
    {
    	//�P�_�W����l�O�_�Ů�
        if(map[x - 1][y] == 0) 
        {
           map[x - 1][y] = 2;
           map[x][y] = 0;
        }
        
        //�P�_�U����l�O���O�c�l�νc�l�O�_�Q����
        if(map[x + 1][y] == 3 && boxmoved == 1) 
        {
    		map[x][y] = 3;
        	map[x + 1][y] = 0;
        }
        
        //�P�_�U����l�O���O�����νc�l�O�_�Q����
        if(map[x + 1][y] == 5 && boxmoved == 1)  
        {
        	map[x][y] = 3;
        	map[x + 1][y] = 4;
		}
    }
    return 0;
}

//����(�k)����^
int back_right()
{
	//���ۤv 
	if(map[x][y] == 2) 
	{ 
		//�P�_���Ӯ�l�O�_�Ů�
		if(map[x][y - 1] == 0)
		{
			map[x][y - 1] = 2;
			map[x][y] = 0;
		}
		
		//�P�_�k���l�O���O�c�l�νc�l�O�_�Q����
		if(map[x][y + 1] == 3 && boxmoved == 1)  
	    {
	    	map[x][y] = 3;
	        map[x][y + 1] = 0;
	    }
	    
	    //�P�_�k���l�O���O�����νc�l�O�_�Q����    
	    if(map[x][y + 1] == 5 && boxmoved == 1) 
	    {
	        map[x][y] = 3;
	        map[x][y + 1] = 4;
		}
	}
	return 0;
}

//����(��)����^
int back_left()
{
	//���ۤv
	if(map[x][y] == 2)
	{
		//�P�_�k�Ӯ�l�O�_�Ů�
		if(map[x][y + 1] == 0)
		{
			map[x][y + 1] = 2;
			map[x][y] = 0;
		}
		
		//�P�_�����l�O���O�c�l�νc�l�O�_�Q���� 
		if(map[x][y - 1] == 3 && boxmoved == 1) 
	    {
	    	map[x][y] = 3;
	        map[x][y - 1] = 0;
	    }
	    
	    //�P�_�����l�O���O�����νc�l�O�_�Q����
	    if(map[x][y - 1] == 5 && boxmoved == 1) 
	    {
	        map[x][y] = 3;
	        map[x][y - 1] = 4;
		}
	}
	return 0;
}

//��^�W�@�B 
int back(char step)
{
	//����(�W)����^
	if(step == 'w')
	{
		back_up();
		return 0;
	}
	//����(�U)����^
	if(step == 's')
	{
		back_down();
		return 0;
	}
	//����(��)����^
	if(step == 'a')
	{
		back_left();
		return 0;
	}
	//����(�k)����^
	if(step == 'd')
	{
		back_right();
		return 0;
	}
} 

//�Ʀ�]��� 
void billboard(void)
{
	char choice;
	
	printf("****************************\n"); 
	printf("          Billboard          \n");
	printf("****************************\n");
	
	printf("Please choose one option:\n");
	printf("a.Show Billboard\n");
	printf("b.Search Billboard\n");
	printf("c.Back To Main Menu\n\n");
	
	printf("Yor choice:");
	scanf("%c", &choice);
	
	//��ܱƦ�]
	if(choice == 'a')
	{	
		read_Billboard();
	}
	
	//�j�M�Ʀ�] 
	else if(choice == 'b')
	{
		search_Billboard(); 
	}
	
	//��^�D��� 
	else if(choice == 'c')
	{
		system("cls"); //�M�� 
		welcome(); // ��^�D��� 
	}
	
	else
	{
		printf("Error! Please enter yor choice again.\n");
	}	
} 

//�x�s�Ʀ�]��� 
void write_Billboard()
{
	FILE *fptr;
	fptr = fopen("Player_data.txt", "a+"); //���a����ɮ� 

	Player New;
	printf("Please enter date:\n");
	scanf("%11s", New.date);
	
	printf("Please enter name:\n");
	scanf("%15s", New.name);
	
	printf("Your level: %d:\n", level);
	New.round = level;
	
	printf("Your total steps: %d\n", total_step);
	New.total_step = total_step;

	fprintf(fptr, "%-12s", New.date);
	fprintf(fptr, "%-16s", New.name);
	fprintf(fptr, "%-4d", New.round);
	fprintf(fptr, "%-4d\n", New.total_step);
	
	fclose(fptr);		
}

//�L�X�{�����a��� 
void read_Billboard()
{
	FILE *fptr;
	fptr = fopen("Player_data.txt", "r");
	
	puts("");
	printf("%-10s%-12s%-16s%-9s%-10s\n", "Rank", "Date", "Name", "Round", "Total Step"); 
	
	fseek(fptr, 0, SEEK_END); //���Ы����ɮ׳̫� 
	
	int i = 0;  
	int rank = 1; //�ƦW 
	int datanum = 0; //�ɮפ����X�����a��� 
	
	//�ɮפ����X����Ƶ����ɮ��`�r���ư��@�Ӫ��a����x�s�j�p 
	datanum = (ftell(fptr)) / (sizeof(Player));
	
	//���Ы��^�ɮ׶}�Y 
	rewind(fptr);
	
	Player p[datanum];
	
    //��fileŪ�J��� 
	for(i = 0; i < datanum; i++)
	{
		fscanf(fptr, "%12s", p[i].date);
		fscanf(fptr, "%16s", p[i].name);
		fscanf(fptr, "%4d", &p[i].round);
		fscanf(fptr, "%4d", &p[i].total_step);	
	}

	int pass = 0;
	int j = 0;
	
	//����^�X�C�������^�X�h�A�ƧǶV�e�� 
	for(pass = 1; pass <= datanum; pass++)
	{
		for(j = 0; j < datanum - pass; j++)
		{
			if(p[j + 1].round > p[j].round)
			{
				Player hold;
				hold = p[j];
				p[j] = p[j + 1];
				p[j + 1] = hold;
			}
		}
	}
	
	//����`�B�ơC �p�G�����^�X�ƬۦP�h����B�ơC�B�ƶV�ֱƧǶV�e�� 
	for(pass = 1; pass <= datanum; pass++)
	{
		for(j = 0; j < datanum - pass; j++)
		{
			if(p[j].round == p[j + 1].round)
			{
				if(p[j].total_step > p[j + 1].total_step)
				{
					Player hold;
					hold = p[j + 1];
					p[j + 1] = p[j];
					p[j] = hold;
				}
			}
		}
	}
	
	//�L�X���a��� 
	for(i = 0; i < datanum; i++)
	{
		printf("  %-8d", rank);
		printf("%-12s", p[i].date);
		printf("%-16s", p[i].name);
		printf("%3d", p[i].round);
		printf("%12d\n", p[i].total_step);
		rank++;
	}	

	fclose(fptr);
	
	puts("");
	printf("�����N���^�D���\n");	
	getch();
}

//�Ʀ�]�j�M 
void search_Billboard()
{
	FILE *file = fopen("Player_data.txt", "r");
	
	char name[15] = {0};
	int z = 0;
	int Search_count = 0;
	
	printf("name=> ");
	scanf("%s", name);
	
	fseek(file, 0, SEEK_END); //���Ы����ɮ׳̫� 
	
	int i = 0;
	int datanum = 0; //�ɮפ����X�����a��� 
	
	//�ɮפ����X����Ƶ����ɮ��`�r���ư��@�Ӫ��a����x�s�j�p 
	datanum = (ftell(file)) / (sizeof(Player));  
	
	rewind(file); //���Ы��^�ɮ׶}�Y 
	
	Player p[datanum];
	
    //��fileŪ�J��� 
	for(i = 0; i < datanum; i++)
	{
		fscanf(file, "%12s", p[i].date);
		fscanf(file, "%16s", p[i].name);
		fscanf(file, "%4d", &p[i].round);
		fscanf(file, "%4d", &p[i].total_step);	
	}

	int pass = 0;
	int j = 0;
	
	//����^�X�C�������^�X�h�A�ƧǶV�e�� 
	for(pass = 1; pass < datanum; pass++)
	{
		for(j = 0; j < datanum - pass; j++)
		{
			if(p[j + 1].round > p[j].round)
			{
				Player hold = {0};
				hold = p[j];
				p[j] = p[j + 1];
				p[j + 1] = hold;
			}
		}
	}
	
	//����`�B�ơC �p�G�����^�X�ƬۦP�h����B�ơC�B�ƶV�ֱƧǶV�e�� 
	for(pass = 1; pass <= datanum; pass++)
	{
		for(j = 0; j < datanum - pass; j++)
		{
			if(p[j].round == p[j + 1].round)
			{
				if(p[j].total_step > p[j + 1].total_step)
				{
					Player hold = {0};
					hold = p[j + 1];
					p[j + 1] = p[j];
					p[j] = hold;
				}
			}
		}
	}
	
	//����C�@����ƪ��W�r�M�n�j�M���W�r�O�_�ۦP 
	for(z = 0; z < datanum; z++)
	{	
		int h = 0;
		int j = 0;
		
		while(p[z].name[h] != '\0')
		{
			//���struct���W�r���r���O�_�P���j�M���W�r�r���ۦP�A�p�G�ۦP�h�|�~��i��U�@�Ӧr������� 
			if(p[z].name[h] == name[j])
			{
				//�p�G����쪺�r���ҬۦP�Bstruct�����W�r�U�@�Ӧr���α��j�M���W�r�U�@�Ӧr���Ҭ�'\0'�A�N��b�Ǧ�]���j�M��F�A�hprint�X�j�M�쪺��� 
				if(name[j + 1] == '\0' && p[z].name[h+1]=='\0')
				{
					Search_count++;
					
					if(Search_count==1)
					{
						puts("");
						printf("%-10s%-12s%-16s%-9s%-10s\n", "Rank", "Date", "Name", "Round", "Total Step"); 
						printf("  %-8d%-12s%-16s%3d%12d\n", z+1, p[z].date, p[z].name, p[z].round, p[z].total_step);
					}
					
					if(Search_count>1)
					{
						printf("  %-8d%-12s%-16s%3d%12d\n", z+1, p[z].date, p[z].name, p[z].round, p[z].total_step);
					}
					
					break;
				}
				
				//�p�Gstruct�����W�r�U�@�Ӧr���α��j�M���W�r�U�@�Ӧr������'\0'�A�h�Nh��j ++�A�~������W�r�O�_�ۦP 
				else
				{
					h++;
					j++;
				}
			}
			
			//�p�Gstruct���W�r���r���P���j�M���W�r�r�����ۦP�A�h�����D�X 
			else
			{
				break;
			}
		}
	}
	
	//�]�����j�M���Ʈ�Search_count�|++�A�ҥHSearch_count==0�N�N��S���j�M���� 
	if(Search_count == 0)
	{
		printf("Not found!\n");
	}
	
	fclose(file);
	
	puts("");
	printf("�����N���^�D���\n");	
	getch();
}

//�}���x�s����
void  OpenData()  
{  
    int  i = 0;  
    FILE *fPtr = fopen("1.txt", "r");
    
    if (fPtr == NULL)  
    {  
        printf( "���ॴ�}���\n" );    
    }    
    else
	{
    	int result = 0;
    	result = fread(copyMap, sizeof(copyMap), 1, fPtr);
    	 
		if(result != 0)
		{
    		memcpy(map, copyMap, sizeof(copyMap));
		}
	}
    fclose(fPtr); 
}  

//�x�s�C������ 
void  SaveData()  
{
	FILE *FPtr;
	FPtr = fopen("1.txt", "w+");
    
	if(FPtr == NULL)
	{  
        printf( "����s�J���\n" );  
        return ;  
    }	  
    else
	{
    	fwrite(map, sizeof(copyMap), 1, FPtr);
	}
	 
    fclose(FPtr);   
}   
