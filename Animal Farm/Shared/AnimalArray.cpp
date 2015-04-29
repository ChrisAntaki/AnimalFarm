#include <iostream>

#include "FarmSDK.h"

using namespace std;

AnimalArray::AnimalArray() {
}

AnimalArray::~AnimalArray() {
	Free();
}

IAnimal * AnimalArray::At(int i) {
	if (i > -1 && i < m_size) {
		return m_animals[i];
	}
	else {
		return NULL;
	}
}

IAnimal * AnimalArray::Back() {
	return m_animals[m_size - 1];
}

void AnimalArray::Free() {
	if (m_size > 0) {
		free(m_animals);
		m_size = 0;
	}
}

void AnimalArray::PopBack() {
	if (m_size == 0) {
		return;
	}

	m_size--;

	Reallocate();
}

void AnimalArray::PushBack(IAnimal * animal) {
	m_size++;

	Reallocate();

	m_animals[m_size - 1] = animal;
}

void AnimalArray::Reallocate() {
	int sizeOfMemory = ((m_size + m_chunkSize - 1) / m_chunkSize) * m_chunkSize * sizeof(IAnimal *);
	m_animals = (IAnimal **)realloc(m_animals, sizeOfMemory);
}

int AnimalArray::Size() {
	return m_size;
}

// Sorting (public)

void AnimalArray::BubbleSort() {
	for (int i = 0; i < m_size; i++) {
		for (int ii = 1; ii < m_size - i; ii++) {
			if (Compare(ii - 1, ii) > 0) {
				Swap(ii, ii - 1);
			}
		}
	}
}

void AnimalArray::HeapSort() {
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

void AnimalArray::BuildHeap() {
	for (int i = (m_size - 2) / 2; i > -1; i--) {
		Heapify(i, m_size - 1);
	}
}

int AnimalArray::Compare(int a, int b) {
	return strcmp(m_animals[a]->GetName(), m_animals[b]->GetName());
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
	float half = (float)m_size / 2;

	for (int i = 0; i < half; i++) {
		if (i == m_size - i - 1) {
			break;
		}

		Swap(i, m_size - i - 1);
	}
}

void AnimalArray::Swap(int a, int b) {
	IAnimal * temp = m_animals[a];
	m_animals[a] = m_animals[b];
	m_animals[b] = temp;
}
