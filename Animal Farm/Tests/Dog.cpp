#include <iostream>

#include "Dog.h"

using namespace std;

const char * Dog::GetName() {
	return "Dog";
}

void Dog::Speak() {
	cout << "Woof, woof.\n";
}

void Dog::Walk() {
	cout << "Stomp, stomp.\n";
}
