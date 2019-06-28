#ifndef PIZZA_STORE_HPP
#define PIZZA_STORE_HPP

#include "SimplePizzaFactory.hpp"

class PizzaStore
{
public:
    PizzaStore(SimplePizzaFactory &factory);
    Pizza *orderPizza(const std::string &type);

private:
    SimplePizzaFactory m_factory;
};

#endif
