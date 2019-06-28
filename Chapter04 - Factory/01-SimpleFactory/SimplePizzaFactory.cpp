#include "SimplePizzaFactory.hpp"
#include "Pizza.hpp"

Pizza* SimplePizzaFactory::createPizza(std::string type)
{
    Pizza* pizza = nullptr;

    if (!type.compare("cheese"))
	pizza = new CheesePizza();
    else if (!type.compare("pepperoni"))
	pizza = new PepperoniPizza();
    else if (!type.compare("clam"))
	pizza = new ClamPizza();
    else if (!type.compare("veggie"))
	pizza = new VeggiePizza();

    return pizza;
}
