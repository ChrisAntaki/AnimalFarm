#include <iostream>
#include <vector>
#include <windows.h>

#include "../Shared/IAnimal.h"

using namespace std;

// Define class(es)
class Cat : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

const char * Cat::GetName() {
	return "Cat";
}

void Cat::Speak() {
	printf("Meow, meow.\n");
}

void Cat::Walk() {
	printf("Stroll, stroll.\n");
}

class LochNessMonster : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

const char * LochNessMonster::GetName() {
	return "Loch Ness Monster";
}

void LochNessMonster::Speak() {
	printf("You found me!?\n");
}

void LochNessMonster::Walk() {
	printf("Splish, splash.\n");
}

// Export
extern "C"
{
	__declspec(dllexport) bool CDECL GetIAnimals(vector<IAnimal*> * animals)
	{
		animals->push_back(new Cat);
		animals->push_back(new LochNessMonster);

		return true;
	}
}
