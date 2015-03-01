#include <iostream>
#include <string>
#include "Animals.h"

void exit_due_to_invalid_input() {
	std::cout << "Sorry, that input wasn't recognized.\n";
	std::cin.get();
	exit(0);
}

char get_single_char() {
	char input;
	std::cin >> input;
	std::cin.ignore(INT_MAX, '\n');
	return input;
}

void main() {
	IAnimal * animal;

	system("cls");
	std::cout
		<< "Please choose an animal:\n"
		<< "1. Cat\n"
		<< "2. Duck\n"
		<< "3. Horse\n";

	switch (get_single_char()) {
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

	system("cls");
	std::cout
		<< "Please choose an action:\n"
		<< "1. Speak\n"
		<< "2. Walk\n";

	switch (get_single_char()) {
	case '1':
		system("cls");
		animal->Speak();
		break;
	case '2':
		system("cls");
		animal->Walk();
		break;
	default:
		exit_due_to_invalid_input();
		break;
	}

	delete animal;

	std::cin.get();
}
