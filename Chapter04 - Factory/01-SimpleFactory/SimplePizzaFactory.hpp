#ifndef SIMPLE_PIZZA_FACTORY_HPP
#define SIMPLE_PIZZA_FACTORY_HPP

#include <string>

class Pizza;

class SimplePizzaFactory
{
public:
    Pizza* createPizza(std::string type);
};

#endif
