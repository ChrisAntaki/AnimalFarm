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
	cout << "Size: " << stringArray.Size() << "\n";
	cout << "@1: " << stringArray.At(0) << "\n";

	stringArray.Remove(0);
	cout << "Size: " << stringArray.Size() << "\n";

	stringArray.PushBack(66);
	stringArray.PushBack(44);
	stringArray.PushBack(33);
	stringArray.PushBack(22);
	stringArray.PushBack(11);
	cout << "Size: " << stringArray.Size() << "\n";
	cout << "@1: " << stringArray.At(1) << "\n";

	cin.get();
}
