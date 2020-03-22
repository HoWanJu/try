#include<stdio.h>
int printmap(int MAP[10][10]);

int main(void){
	int map2[10][10] = {{1, 1, 1, 1, 0, 0, 1, 1, 1, 1},
					{1, 0, 0, 1, 0, 1, 1, 0, 0, 1},
					{1, 0, 0, 1, 1, 1, 0, 3, 0, 1},
					{1, 0, 3, 0, 0, 1, 0, 0, 4, 1},
					{1, 0, 0, 3, 0, 0, 1, 0, 4, 1},
					{1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
					{1, 2, 1, 1, 1, 0, 1, 0, 0, 1},
					{1, 0, 1, 0, 3, 0, 4, 0, 0, 1},
					{1, 0, 4, 0, 0, 0, 0, 0, 0, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					};
	printmap(map2);
}

int printmap(int MAP[10][10]){
	int i, k;
	for(i = 0; i < 10; i++){
		for(k = 0; k < 10; k++){
			if(MAP[i][k] == 0){
				printf("  ");
			}
			if(MAP[i][k] == 1){
				printf("¡½");
			}
			if(MAP[i][k] == 2){
				printf("¡¿");
			}
			if(MAP[i][k] == 3){
				printf("¡¼");
			}
			if(MAP[i][k] == 4){
				printf("¡ó");
			}
			if(MAP[i][k] == 5){
				printf("¡¹");
			}
		}
		printf("\n");
	}
	return 0;
}
