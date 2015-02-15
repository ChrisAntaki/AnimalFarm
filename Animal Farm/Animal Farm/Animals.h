#ifndef ANIMAL_H
#define ANIMAL_H 1

class Animal {
public:
	virtual void Speak();
	virtual void Walk();
};

class Cat : public Animal {
public:
	virtual void Speak();
	virtual void Walk();
};

class Duck : public Animal {
public:
	virtual void Speak();
	virtual void Walk();
};

class Horse : public Animal {
public:
	virtual void Speak();
	virtual void Walk();
};

#endif // !ANIMAL_H
