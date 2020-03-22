#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int welcome(); //主選單 
int printmap(); //顯示地圖 
int gamechoice(); //遊戲時的選單 

int find(); //找到自己 
int monster(); //計算幾個怪獸 
int finished(); //計算幾個成功 

int up(); //移動(上) 
int down(); //移動(下)
int right(); //移動(右)
int left(); //移動(左)

int back(char step); //返回上一步 
int back_up(); //移動(上)的返回 
int back_down(); //移動(下)的返回
int back_right(); //移動(右)的返回
int back_left(); //移動(左)的返回

void billboard(); //排行榜 
void write_Billboard(); //把資料寫進排行榜 
void read_Billboard(); //顯示排行榜資料 
void search_Billboard(); //搜尋排行榜 

void OpenData(); //開啟儲存紀錄 
void SaveData(); //儲存遊戲紀錄 

int counter=0; //每關步數 
int total_step=0; //總步數 
int level = 1; //關卡
int boxmoved = 0; //箱子是否被移動 
 
int x = 0, y = 0; //地圖座標
 
int map[10][10] = {0}; //地圖初始化

int copyMap[10][10] = {0}; //儲存玩家目前遊戲進度地圖 
 
int nowmap[10][10] = {0}; //儲存現在關卡地圖 

//第一關地圖 
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
					
//第二關地圖		
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
					
//第三關地圖
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
					
//第四關地圖 
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
					
//第五關地圖 
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
 
//玩家資料
typedef struct player{
	char date[12];
	char name[16];
	int round;
	int total_step;
}Player;

int main(void){	

	int a, b; //計算箱子和怪獸數量 
	char choice; //玩家的選擇 
	
	system("title main");
	
	memcpy(map, map1, sizeof(map1)); //遊戲地圖為第一關
	memcpy(nowmap, map1, sizeof(nowmap)); //現在關卡地圖為第一關 
	
	welcome(); //主頁面
	
	//玩家選擇排行榜選單 
	while((choice = getch()) == 'b')
	{
		system("cls"); //清屏 
		billboard(); //排行榜選單 
		system("cls"); //清屏 
		fflush(stdin); //清空暫存 
		welcome(); //主選單 
	} 
	
	//玩家選擇開啟上次遊戲 
	if(choice == 'o')
	{
		OpenData();
	} 
	
	a = monster(); //計算怪獸數量 
	
	char prestep = 'r'; //上一步  
	char nowstep = '0'; //現在步  
	
	while(1){
		
		system("cls"); //清屏 
		
		printmap(); //顯示地圖 
		gamechoice(); //遊戲選單 
		
		b = finished(); //計算成功數量 
		find(); //找到自己的位置 
		
		//如果完成數量等於怪獸數量 
		if(a == b)
		{
			system("cls");
			printf("Good job!!!!\n");
			 
			total_step+=counter; //將步數加總 
			counter=0; //步數歸零 
			
			//如果是最後一關 
			if(level == 5)
			{
				puts("You win!!");
				printf("Do you want to save your infor on billboard?(y/n)\n");
				//玩家選擇存入排行榜 
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
			
			//如果不是最後一關 
			else
			{
				printf("Next level?(y/n)\n");
				//玩家選擇下一關 
				if(getch() == 'y')
				{
					level++;
					switch(level)
					{
						case 2:
							memcpy(map, map2, sizeof(map2)); //地圖變成第二關地圖 
							memcpy(nowmap, map2, sizeof(nowmap)); //現在地圖為第二關地圖 
							a = monster(); //計算本關怪獸數量 
							printf("按 g 開始新遊戲\n");
							break;
						case 3:
							memcpy(map, map3, sizeof(map3)); //地圖變成第三關地圖 
							memcpy(nowmap, map3, sizeof(nowmap)); //現在地圖為第三關地圖
							a = monster(); //計算本關怪獸數量 
							printf("按 g 開始新遊戲\n");
							break;
						case 4:
							memcpy(map, map4, sizeof(map4)); //地圖變成第四關地圖
							memcpy(nowmap, map4, sizeof(nowmap)); //現在地圖為第四關地圖
							a = monster(); //計算本關怪獸數量 
							printf("按 g 開始新遊戲\n");
							break;
						case 5:
							memcpy(map, map5, sizeof(map5)); //地圖變成第五關地圖
							memcpy(nowmap, map5, sizeof(nowmap)); //現在地圖為第五關地圖
							a = monster(); //計算本關怪獸數量 	
							printf("按 g 開始新遊戲\n");
							break;	
					}
				}
				
				//如果玩家不選擇下一關 
				else
				{
					printf("Do you want to save your infor on billboard?(y/n)\n");
					//假如玩家選擇存到排行榜 
					if(getch() == 'y')
					{
						write_Billboard(); //寫入排行榜 
						puts("End!!");
						return 0;
					}
					//假如玩家選擇不存到排行榜 
					else
					{
						system("cls"); //清屏 
						puts("End!!");
						return 0;
					}
				}
			}
		}
		//玩家移動 
		switch(nowstep = getch())
		{ 
		//如果這一步不是返回，箱子設為還沒移動過	
		if(nowstep != 'b')
		{
			boxmoved = 0;
		}
		//向上移動 
		case 'w':
			up();
			prestep = 'w'; //上一步為 w 
			break;
		//向下移動
		case 's':
			down();
			prestep = 's'; //上一步為 s 
			break;
		//向左移動		
        case 'a':	
			left(); 
			prestep = 'a'; //上一步為 a
			break;
		//向右移動
        case 'd':
			right(); 
			prestep = 'd'; //上一步為 d 
			break;
		//重新開始 
        case 'r':
        	memcpy(map, nowmap, sizeof(nowmap)); //將現在關卡完原本地圖放進地圖 
			prestep = 'r'; //上一步為 r 
			counter = 0; //步數歸零 
			break;
		//返回上一步 
		case 'b':
			back(prestep);
			prestep = 'b'; //上一步為 b 
			boxmoved = 0; //箱子的移動設為未移動 
			counter--; //步數減一步 
			break;
		//遊戲結束	
		case 'j':
			system("cls"); //清屏 
			puts("End!!");
			return 0;
		//儲存目前遊戲進度	
		case 'z':
			printf("儲存嗎:)(y/n)\n");
			
			//如果玩家選擇儲存 
			if(getch() == 'y')
			{
				SaveData(); //儲存遊戲進度 
				system("cls");
				puts("End!!");
				return 0;
			}
			
			//如果玩家不選擇儲存 
			else
			{
				return 0;
			} 
			break;
		}	
	}
}

//主選單 
int welcome(void)
{
	puts("*****************************************");
	puts("*   Welcome to the Blocking Monster!!   *");
	puts("*---------------------------------------*");
	puts("*  請將□推到⊙擋住洞穴讓怪獸無法出來   *");
	puts("*---------------------------------------*");
	puts("*           按 b 進入排行榜選單         *");
	puts("*---------------------------------------*");
	puts("*           按 o 打開上次遊戲進度       *");
	puts("*---------------------------------------*");
	puts("*           按任意建開始新遊戲          *");
	puts("*---------------------------------------*");
	
	return 0;
}

//將地圖顯示出來 
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
				printf("■");
			}
			if(map[x][y] == 2)
			{
				printf("▼");
			}
			if(map[x][y] == 3)
			{
				printf("□");
			}
			if(map[x][y] == 4)
			{
				printf("⊙");
			}
			if(map[x][y] == 5)
			{
				printf("★");
			}
		}
		printf("\n");
	}
	return 0;
}

//遊戲時的選單
int gamechoice()
{
	puts("");
	puts("-----------------------");
	puts("-------遊戲說明--------");
	puts("-按w,s,a,d操作上下左右-");
	puts("-----按 r 重新開始-----");
	puts("----按 b 返回上一步----");
	puts("-----按 z 儲存遊戲-----");
	puts("-----按 j 結束遊戲-----");
	puts("-----------------------");
}

//找到自己
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

//計算怪獸的個數
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

//計算成功阻擋怪獸數量 
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

//移動(上) 
int up()
{	
	//找到自己的位置
    if(map[x][y] == 2) 
    {
    	counter++; //步數增加 
    	
    	//判斷上面的格子是不是空的
        if(map[x - 1][y] == 0)  
        {
        	map[x - 1][y] = 2;
            map[x][y] = 0;
            boxmoved = 0; //箱子沒有移動 
        }
        
        //判斷上面的格子是不是箱子,上上面的格子是不是怪獸
        if(map[x - 1][y] == 3 && map[x - 2][y] == 4)  
        {
            map[x][y] = 0;
            map[x - 1][y] = 2;
            map[x - 2][y] = 5;
            boxmoved = 1; //箱子有移動 
        }
        
        //判斷上面的格子是不是箱子，上上面的格子是不是空白 
        if(map[x - 1][y] == 3 && map[x - 2][y] == 0) 
        {
        	map[x][y] = 0;
        	map[x - 1][y] = 2;
            map[x - 2][y] = 3;
            boxmoved = 1; //箱子有移動 
		}
    }
    return 0;
}

//移動(下)
int down()
 {
	//找到自己
    if(map[x][y] == 2) 
    {
    	counter++; //步數增加 
    	
    	//判斷下面的格子是否是空白 
         if(map[x + 1][y] == 0) 
         {
            map[x + 1][y] = 2;
            map[x][y] = 0;
            boxmoved = 0; //箱子沒有移動 
         }
         
         //判斷下面的格子是不是箱子且下下面的格子是不是怪獸 
         if(map[x + 1][y] == 3 && map[x + 2][y] == 4) 
         {
             map[x][y] = 0;
             map[x + 1][y] = 2;
             map[x + 2][y] = 5;
             boxmoved = 1; //箱子有移動 
         }
         
         //判斷下面的格子是不是箱子，下下面的格子是不是空白
         if(map[x + 1][y] == 3 && map[x + 2][y] == 0) 
         {
         	map[x][y] = 0;
         	map[x + 1][y] = 2;
            map[x + 2][y] = 3;
            boxmoved = 1; //箱子有移動
		 }
    }
    return 0;
}
 
//移動(右) 
int right()
{
	//找到自己
	if(map[x][y] == 2){
		
		counter++; //步數增加
		
		//判斷右邊的格子是否是空白 
		if(map[x][y + 1] == 0)
		{
			map[x][y + 1] = 2;
			map[x][y] = 0;
			boxmoved = 0; //箱子沒有移動 
		}
		//判斷右邊的格子是不是箱子且右右邊的格子是不是怪獸 
		if(map[x][y + 1] == 3 && map[x][y + 2] == 4)
		{
			map[x][y] = 0;
			map[x][y + 1] = 2;
			map[x][y + 2] = 5;
			boxmoved = 1; //箱子有移動 
		}
		
		//判斷右邊的格子是不是箱子，右右邊的格子是不是空白
		if(map[x][y + 2] == 0 && map[x][y + 1] == 3)
		{
			map[x][y] = 0;
			map[x][y + 1] = 2;
			map[x][y + 2] = 3;
			boxmoved = 1; //箱子有移動 
		}
	}
	return 0;
}

//移動(左)
int left()
{
	//找到自己
	if(map[x][y] == 2)
	{
		counter++; //步數增加	
		
		//判斷左邊的格子是否是空白 
		if(map[x][y - 1] == 0)
		{
			map[x][y - 1] = 2;
			map[x][y] = 0;
			boxmoved = 0; //箱子沒有移動 
		}
		
		//判斷左邊的格子是不是箱子且左左邊的格子是不是怪獸
		if(map[x][y - 1] == 3 && map[x][y - 2] == 4)
		{
			map[x][y] = 0;
			map[x][y - 1] = 2;
			map[x][y - 2] = 5;
			boxmoved = 1; //箱子有移動  
		}
		
		//判斷左邊的格子是不是箱子，左左邊的格子是不是空白
		if(map[x][y - 2] == 0 && map[x][y - 1] == 3)
		{
			map[x][y] = 0;
			map[x][y - 1] = 2;
			map[x][y - 2] = 3;
			boxmoved = 1; //箱子有移動  
		}
	}
	return 0;
}

//移動(上)的返回
int back_up()
{
	//找到自己的位置
    if(map[x][y] == 2) 
    {
    	//判斷下面的格子是不是空白
        if(map[x + 1][y] == 0)  
        {
            map[x + 1][y] = 2;
            map[x][y] = 0;
        }
        
        //判斷上面格子不是箱子及箱子是否被移動
        if(map[x - 1][y] == 3 && boxmoved == 1)  
        {
        	map[x][y] = 3;
            map[x - 1][y] = 0;
        }
        
        //判斷上面格是不是完成及箱子是否被移動 
        if(map[x - 1][y] == 5 && boxmoved == 1) 
        {
        	map[x][y] = 3;
        	map[x - 1][y] = 4;
		}	
    }
    return 0;
}

//移動(下)的返回
int back_down()
{
	//找到自己
    if(map[x][y] == 2)
    {
    	//判斷上面格子是否空格
        if(map[x - 1][y] == 0) 
        {
           map[x - 1][y] = 2;
           map[x][y] = 0;
        }
        
        //判斷下面格子是不是箱子及箱子是否被移動
        if(map[x + 1][y] == 3 && boxmoved == 1) 
        {
    		map[x][y] = 3;
        	map[x + 1][y] = 0;
        }
        
        //判斷下面格子是不是完成及箱子是否被移動
        if(map[x + 1][y] == 5 && boxmoved == 1)  
        {
        	map[x][y] = 3;
        	map[x + 1][y] = 4;
		}
    }
    return 0;
}

//移動(右)的返回
int back_right()
{
	//找到自己 
	if(map[x][y] == 2) 
	{ 
		//判斷左個格子是否空格
		if(map[x][y - 1] == 0)
		{
			map[x][y - 1] = 2;
			map[x][y] = 0;
		}
		
		//判斷右邊格子是不是箱子及箱子是否被移動
		if(map[x][y + 1] == 3 && boxmoved == 1)  
	    {
	    	map[x][y] = 3;
	        map[x][y + 1] = 0;
	    }
	    
	    //判斷右邊格子是不是完成及箱子是否被移動    
	    if(map[x][y + 1] == 5 && boxmoved == 1) 
	    {
	        map[x][y] = 3;
	        map[x][y + 1] = 4;
		}
	}
	return 0;
}

//移動(左)的返回
int back_left()
{
	//找到自己
	if(map[x][y] == 2)
	{
		//判斷右個格子是否空格
		if(map[x][y + 1] == 0)
		{
			map[x][y + 1] = 2;
			map[x][y] = 0;
		}
		
		//判斷左邊格子是不是箱子及箱子是否被移動 
		if(map[x][y - 1] == 3 && boxmoved == 1) 
	    {
	    	map[x][y] = 3;
	        map[x][y - 1] = 0;
	    }
	    
	    //判斷左邊格子是不是完成及箱子是否被移動
	    if(map[x][y - 1] == 5 && boxmoved == 1) 
	    {
	        map[x][y] = 3;
	        map[x][y - 1] = 4;
		}
	}
	return 0;
}

//返回上一步 
int back(char step)
{
	//移動(上)的返回
	if(step == 'w')
	{
		back_up();
		return 0;
	}
	//移動(下)的返回
	if(step == 's')
	{
		back_down();
		return 0;
	}
	//移動(左)的返回
	if(step == 'a')
	{
		back_left();
		return 0;
	}
	//移動(右)的返回
	if(step == 'd')
	{
		back_right();
		return 0;
	}
} 

//排行榜選單 
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
	
	//顯示排行榜
	if(choice == 'a')
	{	
		read_Billboard();
	}
	
	//搜尋排行榜 
	else if(choice == 'b')
	{
		search_Billboard(); 
	}
	
	//返回主選單 
	else if(choice == 'c')
	{
		system("cls"); //清屏 
		welcome(); // 返回主選單 
	}
	
	else
	{
		printf("Error! Please enter yor choice again.\n");
	}	
} 

//儲存排行榜資料 
void write_Billboard()
{
	FILE *fptr;
	fptr = fopen("Player_data.txt", "a+"); //玩家資料檔案 

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

//印出現有玩家資料 
void read_Billboard()
{
	FILE *fptr;
	fptr = fopen("Player_data.txt", "r");
	
	puts("");
	printf("%-10s%-12s%-16s%-9s%-10s\n", "Rank", "Date", "Name", "Round", "Total Step"); 
	
	fseek(fptr, 0, SEEK_END); //指標指到檔案最後 
	
	int i = 0;  
	int rank = 1; //排名 
	int datanum = 0; //檔案中有幾筆玩家資料 
	
	//檔案中有幾筆資料等於檔案總字元數除一個玩家資料儲存大小 
	datanum = (ftell(fptr)) / (sizeof(Player));
	
	//指標指回檔案開頭 
	rewind(fptr);
	
	Player p[datanum];
	
    //由file讀入資料 
	for(i = 0; i < datanum; i++)
	{
		fscanf(fptr, "%12s", p[i].date);
		fscanf(fptr, "%16s", p[i].name);
		fscanf(fptr, "%4d", &p[i].round);
		fscanf(fptr, "%4d", &p[i].total_step);	
	}

	int pass = 0;
	int j = 0;
	
	//比較回合。完成的回合多，排序越前面 
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
	
	//比較總步數。 如果完成回合數相同則比較步數。步數越少排序越前面 
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
	
	//印出玩家資料 
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
	printf("按任意鍵返回主選單\n");	
	getch();
}

//排行榜搜尋 
void search_Billboard()
{
	FILE *file = fopen("Player_data.txt", "r");
	
	char name[15] = {0};
	int z = 0;
	int Search_count = 0;
	
	printf("name=> ");
	scanf("%s", name);
	
	fseek(file, 0, SEEK_END); //指標指到檔案最後 
	
	int i = 0;
	int datanum = 0; //檔案中有幾筆玩家資料 
	
	//檔案中有幾筆資料等於檔案總字元數除一個玩家資料儲存大小 
	datanum = (ftell(file)) / (sizeof(Player));  
	
	rewind(file); //指標指回檔案開頭 
	
	Player p[datanum];
	
    //由file讀入資料 
	for(i = 0; i < datanum; i++)
	{
		fscanf(file, "%12s", p[i].date);
		fscanf(file, "%16s", p[i].name);
		fscanf(file, "%4d", &p[i].round);
		fscanf(file, "%4d", &p[i].total_step);	
	}

	int pass = 0;
	int j = 0;
	
	//比較回合。完成的回合多，排序越前面 
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
	
	//比較總步數。 如果完成回合數相同則比較步數。步數越少排序越前面 
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
	
	//比較每一筆資料的名字和要搜尋的名字是否相同 
	for(z = 0; z < datanum; z++)
	{	
		int h = 0;
		int j = 0;
		
		while(p[z].name[h] != '\0')
		{
			//比較struct中名字的字元是否與欲搜尋的名字字元相同，如果相同則會繼續進行下一個字元的比較 
			if(p[z].name[h] == name[j])
			{
				//如果比較到的字元皆相同且struct中的名字下一個字元及欲搜尋的名字下一個字元皆為'\0'，代表在旁行榜中搜尋到了，則print出搜尋到的資料 
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
				
				//如果struct中的名字下一個字元及欲搜尋的名字下一個字元不為'\0'，則將h及j ++，繼續比較兩名字是否相同 
				else
				{
					h++;
					j++;
				}
			}
			
			//如果struct中名字的字元與欲搜尋的名字字元不相同，則直接挑出 
			else
			{
				break;
			}
		}
	}
	
	//因為有搜尋到資料時Search_count會++，所以Search_count==0就代表沒有搜尋到資料 
	if(Search_count == 0)
	{
		printf("Not found!\n");
	}
	
	fclose(file);
	
	puts("");
	printf("按任意鍵返回主選單\n");	
	getch();
}

//開啟儲存紀錄
void  OpenData()  
{  
    int  i = 0;  
    FILE *fPtr = fopen("1.txt", "r");
    
    if (fPtr == NULL)  
    {  
        printf( "不能打開文件\n" );    
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

//儲存遊戲紀錄 
void  SaveData()  
{
	FILE *FPtr;
	FPtr = fopen("1.txt", "w+");
    
	if(FPtr == NULL)
	{  
        printf( "不能存入文件\n" );  
        return ;  
    }	  
    else
	{
    	fwrite(map, sizeof(copyMap), 1, FPtr);
	}
	 
    fclose(FPtr);   
}   
