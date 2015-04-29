#include <assert.h>
#include <iostream>


#include "../Shared/FarmSDK.h"
#include "../Shared/AnimalArray.cpp"
#include "Dog.h"
#include "Fly.h"

using namespace std;

void main() {
	Dog * dog = new Dog;
	Fly * fly = new Fly;
	Floi * floi = new Floi;
	
	AnimalArray animalArray;
	assert(animalArray.Size() == 0);

	animalArray.PushBack(fly);
	assert(animalArray.Size() == 1);

	animalArray.PushBack(dog);
	assert(animalArray.Size() == 2);

	animalArray.PushBack(fly);
	assert(animalArray.Size() == 3);

	animalArray.PushBack(dog);
	assert(animalArray.Size() == 4);

	animalArray.PushBack(floi);
	assert(animalArray.Size() == 5);

	int i;
	for (i = 0; i < animalArray.Size(); i++) {
		cout << animalArray.At(i)->GetName() << "\n";
	}

	cout << "Sorting...\n";

	// Please sort, good Array.
	animalArray.HeapSort();

	for (i = 0; i < animalArray.Size(); i++) {
		cout << animalArray.At(i)->GetName() << "\n";
	}

	animalArray.PopBack();
	assert(animalArray.Size() == 4);

	animalArray.Free();
	assert(animalArray.Size() == 0);

	// Free() should be idempotent
	animalArray.Free();
	animalArray.Free();

	cout << "All the tests have passed!\n";

	cin.get();
}
