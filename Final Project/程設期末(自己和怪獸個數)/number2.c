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
