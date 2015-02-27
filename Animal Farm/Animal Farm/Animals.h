#ifndef ANIMAL_H
#define ANIMAL_H 1

class IAnimal {
public:
	virtual void Speak() = 0;
	virtual void Walk() = 0;
};

class Cat : public IAnimal {
public:
	void Speak();
	void Walk();
};

class Duck : public IAnimal {
public:
	void Speak();
	void Walk();
};

class Horse : public IAnimal {
public:
	void Speak();
	void Walk();
};

#endif // !ANIMAL_H
