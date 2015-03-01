#include <iostream>
#include "Animals.h"

char * Cat::GetName() {
	return "Cat";
}

void Cat::Speak() {
	printf("Meow, meow.\n");
}

void Cat::Walk() {
	printf("Stroll, stroll.\n");
}

char * Duck::GetName() {
	return "Duck";
}

void Duck::Speak() {
	printf("Quack, quack.\n");
}

void Duck::Walk() {
	printf("Waddle, waddle.\n");
}

char * Horse::GetName() {
	return "Horse";
}

void Horse::Speak() {
	printf("Neigh, neigh.\n");
}

void Horse::Walk() {
	printf("Trot, trot.\n");
}
