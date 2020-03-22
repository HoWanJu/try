#include "find.h"
//Find myself
int find(){
	int x;
	int y;
	
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			if(map[x][y]==2){
				return 0;
			}
		}
		return 0;
	}
}
