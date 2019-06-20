#include <iostream>

#include "Beverage.hpp"
#include "Decorator.hpp"

int main()
{

    // Declare the base Beverage
    Beverage* beverage;
    beverage = new Decaf();

    // Decorate the base beverage by wrapping with condiment
    Milk* milk = new Milk(*beverage);

    // Decorate  the wrapped beverage with another condiment
    Mocha* mocha = new Mocha(*milk);
    Soy* soy = new Soy(*mocha);
    Milk* anothermilk = new Milk(*soy);

    // Show the condiment names and total cost
    std::cout << "Total Cost of: " << anothermilk->getDescription()
              << " is " << anothermilk->cost() << std::endl;
    return 0;
}
