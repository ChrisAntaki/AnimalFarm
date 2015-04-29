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
	IAnimal ** m_animals;
	const int m_chunkSize = 64;
	int m_size = 0;
	int m_sizeOfMemory = 0;
	void Reallocate();

	// Sorting
	void BuildHeap();
	int Compare(int, int);
	void Heapify(int, int);
	void Reverse();
	void Swap(int, int);

};

typedef bool (CDECL *PGETIANIMALS)(AnimalArray *);
