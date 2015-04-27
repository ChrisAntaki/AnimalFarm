#include <iostream>
#include <windows.h>

#include "../Animal Farm/AnimalArray.cpp"
#include "../Shared/IAnimal.h"

using namespace std;

// Define class(es)
class Duck : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

const char * Duck::GetName() {
	return "Duck";
}

void Duck::Speak() {
	printf("Quack, quack.\n");
}

void Duck::Walk() {
	printf("Waddle, waddle.\n");
}

// Export
extern "C"
{
	__declspec(dllexport) bool CDECL GetIAnimals(AnimalArray * animals)
	{
		animals->PushBack(new Duck);

		return true;
	}
}

