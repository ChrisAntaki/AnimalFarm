#pragma once

#include <windows.h>

#include "IAnimal.h"

template <class ClassA> class PointerArray {

public:
	PointerArray();
	~PointerArray();

	ClassA * At(int);
	ClassA * Back();
	void Free();
	void PopBack();
	void PushBack(ClassA *);
	int Size();
	
	// Sorting
	void BubbleSort();
	void HeapSort();

private:
	ClassA ** m_animals = NULL;
	const int m_chunkSize = 64;
	int m_size = 0;
	void Reallocate();

	// Sorting
	void BuildHeap();
	int Compare(int, int);
	void Heapify(int, int);
	void Reverse();
	void Swap(int, int);

};

typedef bool (CDECL *PGETIANIMALS)(PointerArray<IAnimal> *);
