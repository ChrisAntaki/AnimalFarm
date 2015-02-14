#include <iostream>

#include "Animals.h"

void Animal::Speak() {
	printf("I don't know what to say...\n");
}

void Animal::Walk() {
	printf("I don't know how to walk...\n");
}

void Duck::Speak() {
	printf("Quack, quack.\n");
}

void Duck::Walk() {
	printf("Waddle, waddle.\n");
}
