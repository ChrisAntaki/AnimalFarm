#include <iostream>
#include "Animals.h"

void Animal::Speak() {
	printf("I don't know what to say...\n");
}

void Animal::Walk() {
	printf("I don't know how to walk...\n");
}

void Cat::Speak() {
	printf("Meow, meow.\n");
}

void Cat::Walk() {
	printf("Stroll, stroll.\n");
}

void Duck::Speak() {
	printf("Quack, quack.\n");
}

void Duck::Walk() {
	printf("Waddle, waddle.\n");
}

void Horse::Speak() {
	printf("Neigh, neigh.\n");
}

void Horse::Walk() {
	printf("Trot, trot.\n");
}
