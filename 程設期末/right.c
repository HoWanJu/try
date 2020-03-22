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
