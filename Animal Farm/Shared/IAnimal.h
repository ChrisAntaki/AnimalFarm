#pragma once

#include <vector>

using namespace std;

class IAnimal {
public:
	virtual const char * GetName() = 0;
	virtual void Speak() = 0;
	virtual void Walk() = 0;
};

typedef bool (CDECL *PGETIANIMALS)(vector<IAnimal*> *);
