 int up()
 {
     if(map[x][y] == 3) //���ۤv����m
     {
         if(map[x-1][y] == 0) //�P�_�U�@��l�O���O��
         {
             map[x-1][y] = 3;
             map[x][y] = 0;
         }
         if(map[x-1][y] == 2 && map[x-2][y] == 4) /*�P�_�U�@��l�O���O�c�l,�U�U�Ӯ�l�O���O�c�l�n�쪺�a��*/
         {
             map[x][y] = 0;
             map[x-1][y] = 3;
             map[x-2][y] = 5;
         }
     }
     return 0;
 }

 
