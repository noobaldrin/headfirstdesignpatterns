#include "PizzaStore.hpp"
#include "Pizza.hpp"
#include "SimplePizzaFactory.hpp"

int main()
{
    SimplePizzaFactory factory;
    PizzaStore store(factory);

    Pizza *pizza = store.orderPizza("cheese");
    pizza->print();

    return 0;
}
