/**
Author: Yuzhe Hung
Date: 2018/05/07
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct passenger{
	char seat[5];
	char name[10];
	char phone[10];
	int age;
	float balance;
} Passenger;

typedef struct car{
	char name[10];
	struct passenger *p;
 	struct car *next;
} Car;

void list(Car *ptr){
//	while(ptr != NULL){
//		printf("%s: %s, %s, %d, %f\n", ptr->p->seat, ptr->p->name, ptr->p->phone, ptr->p->age,ptr->p->balance);
//		ptr = ptr->next;
//	}
	if(ptr != NULL){
		list(ptr->next);
		printf("%s: %s, %s, %d, %f\n", ptr->p->seat, ptr->p->name, ptr->p->phone, ptr->p->age,ptr->p->balance);
	}
	return;
}

struct passenger newPassenger(char seat[5],char name[10],char phone[10],int age,float balance){
	Passenger temp;
	strcpy(temp.seat, seat);
	strcpy(temp.name, name);
	strcpy(temp.phone, phone);
	temp.age = age;
	temp.balance = balance;
	return temp;
}

int main(void){
	// Declare Passenger Data
	Passenger Albee = newPassenger("1A", "Albee", "0900000000", 18, 10.1);
	Passenger Bob = newPassenger("1B", "Bob", "0911111111", 19, 10.2);

	// Declare Car Data
  Car car1, car2;
	strcpy(car1.name, "car 1");
	car1.p = &Albee;
	car1.next = &car2;

	strcpy(car2.name, "car 2");
	car2.p = &Bob;
	car2.next = NULL;

	Car *temp = &car1;
	list(temp);

	return 0;
}
