#pragma once

#include <windows.h>

#include "IAnimal.h"

class AnimalArray {

public:
	AnimalArray();
	~AnimalArray();

	IAnimal * At(int);
	IAnimal * Back();
	void Free();
	void PopBack();
	void PushBack(IAnimal *);
	int Size();
	
	// Sorting
	void BubbleSort();
	void HeapSort();

private:
	IAnimal ** animals;
	const int chunkSize = 64;
	int size = 0;
	int sizeOfMemory = 0;
	void Reallocate();

	// Sorting
	void BuildHeap();
	int Compare(int, int);
	void Heapify(int, int);
	void Reverse();
	void Swap(int, int);

};

typedef bool (CDECL *PGETIANIMALS)(AnimalArray *);
