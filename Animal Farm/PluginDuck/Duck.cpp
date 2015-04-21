#include <iostream>
#include <windows.h>

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
	__declspec(dllexport) bool CDECL GetIAnimals(vector<IAnimal*> * animals)
	{
		animals->push_back(new Duck);

		return true;
	}
}

