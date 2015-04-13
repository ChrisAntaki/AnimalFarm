#pragma once

class IAnimal {
public:
	virtual char * GetName() = 0;
	virtual void Speak() = 0;
	virtual void Walk() = 0;
};

typedef bool (CDECL *PGETIANIMAL)(IAnimal **);
