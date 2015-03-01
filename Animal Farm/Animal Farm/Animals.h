#ifndef ANIMAL_H
#define ANIMAL_H 1

class IAnimal {
public:
	virtual char * GetName() = 0;
	virtual void Speak() = 0;
	virtual void Walk() = 0;
};

class Cat : public IAnimal {
public:
	char * GetName();
	void Speak();
	void Walk();
};

class Duck : public IAnimal {
public:
	char * GetName();
	void Speak();
	void Walk();
};

class Horse : public IAnimal {
public:
	char * GetName();
	void Speak();
	void Walk();
};

#endif // !ANIMAL_H
