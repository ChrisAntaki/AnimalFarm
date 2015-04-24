#include <assert.h>
#include <iostream>

#include "../Animal Farm/AnimalArray.cpp"
#include "Dog.h"

using namespace std;

void main() {
	Dog * dog = new Dog;
	
	AnimalArray animalArray;
	assert(animalArray.Size() == 0);

	animalArray.PushBack(dog);
	assert(animalArray.Size() == 1);

	animalArray.PushBack(dog);
	assert(animalArray.Size() == 2);

	animalArray.PopBack();
	assert(animalArray.Size() == 1);

	animalArray.Free();
	assert(animalArray.Size() == 0);

	// Free() should be idempotent
	animalArray.Free();
	animalArray.Free();

	cout << "All the tests have passed!\n";

	cin.get();
}
