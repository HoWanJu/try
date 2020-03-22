#include<stdio.h>
#include<string.h>

typedef struct passenger{
	char passenger_name[20];
	char passenger_phone_number[10];
	int passenger_age;
	float passenger_balance;
	char seat[5];
} Passenger;

typedef struct car{
	int car_number;
	struct passenger * p[7];
	struct car *next_car;
}Car;

Passenger Albee={
	"Albee",
	"0900000000",
	18,
	10.1,
	"1A",
};

Passenger Bob={
	"Bob",
	"0911111111",
	19,
	10.2,
	"1B",
};

Passenger Cathy={
	"Cathy",
	"0911111111",
	20,
	10.3,
	"2C",
};

Passenger David={
	"David",
	"0922222222",
	21,
	10.4,
	"3C",
};

Passenger Emma={
	"Emma",
	"0933333333",
	22,
	10.5,
	"4F",
};

Passenger Frank={
	"Frank",
	"0944444444",
	23,
	10.6,
	"5A",
};

Passenger Gigi={
	"Gigi",
	"0955555555",
	24,
	10.7,
	"5B",
};


Car car1={
	1,
	{&Albee,&Bob},
};

Car car2={
	2,
	{&Cathy},
};

Car car3={
	3,
	{&David},
};

Car car4={
	4,
	{&Emma},
};

Car car5={
	5,
	{&Frank,&Gigi},
};


int list(struct car CarNumber){
	printf("Car %d\n",CarNumber.car_number);
	int counter=0;
	//檢查counter是否小於7因為乘客只有六人 
	while(counter!=7){
		if(CarNumber.p[counter]!=NULL){
			printf("%s : %s  %10s   %2dyo  $%.2f\n",CarNumber.p[counter]->seat,CarNumber.p[counter]->passenger_name,CarNumber.p[counter]->passenger_phone_number,CarNumber.p[counter]->passenger_age,CarNumber.p[counter]->passenger_balance);	
		}
	counter++;
	}
	
	printf("\n");
	
	//如果next_car不是NULL就呼叫list function 
	if(CarNumber.next_car!=NULL){
		list(*CarNumber.next_car);
	}
}



int main(void){
	
	car1.next_car=&car2;
	car2.next_car=&car3;
	car3.next_car=&car4;
	car4.next_car=&car5;
	
	list(car1);
}
	

