int down()
 {
     if(map[x][y] == 3)             //���ۤv
     {
         if(map[x+1][y] == 0)       //�P�_�U�Ӯ�l�O�_�Ů�
         {
            map[x+1][y] = 3;
            map[x][y] = 0;
         }
         if(map[x+1][y] == 2 && map[x+2][y] == 4)  /*�P�_�U�Ӯ�l�O���O�c�l�B�c�l�᭱���O���O�P�P*/
         {
             map[x][y] = 0;
             map[x+1][y] = 3;
             map[x+2][y] = 5;
         }
     }
     return 0;
 }
