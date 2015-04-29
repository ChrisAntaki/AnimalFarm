#include <iostream>
#include <windows.h>

#include "../Shared/FarmSDK.h"
#include "../Shared/AnimalArray.cpp"

using namespace std;

// Define class(es)
class Horse : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

const char * Horse::GetName() {
	return "Horse";
}

void Horse::Speak() {
	printf("Nay, nay.\n");
}

void Horse::Walk() {
	printf("Trot, trot.\n");
}

class Chupacabra : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

const char * Chupacabra::GetName() {
	return "Chupacabra";
}

void Chupacabra::Speak() {
	printf("Hiss, hiss.\n");
}

void Chupacabra::Walk() {
	printf("Crunch, crunch.\n");
}

class Unicorn : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

const char * Unicorn::GetName() {
	return "Unicorn";
}

void Unicorn::Speak() {
	printf("La, la, la.\n");
}

void Unicorn::Walk() {
	printf("Whoosh, whoosh.\n");
}

// Export
extern "C"
{
	__declspec(dllexport) bool CDECL GetIAnimals(AnimalArray * animals)
	{
		animals->PushBack(new Horse);
		animals->PushBack(new Chupacabra);
		animals->PushBack(new Unicorn);

		return true;
	}
}
