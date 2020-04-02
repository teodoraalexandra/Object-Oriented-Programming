class Animal
{
public:
	virtual void eat() = 0;
};


class Mammal : public virtual Animal 
{
public:
	virtual void breathe() = 0;
	void eat() override {}
};

class WingedAnimal : public virtual Animal 
{
public:
	virtual void flap() = 0;
	void eat() override {}
};

class Bat : public Mammal, public WingedAnimal
{
public:
	void breathe() override {}
	void flap() override {}
	void eat() override {}
};

int main()
{
	Bat b{};
	b.eat();
	Animal& a = b;
}