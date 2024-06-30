#include <iostream>

struct AirBag{};
struct EUSafetyStandartAirBag:AirBag{};
struct USSSafetyStandartAirBag:AirBag{};

struct TurnSignal{};
struct YellowTurnSignal:TurnSignal{};
struct RedTurnSignal:TurnSignal{};

class CarPartsFactory 
{
public:
	virtual AirBag* createAirBag()const = 0;
	virtual TurnSignal* createTurnSignal()const = 0;

	virtual ~CarPartsFactory() = default;
};

class EuropeanCarPartsFactory :public CarPartsFactory
{
public:
	AirBag* createAirBag()const override
	{
		return new EUSafetyStandartAirBag();
	}
	TurnSignal* createTurnSignal()const override
	{
		return new YellowTurnSignal();
	}
};

class USCarPartsFactory : public CarPartsFactory {
public:
	AirBag* createAirBag() const override {
		return new USSSafetyStandartAirBag();
	}
	TurnSignal* createTurnSignal() const override {
		return new RedTurnSignal();
	}
};

CarPartsFactory* factoryOfFactories(bool isEU)
{
	if (isEU)
		return new EuropeanCarPartsFactory();
	else 
		return new USCarPartsFactory();
}

void createCar(CarPartsFactory* partsFactory)
{
	AirBag* airbag = partsFactory->createAirBag();
	TurnSignal* turnsignal = partsFactory->createTurnSignal();
}

int main() 
{
	CarPartsFactory* factory = factoryOfFactories(true);
	createCar(factory);

	delete factory;
}