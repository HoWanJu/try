int down()
 {
     if(map[x][y] == 3)             //找到自己
     {
         if(map[x+1][y] == 0)       //判斷下個格子是否空格
         {
            map[x+1][y] = 3;
            map[x][y] = 0;
         }
         if(map[x+1][y] == 2 && map[x+2][y] == 4)  /*判斷下個格子是不是箱子且箱子後面的是不是星星*/
         {
             map[x][y] = 0;
             map[x+1][y] = 3;
             map[x+2][y] = 5;
         }
     }
     return 0;
 }
