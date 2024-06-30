#include <iostream>

class Base
{
public:
	virtual ~Base() = default;
};

class Der1:public Base{};
class Der2:public Base{};

//FM
class BaseFactory
{
public:
	virtual Base* create()const = 0;
	virtual ~BaseFactory() = default;
};

class Der1Factory :public BaseFactory
{
public:
	Base* create()const override
	{
		return new Der1();
	}
};

class Der2Factory : public BaseFactory {
public:
	Base* create() const override {
		return new Der2();
	}
};

//Factory

BaseFactory* factOfFactories(bool useDer1)
{
	if (useDer1)
	{
		return new Der1Factory();
	}
	else return new Der2Factory();
}

void runApp(BaseFactory* fact)
{

}

int main()
{
	BaseFactory* fact = factOfFactories(true);
	runApp(fact);
	delete fact;
}