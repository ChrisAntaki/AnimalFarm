#include "../Shared/IAnimal.h"

class Fly : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};

class Floi : public IAnimal {
public:
	const char * GetName();
	void Speak();
	void Walk();
};
