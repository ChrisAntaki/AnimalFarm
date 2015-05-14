#include <assert.h>
#include <iostream>
#include <string>


#include "../Shared/FarmSDK.h"
#include "../Shared/FlexibleArray.cpp"
#include "Dog.h"
#include "Fly.h"

using namespace std;

void main() {
	FlexibleArray<int> intArray;

	intArray.PushBack(88);
	assert(intArray.At(0) == 88);

	intArray.Remove(0);
	assert(intArray.Size() == 0);

	intArray.PushBack(66);
	intArray.PushBack(44);
	intArray.PushBack(33);
	intArray.PushBack(22);
	intArray.PushBack(11);
	assert(intArray.Size() == 5);
	assert(intArray.At(1) == 44);

	FlexibleArray<IAnimal *> animalArray;
	animalArray.PushBack(new Dog);
	animalArray.PushBack(new Fly);
	assert(animalArray.Size() == 2);
	assert(strcmp(animalArray.At(0)->GetName(), "Dog") == 0);
	animalArray.Remove(0);
	assert(strcmp(animalArray.At(0)->GetName(), "Fly") == 0);
	animalArray.Remove(0);
	assert(animalArray.Size() == 0);

	cin.get();
}
