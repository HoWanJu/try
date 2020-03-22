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


