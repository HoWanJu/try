#include<stdio.h> 
#include<string.h>

typedef struct time {
	int hour;
	int minute;
	int second;
}Time;
 
int main(void){
	Time TIME_1={0,0,0};
	Time TIME_2={0,0,0};
	Time result={0,0,0};
	
	printf("Enter the time for the first time\n");
	printf("Enter hours, minutes and seconds respectively.\n");
	scanf("%d %d %d",&TIME_1.hour,&TIME_1.minute,&TIME_1.second);
	printf("Enter the time for the second time\n");
	printf("Enter hours, minutes and seconds respectively.\n");
	scanf("%d %d %d",&TIME_2.hour,&TIME_2.minute,&TIME_2.second);
	
	if(TIME_1.hour<TIME_2.hour){
		printf("The first time should be later than the second time.\n");
	}
	else {
		if(TIME_1.minute<TIME_2.minute){
			printf("The first time should be later than the second time.\n");
		}
		else{
			if(TIME_1.second<TIME_2.second){
				printf("The first time should be later than the second time.\n");
			}
		}
	}
	
	if(TIME_1.second<TIME_2.second){
		result.second=(60+TIME_1.second)-TIME_2.second;
		result.minute=TIME_1.minute-1;
		if(result.minute<TIME_2.minute){
			result.minute=(60+result.minute)-TIME_2.minute;
			result.hour=((TIME_1.hour-1)-TIME_2.hour);
		}
	}
	else{
		if(TIME_1.minute<TIME_2.minute){
			result.minute=(60+TIME_1.minute)-TIME_2.minute;
			result.hour=((TIME_1.hour-1)-TIME_2.hour);
			
		}
	}
	
	printf("Time Difference:%d :%d: %d-%d: %d: %d=%d :%d :%d",TIME_1.hour,TIME_1.minute,TIME_1.second,TIME_2.hour,TIME_2.minute,TIME_2.second,result.hour,result.minute,result.second);
	return 0;
} 
