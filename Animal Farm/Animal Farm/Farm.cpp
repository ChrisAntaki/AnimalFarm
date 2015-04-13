#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "../Shared/IAnimal.h"

char fullPath[MAX_PATH] = { 0 };
std::vector<PGETIANIMAL> constructors;
std::vector<IAnimal*> animals;
IAnimal * animal;

bool LoadPlugin(const char *pFilepath)
{
	HMODULE hModule;

	bool success = false;

	do
	{
		//Attempt to load the DLL
		hModule = LoadLibrary(pFilepath);
		if (NULL == hModule) break;

		//If it loaded, see if it has a function "GetIAnimal".. 
		//GetProcAddress will return the address of the function (I.e. a pointer to it) if it exists
		PGETIANIMAL p = (PGETIANIMAL)GetProcAddress(hModule, "GetIAnimal");
		if (NULL == p) break;

		//Save the constructor.
		constructors.push_back(p);

		success = true;
	} while (false);

	//If it failed to load as a plugin, free the library
	if (false == success && NULL != hModule)
		FreeLibrary(hModule);

	return success;
}

void AddConstructors()
{
	//Figure out the directory the exe is running in
	//and append *.dll to it so we can search for all the dlls in the directory

	//Determine the full exe path, copy it over
	char directory[MAX_PATH] = { 0 };
	strncpy_s(directory, fullPath, sizeof(directory) - 1);

	//find the last slash in the path and null it out
	//this leaves us with the directory but not the exe
	char *pLastSlash = strrchr(directory, '\\');
	if (NULL != pLastSlash) *pLastSlash = NULL;

	//concantenate *.dll to the directory
	strncat_s(directory, "\\*.dll", sizeof(directory) - strlen(directory) - 1);

	//Loop through all the *.dll files in the directory
	WIN32_FIND_DATA findFileData;
	HANDLE hFind = FindFirstFile(directory, &findFileData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			//Assume each dll is a plugin we want to load
			LoadPlugin(findFileData.cFileName);
		} while (TRUE == FindNextFile(hFind, &findFileData));

		FindClose(hFind);
	}
}

void exit_due_to_invalid_input() {
	std::cout << "Sorry, that input wasn't recognized.\n";
	std::cin.get();
	exit(0);
}

char get_single_char() {
	char input;
	std::cin >> input;
	std::cin.ignore(INT_MAX, '\n');
	return input;
}

void main(int argc, const char *pArgv[]) {
	//Save full path of directory.
	strncpy_s(fullPath, pArgv[0], sizeof(fullPath) - 1);

	//Load constructors from DLLs.
	AddConstructors();

	//List animals as options.
	system("cls");
	std::cout << "Please choose an animal:\n";
	for (int i = 0; i < (int)constructors.size(); i++) {
		constructors.at(i)(&animal);
		animals.push_back(animal);

		std::cout << (i + 1) << ". " << animal->GetName() << "\n";
	}

	int index = get_single_char() - '0' - 1;

	if (index < 0 || index > animals.size()) {
		exit_due_to_invalid_input();
	}

	animal = animals.at(index);

	system("cls");
	std::cout
		<< "Please choose an action for the " << animal->GetName() << ":\n"
		<< "1. Speak\n"
		<< "2. Walk\n";

	switch (get_single_char()) {
	case '1':
		system("cls");
		printf("The %s is talking.\n  ", animal->GetName());
		animal->Speak();
		break;
	case '2':
		system("cls");
		printf("The %s is walking.\n  ", animal->GetName());
		animal->Walk();
		break;
	default:
		exit_due_to_invalid_input();
		break;
	}

	delete animal;

	std::cin.get();
}
