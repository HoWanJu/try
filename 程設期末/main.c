#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int welcome(void);
int printmap();
int find(void);
int number1(void);
int number2(void);
int up();
int down();
int right();
int left();

int x=0,y=0;

int map[10][10]={0};

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
		
int main(void)
{	
	int a,b;
	
	system("title main");
	
	memcpy(map, map1, sizeof(map1));
	
	welcome();
	
	getch();
	
	system("cls");
	
	a=number1();
	
	while(1)
	{
		system("cls");
		printmap();
		b = number2();
		find();
		
		switch(getch())
		{
			case 'w':
				up();
				break;
			case 's':
				down(); 
				break;
            case 'a':	
				left(); 
				break;
            case 'd':
				right(); 
				break;
            case 'r':
				memcpy(map, map1, sizeof(map1)); 
				break;
		}
		
		if(a==b)
		{
			system("cls");
			printf("You win!!");
			getch();
			return 0;	
		}
		
		
	}
	
 } 
int welcome(void){
	puts("*****************************************");
	puts("*   Welcome to the Blocking Monster!!   *");
	puts("*---------------------------------------*");
	puts("*    以w,a,s,d控制人物的上下左右移動    *");
	puts("*---------------------------------------*");
	puts("*  請將□推到⊙擋住洞穴讓怪獸無法出來   *");
	puts("*---------------------------------------*");
	puts("*           按任意鍵開始遊戲            *");
	puts("*---------------------------------------*");
	puts("*          按「r」重新開始遊戲          *");
	puts("*****************************************");
	
	return 0;
}

int up()
 {
     if(map[x][y] == 2) //找到自己的位置
     {
         if(map[x-1][y] == 0) //判斷下一格子是不是空
         {
             map[x-1][y] = 2;
             map[x][y] = 0;
         }
         if(map[x-1][y] == 3 && map[x-2][y] == 4) /*判斷下一格子是不是箱子,下下個格子是不是箱子要到的地方*/
         {
             map[x][y] = 0;
             map[x-1][y] = 2;
             map[x-2][y] = 5;
         }
         if(map[x-1][y] == 3 && map[x-2][y] == 0)
         {
         	map[x][y] = 0;
         	map[x-1][y] = 2;
            map[x-2][y] = 3;
		 }
     }
     return 0;
}

int right()
{
	if(map[x][y]==2){
		if(map[x][y+1]==0){
			map[x][y+1] = 2;
			map[x][y] = 0;
		}
		
		if(map[x][y+1]==3 && map[x][y+2]==4){
			map[x][y] = 0;
			map[x][y+1] = 2;
			map[x][y+2] = 5;
		}
		
		if(map[x][y+2]==0 && map[x][y+1]==3){
			map[x][y] = 0;
			map[x][y+1] = 2;
			map[x][y+2] = 3;
		}
	}
	return 0;
}

int printmap(){
	for(x = 0; x < 10; x++){
		for(y = 0; y < 10; y++){
			if(map[x][y] == 0){
				printf("  ");
			}
			if(map[x][y] == 1){
				printf("■");
			}
			if(map[x][y] == 2){
				printf("▼");
			}
			if(map[x][y] == 3){
				printf("□");
			}
			if(map[x][y] == 4){
				printf("⊙");
			}
			if(map[x][y] == 5){
				printf("★");
			}
		}
		printf("\n");
	}
	return 0;
}
//the number of blocked monsters
int number2(){
	int b=0;
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			if(map[x][y]==5){
				b++;
			}
		}
	}
	return b;
}
//number the monsters
int number1(){
	int a=0;
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			if(map[x][y]==4){
				a++;
			}
		}
	}
	return a;
}

int left()
{
	if(map[x][y]==2){
		if(map[x][y-1]==0){
			map[x][y-1] = 2;
			map[x][y] = 0;
		}
		
		if(map[x][y-1]==3 && map[x][y-2]==4){
			map[x][y] = 0;
			map[x][y-1] = 2;
			map[x][y-2] = 5;
		}
		
		if(map[x][y-2]==0 && map[x][y-1]==3){
			map[x][y] = 0;
			map[x][y-1] = 2;
			map[x][y-2] = 3;
		}
	}
	return 0;
}

//Find myself
int find(){
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			if(map[x][y]==2){
				return 0;
			}
		}
	}
} 

int down()
 {
     if(map[x][y] == 2)             //找到自己
     {
         if(map[x+1][y] == 0)       //判斷下個格子是否空格
         {
            map[x+1][y] = 2;
            map[x][y] = 0;
         }
         if(map[x+1][y] == 3 && map[x+2][y] == 4)  /*判斷下個格子是不是箱子且箱子後面的是不是星星*/
         {
             map[x][y] = 0;
             map[x+1][y] = 2;
             map[x+2][y] = 5;
         }
         if(map[x+1][y] == 3 && map[x+2][y] == 0)
         {
         	map[x][y] = 0;
         	map[x+1][y] = 2;
            map[x+2][y] = 3;
		 }
     }
     return 0;
 }
