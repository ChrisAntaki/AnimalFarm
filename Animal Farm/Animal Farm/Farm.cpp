#include <iostream>
#include <string>
#include "Animals.h"

void exit_due_to_invalid_input() {
	std::cout << "Sorry, that input wasn't recognized.\n";
	std::cin.get();
	exit(0);
}

void main() {
	Animal * animal;

	std::cout
		<< "Please choose an animal:\n"
		<< "1. Cat\n"
		<< "2. Duck\n"
		<< "3. Horse\n";

	std::string response;
	std::cin >> response;
	std::cin.ignore();

	switch (response[0]) {
	case '1':
		animal = new Cat();
		break;
	case '2':
		animal = new Duck();
		break;
	case '3':
		animal = new Horse();
		break;
	default:
		exit_due_to_invalid_input();
		break;
	}

	std::cout
		<< "Please choose an action:\n"
		<< "1. Speak\n"
		<< "2. Walk\n";

	std::cin >> response;
	std::cin.ignore();

	std::cout << "\n";

	switch (response[0]) {
	case '1':
		animal->Speak();
		break;
	case '2':
		animal->Walk();
		break;
	default:
		exit_due_to_invalid_input();
		break;
	}

	delete animal;

	std::cin.get();
}
