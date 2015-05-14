#pragma once

#include <windows.h>

#include "IAnimal.h"

template <class ClassA> class FlexibleArray {

public:
	FlexibleArray();
	~FlexibleArray();

	ClassA At(int);
	ClassA Back();
	ClassA * Begin();
	ClassA * End();
	void Free();
	void PopBack();
	void PushBack(ClassA);
	void Remove(int);
	int Size();

private:
	ClassA * m_items = NULL;
	const int m_chunkSize = 64;
	int m_size = 0;
	void Reallocate();

};

typedef bool (CDECL *PGETIANIMALS)(FlexibleArray<IAnimal *> *);
