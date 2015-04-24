#include "../Shared/IAnimal.h"

class AnimalArray {

public:
	AnimalArray();
	~AnimalArray();

	IAnimal * Back();
	void Free();
	void PopBack();
	void PushBack(IAnimal *);
	size_t Size();

private:
	IAnimal ** animals;
	int size;

};
