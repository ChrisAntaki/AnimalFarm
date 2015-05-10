#include <iostream>
#include <stdexcept>

#include "FarmSDK.h"

using namespace std;

template <class ClassA> FlexibleArray<ClassA>::FlexibleArray() {
}

template <class ClassA> FlexibleArray<ClassA>::~FlexibleArray() {
	Free();
}

template <class ClassA> ClassA FlexibleArray<ClassA>::At(int i) {
	if (i < 0 && i > m_size - 1) {
		throw out_of_range("That element doesn't exist.");
	}

	return m_items[i];
}

template <class ClassA> ClassA FlexibleArray<ClassA>::Back() {
	if (m_size == 0) {
		throw out_of_range("This array is empty.");
	}

	return m_items[m_size - 1];
}

template <class ClassA> ClassA * FlexibleArray<ClassA>::Begin() {
	return m_items;
}

template <class ClassA> ClassA * FlexibleArray<ClassA>::End() {
	return m_items + m_size;
}

template <class ClassA> void FlexibleArray<ClassA>::Free() {
	if (m_size > 0) {
		free(m_items);
		m_size = 0;
	}
}

template <class ClassA> void FlexibleArray<ClassA>::PopBack() {
	if (m_size == 0) {
		return;
	}

	m_size--;

	Reallocate();
}

template <class ClassA> void FlexibleArray<ClassA>::PushBack(ClassA item) {
	m_size++;

	Reallocate();

	m_items[m_size - 1] = item;
}

template <class ClassA> int FlexibleArray<ClassA>::Size() {
	return m_size;
}

template <class ClassA> void FlexibleArray<ClassA>::Reallocate() {
	int sizeOfMemory = ((m_size + m_chunkSize - 1) / m_chunkSize) * m_chunkSize * sizeof(ClassA);
	m_items = (ClassA *)realloc(m_items, sizeOfMemory);
}
