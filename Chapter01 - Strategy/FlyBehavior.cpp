#include <iostream>

#include "FlyBehavior.hpp"

FlyBehavior::FlyBehavior() {}
FlyBehavior::~FlyBehavior() {}

void FlyWithWings::fly()
{
    std::cout << "I'm flying!!" << std::endl;
}
void FlyNoWay::fly()
{
    std::cout << "I can't fly" << std::endl;
}
void FlyRocketPowered::fly()
{
    std::cout << "I'm flying with a rocket" << std::endl;
}
