#include <iostream>

#include "Duck.hpp"
#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

int main()
{
    // Initialize mallard duck object
    Duck* mallard = new MallardDuck();

    // Perform functions
    mallard->display();
    mallard->performQuack();
    mallard->performFly();

    // Set Quack and Fly behaviors dynamically (during runtime)
    std::cout << "\n"
              << "Setting quack and fly behaviors...\n"
              << "Press any key to continue..." << std::endl;
    std::cin.get();

    mallard->setFlyBehavior(new FlyRocketPowered());
    mallard->setQuackBehavior(new Squeak());
    mallard->display();
    mallard->performQuack();
    mallard->performFly();

    std::cout << "Press any key to exit." << std::endl;
    std::cin.get();

    return 0;
}
