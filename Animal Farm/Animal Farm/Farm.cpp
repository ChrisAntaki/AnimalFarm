#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "../Shared/AnimalArray.cpp"
#include "../Shared/IAnimal.h"

using namespace std;

static char fullPath[MAX_PATH] = { 0 };
static AnimalArray animals;

bool LoadPlugin(const char * pFilepath)
{
	HMODULE hModule;

	bool success = false;

	do
	{
		//Attempt to load the DLL
		hModule = LoadLibrary(pFilepath);
		if (NULL == hModule) break;

		PGETIANIMALS getAnimals = (PGETIANIMALS)GetProcAddress(hModule, "GetIAnimals");
		if (NULL == getAnimals) break;
		getAnimals(&animals);

		success = true;
	} while (false);

	//If it failed to load as a plugin, free the library
	if (false == success && NULL != hModule) {
		FreeLibrary(hModule);
	}

	return success;
}

void AddAnimals()
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

bool SortAnimals(IAnimal * a, IAnimal * b) {
	return strcmp(b->GetName(), a->GetName()) > 0;
}

void exit_due_to_invalid_input() {
	cout << "Sorry, that input wasn't recognized.\n";
	cin.get();
	exit(0);
}

char get_single_char() {
	char input;
	cin >> input;
	cin.ignore(INT_MAX, '\n');
	return input;
}

void main(int argc, const char *pArgv[]) {
	//Save full path of directory.
	strncpy_s(fullPath, pArgv[0], sizeof(fullPath) - 1);

	//Load animals from DLLs.
	AddAnimals();
	//sort(animals.begin(), animals.end(), SortAnimals);

	//List animals as options.
	system("cls");
	if (animals.Size() == 0) {
		cout << "Where have all the animals gone? Animals?!\nPlease build an animal DLL to continue.\n";
		cin.get();
		return;
	}
	else {
		cout << "Please choose an animal:\n";
	}

	animals.HeapSort();
	for (int i = 0; i < (int)animals.Size(); i++) {
		cout << (i + 1) << ". " << animals.At(i)->GetName() << "\n";
	}

	int index = get_single_char() - '0' - 1;

	if (index < 0 || index > animals.Size() - 1) {
		exit_due_to_invalid_input();
	}

	IAnimal * animal = animals.At(index);

	system("cls");
	cout
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

	//Release memory.
	while (animals.Size() > 0) {
		delete animals.Back();
		animals.PopBack();
	}

	cin.get();
}
