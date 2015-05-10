#include <assert.h>
#include <iostream>
#include <string>


#include "../Shared/FarmSDK.h"
#include "../Shared/FlexibleArray.cpp"
#include "Dog.h"
#include "Fly.h"

using namespace std;

void main() {
	FlexibleArray<int> stringArray;

	stringArray.PushBack(88);
	stringArray.PushBack(66);
	stringArray.PushBack(44);

	assert(stringArray.Size() == 3);

	cout << stringArray.Back() << "\n";

	stringArray.PopBack();

	cout << stringArray.Back() << "\n";

	stringArray.Free();

	cout << "All the tests have passed!\n";

	cin.get();
}
