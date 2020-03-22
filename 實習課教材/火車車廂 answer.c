#include <stdio.h>
#include <string.h>

#define MAX_SEATING 6


// Struct of passenger
typedef struct passenger {
    char *name;
    char *phone_number;
    char *seat;
    int age;
    double money_in_wallet;
} Passenger;

// Struct of railcar
typedef struct railcar {
    int car_number;
    struct railcar *next_railcar;
    struct passenger p[MAX_SEATING];
} Railcar;



// Init an empty passenger
const Passenger k_empty_passenger = {"", "", "", 0, 0};

// Init an empty railcar with a car number
Railcar initRailcar(int car_number) {
    Railcar init_railcar_obj = { car_number, 
                                 NULL, 
                                 { k_empty_passenger, k_empty_passenger, 
                                   k_empty_passenger, k_empty_passenger, 
                                   k_empty_passenger, k_empty_passenger }
                               };
    return(init_railcar_obj);
}


// Compare two passenger is equal or not
int isEqualPassenger(Passenger p1, Passenger p2) {
    int name_equality = (strcmp(p1.name, p2.name) == 0);
    int phone_equality = (strcmp(p1.phone_number, p2.phone_number) == 0);
    int money_equality = (p1.money_in_wallet == p2.money_in_wallet);
    int age_equality = (p1.age == p2.age);
    int seat_equality = (strcmp(p1.seat, p2.seat) == 0);
    return(name_equality && phone_equality && money_equality && age_equality && seat_equality);
}


// Print passenger's information
void printPassengerInfo(Passenger p) {
    printf("%s: %+8s, %+10s, %3d yo, $%'.2f \n", 
           p.seat, p.name, p.phone_number,
           p.age, p.money_in_wallet);
}


// Print railcar's inforamtion (including passengers on the railcar)
void printRailcar(Railcar car) {
    
    int passenger_count = 0;
    
    printf("[Car %d]\n", car.car_number);
    
    for(int i = 0; i < MAX_SEATING; i++) {
        // Skip empty passenger
        if (isEqualPassenger(car.p[i], k_empty_passenger) == 0) {
            printPassengerInfo(car.p[i]);
            passenger_count = passenger_count + 1;
        }
    }
    
    if (passenger_count == 0) {
        printf("None, it's an empty railcar.\n");
    }
    
}


// Traversal railcars
void traversalRailcar(Railcar start_railcar) {
    
    // Print information of railcar
    printRailcar(start_railcar);
    
    // If there is a next railcar.
    if (start_railcar.next_railcar != NULL) {
        // Traversal the next railcar
        traversalRailcar(*(start_railcar.next_railcar));
    }
    
}



/* =============
 * Main function 
 * ============= */
int main(void) {
    
    // Init passengers
    Passenger mike   = {"Mike", "0912345678", "1A", 17, 1983.15};
    Passenger david  = {"David", "0998765612", "1B", 23, 991.2};
    Passenger bowen  = {"Bowen", "0971572281", "1A", 38, 1002.1};
    Passenger monica = {"Monica", "0938001881", "1B", 19, 299.31};
    Passenger terry  = {"Terry", "0918302849", "2A", 53, 10034.2};
    Passenger jimmy  = {"Jimmy", "0988402981", "1A", 88, 8023.1};
    
    // Init railcars
    Railcar car1 = initRailcar(1);
    Railcar car2 = initRailcar(2);
    Railcar car3 = initRailcar(3);
    Railcar car4 = initRailcar(4);
    Railcar car5 = initRailcar(5);
    Railcar car6 = initRailcar(6);
    
    // Connect railcar order by order
    car1.next_railcar = &car2;
    car2.next_railcar = &car3;
    car3.next_railcar = &car4;
    car4.next_railcar = &car5;
    car5.next_railcar = &car6;
    
    // Arrange seats
    car1.p[0] = mike;
    car1.p[1] = david;
    car2.p[0] = bowen;
    car2.p[1] = monica;
    car3.p[0] = terry;
    car3.p[1] = jimmy;
    
    // Traversal from first railcar to list passenger's info
    traversalRailcar(car1);
    
    return(0);
}