#include <iostream>
#include <windows.h>

#include "../Shared/IAnimal.h"

IAnimal *g_pIAnimal = NULL;

//This is called by windows for startup and shutdown
BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,
	DWORD fdwReason,
	LPVOID lpvReserved
	)
{
	//If it's shutting down, delete our animal instance
	if (DLL_PROCESS_DETACH == fdwReason)
		delete g_pIAnimal;

	return TRUE;
}

//Our plugin's class
class Duck : public IAnimal {
public:
	char * GetName();
	void Speak();
	void Walk();
};

char * Duck::GetName() {
	return "Duck";
}

void Duck::Speak() {
	printf("Quack, quack.\n");
}

void Duck::Walk() {
	printf("Waddle, waddle.\n");
}

//extern "C" tells the compiler to not name-mangle the function name...
//in C++ function names are turned into more complicated (mangled) names behind the scene
//but since we're looking it up by name in our Farm App, we need the name exactly as it appears in code
extern "C"
{
	//__declspec(dllexport) tells the project to export the address so it can be found with GetProcAddress

	//CDECL... 
	//  tells the compiler how to handle pushing/popping variables and the return addresses on the stack
	//  we specifically declare it here so it's consistent 
	//  also it prevents the compiler from adding on an _ and numerator to the end of function name
	//  I'm not sure why it does this - I'd have to reseach more
	__declspec(dllexport) bool CDECL GetIAnimal(IAnimal **pIAnimal)
	{
		*pIAnimal = new Duck;

		return true;
	}
}

