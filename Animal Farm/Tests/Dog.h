#include "../Shared/IAnimal.h"

class Dog : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};
