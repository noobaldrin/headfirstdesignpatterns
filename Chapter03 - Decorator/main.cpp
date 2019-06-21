#include <iostream>

#include "Beverage.hpp"
#include "Decorator.hpp"

int main()
{

    // Declare the base Beverage
    Beverage* decaf;
    decaf = new Decaf();

    // Decorate the base beverage with different condiments
    decaf = new Milk(*decaf);
    decaf = new Mocha(*decaf);
    decaf = new Soy(*decaf);
    decaf = new Milk(*decaf);

    // Display the condiments added and total cost
    std::cout << "Total Cost of: " << decaf->getDescription()
              << " is " << decaf->cost() << std::endl;
    return 0;
}
