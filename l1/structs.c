#include <stdio.h>
#include <stdlib.h>


typedef struct Car {
	char * carName;
	int tankVolume;
	int maxSpeed;
} car_t;

void printCarDescription(car_t car) {
	printf("car %s has tankVolume = %d and maxSpeed = %d\n", car.carName, car.tankVolume, car.maxSpeed);
}


int compareTwoCars(car_t lhs, car_t rhs) {
	if (lhs.maxSpeed > rhs.maxSpeed) {
		return 1;
	} else if (lhs.maxSpeed < rhs.maxSpeed) {
		return -1;
	} else {
		if (lhs.tankVolume > rhs.tankVolume) {
			return 1;
		} else if (lhs.tankVolume < rhs.tankVolume) {
			return -1;
		}
		return 0;
	}
					  
}

int main() {
	car_t bmw = {"BMW", 40, 220};
	printCarDescription(bmw);
	car_t audi = {"AUDI", 40, 210};
	int compareResult = compareTwoCars(bmw, audi);
	
	if (compareResult == 1) printf ("BMW is bettter\n");
	
	
	car_t * p_car = (car_t*) malloc(1*sizeof(car_t));
	p_car -> carName = "Lada";
	p_car -> tankVolume = 50;// === (*p_car).tankVolume = 50
	p_car -> maxSpeed = 140;
	free(p_car);
	
	
	return 0;
}