#include "Pizza.hpp"
#include "PizzaStore.hpp"

PizzaStore::PizzaStore(SimplePizzaFactory &factory)
{
    m_factory = factory;
}

Pizza *PizzaStore::orderPizza(const std::string &type)
{
    Pizza *pizza = nullptr;
    pizza = m_factory.createPizza(type);

    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
}

