#include <iostream>

#include "../Shared/IAnimal.h"
#include "AnimalArray.h"

using namespace std;

AnimalArray::AnimalArray() {
}

AnimalArray::~AnimalArray() {
	Free();
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

void AnimalArray::Free() {
	if (size > 0) {
		free(animals);
		size = 0;
		sizeOfMemory = 0;
	}
}

void AnimalArray::PopBack() {
	if (size == 0) {
		return;
	}

	size--;

	Reallocate();
}

void AnimalArray::PushBack(IAnimal * animal) {
	size++;

	Reallocate();

	animals[size - 1] = animal;
}

void AnimalArray::Reallocate() {
	int newSizeOfMemory = ((size + chunkSize - 1) / chunkSize) * chunkSize * sizeof(IAnimal *);

	if (sizeOfMemory == newSizeOfMemory) {
		return;
	}

	IAnimal ** newAnimals = (IAnimal **)malloc(newSizeOfMemory);

	if (sizeOfMemory > 0 && newSizeOfMemory > 0) {
		int sizeOfMemoryToCopy = (sizeOfMemory < newSizeOfMemory) ? sizeOfMemory : newSizeOfMemory;
		memmove(newAnimals, animals, sizeOfMemoryToCopy);
	}

	free(animals);
	animals = newAnimals;
	sizeOfMemory = newSizeOfMemory;
}

int AnimalArray::Size() {
	return size;
}

// Sorting (public)

void AnimalArray::BubbleSort() {
	for (int i = 0; i < size; i++) {
		for (int ii = 1; ii < size - i; ii++) {
			if (Compare(ii - 1, ii) > 0) {
				Swap(ii, ii - 1);
			}
		}
	}
}

void AnimalArray::HeapSort() {
	BuildHeap();

	int last = size - 1;
	while (last > 0) {
		Swap(0, last);
		last--;
		Heapify(0, last);
	}

	Reverse();
}

// Sorting (private)

void AnimalArray::BuildHeap() {
	for (int i = (size - 2) / 2; i > -1; i--) {
		Heapify(i, size - 1);
	}
}

int AnimalArray::Compare(int a, int b) {
	return strcmp(animals[a]->GetName(), animals[b]->GetName());
}

void AnimalArray::Heapify(int parent, int last) {
	int child = parent * 2 + 1;
	while (child <= last) {
		if (child + 1 <= last && Compare(child, child + 1) > 0) {
			child++;
		}

		if (Compare(child, parent) < 0) {
			Swap(child, parent);

			parent = child;
			child = 2 * parent + 1;
			continue;
		}
		else {
			break;
		}
	}
}

void AnimalArray::Reverse() {
	float half = (float)size / 2;

	for (int i = 0; i < half; i++) {
		if (i == size - i - 1) {
			break;
		}

		Swap(i, size - i - 1);
	}
}

void AnimalArray::Swap(int a, int b) {
	IAnimal * temp = animals[a];
	animals[a] = animals[b];
	animals[b] = temp;
}
