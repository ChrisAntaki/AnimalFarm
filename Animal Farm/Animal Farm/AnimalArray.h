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

private:
	IAnimal ** animals;
	int size;

};

typedef bool (CDECL *PGETIANIMALS)(AnimalArray *);
