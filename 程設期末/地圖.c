#include<stdio.h>
int printmap(int MAP[10][10]);

int printmap(int MAP[10][10]){
	int i, k;
	for(i = 0; i < 10; i++){
		for(k = 0; k < 10; k++){
			if(MAP[i][k] == 0){
				printf("  ");
			}
			if(MAP[i][k] == 1){
				printf("��");
			}
			if(MAP[i][k] == 2){
				printf("��");
			}
			if(MAP[i][k] == 3){
				printf("��");
			}
			if(MAP[i][k] == 4){
				printf("��");
			}
			if(MAP[i][k] == 5){
				printf("��");
			}
		}
		printf("\n");
	}
	return 0;
}

int main(void){
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
	printmap(map1);
}
