#include <assert.h>
#include <iostream>
#include <string>


#include "../Shared/FarmSDK.h"
#include "../Shared/PointerArray.cpp"
#include "Dog.h"
#include "Fly.h"

using namespace std;

void main() {
	PointerArray<string> stringArray;

	string word1 = "Word1";
	string word2 = "Word2";

	stringArray.PushBack(&word1);
	stringArray.PushBack(&word2);

	assert(stringArray.Size() == 2);

	cout << *stringArray.At(1) << "\n";

	stringArray.Free();

	cout << "All the tests have passed!\n";

	cin.get();
}
