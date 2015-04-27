#pragma once

#include <windows.h>

#include "../Shared/IAnimal.h"

class AnimalArray {

public:
	AnimalArray();
	~AnimalArray();

	IAnimal * At(int);
	IAnimal * Back();
	void Free();
	void PopBack();
	void PushBack(IAnimal *);
	size_t Size();
	
	// Sorting
	void BubbleSort();
	void HeapSort();

private:
	IAnimal ** animals;
	int size;

	// Sorting
	void BuildHeap();
	int Compare(int, int);
	void Heapify(int, int);
	void Reverse();
	void Swap(int, int);

};

typedef bool (CDECL *PGETIANIMALS)(AnimalArray *);
