#include <iostream>

#include "FarmSDK.h"

using namespace std;

template <class ClassA> AnimalArray<ClassA>::AnimalArray() {
}

template <class ClassA> AnimalArray<ClassA>::~AnimalArray() {
	Free();
}

template <class ClassA> ClassA * AnimalArray<ClassA>::At(int i) {
	if (i > -1 && i < m_size) {
		return m_animals[i];
	}
	else {
		return NULL;
	}
}

template <class ClassA> ClassA * AnimalArray<ClassA>::Back() {
	return m_animals[m_size - 1];
}

template <class ClassA> void AnimalArray<ClassA>::Free() {
	if (m_size > 0) {
		free(m_animals);
		m_size = 0;
	}
}

template <class ClassA> void AnimalArray<ClassA>::PopBack() {
	if (m_size == 0) {
		return;
	}

	m_size--;

	Reallocate();
}

template <class ClassA> void AnimalArray<ClassA>::PushBack(ClassA * animal) {
	m_size++;

	Reallocate();

	m_animals[m_size - 1] = animal;
}

template <class ClassA> void AnimalArray<ClassA>::Reallocate() {
	int sizeOfMemory = ((m_size + m_chunkSize - 1) / m_chunkSize) * m_chunkSize * sizeof(ClassA *);
	m_animals = (ClassA **)realloc(m_animals, sizeOfMemory);
}

template <class ClassA> int AnimalArray<ClassA>::Size() {
	return m_size;
}

// Sorting (public)

template <class ClassA> void AnimalArray<ClassA>::BubbleSort() {
	for (int i = 0; i < m_size; i++) {
		for (int ii = 1; ii < m_size - i; ii++) {
			if (Compare(ii - 1, ii) > 0) {
				Swap(ii, ii - 1);
			}
		}
	}
}

template <class ClassA> void AnimalArray<ClassA>::HeapSort() {
	BuildHeap();

	int last = m_size - 1;
	while (last > 0) {
		Swap(0, last);
		last--;
		Heapify(0, last);
	}

	Reverse();
}

// Sorting (private)

template <class ClassA> void AnimalArray<ClassA>::BuildHeap() {
	for (int i = (m_size - 2) / 2; i > -1; i--) {
		Heapify(i, m_size - 1);
	}
}

template <class ClassA> int AnimalArray<ClassA>::Compare(int a, int b) {
	return strcmp(m_animals[a]->GetName(), m_animals[b]->GetName());
}

template <class ClassA> void AnimalArray<ClassA>::Heapify(int parent, int last) {
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

template <class ClassA> void AnimalArray<ClassA>::Reverse() {
	float half = (float)m_size / 2;

	for (int i = 0; i < half; i++) {
		if (i == m_size - i - 1) {
			break;
		}

		Swap(i, m_size - i - 1);
	}
}

template <class ClassA> void AnimalArray<ClassA>::Swap(int a, int b) {
	ClassA * temp = m_animals[a];
	m_animals[a] = m_animals[b];
	m_animals[b] = temp;
}
