#include <iostream>

#include "../Shared/IAnimal.h"
#include "AnimalArray.h"

using namespace std;

AnimalArray::AnimalArray() {
	animals = { 0 };
	size = 0;
}

AnimalArray::~AnimalArray() {
	Free();
}

void AnimalArray::Free() {
	if (size > 0) {
		free(animals);
		size = 0;
	}
}

void AnimalArray::PushBack(IAnimal * animal) {
	IAnimal ** newAnimals = (IAnimal **)malloc(sizeof(IAnimal *) * (size + 1));

	int i;
	for (i = 0; i < size; i++) {
		newAnimals[i] = animals[i];
	}

	newAnimals[size] = animal;

	size++;

	free(animals);
	animals = newAnimals;
}

void AnimalArray::PopBack() {
	if (size == 0) {
		return;
	}

	size--;

	IAnimal ** newAnimals = (IAnimal **)malloc(sizeof(IAnimal *) * size);
	
	int i;
	for (i = 0; i < size; i++) {
		newAnimals[i] = animals[i];
	}

	free(animals);
	animals = newAnimals;
}

IAnimal * AnimalArray::At(int i) {
	if (i > -1 && i < size) {
		return animals[i];
	}
	else {
		return NULL;
	}
}

IAnimal * AnimalArray::Back() {
	return animals[size - 1];
}

size_t AnimalArray::Size() {
	return size;
}
