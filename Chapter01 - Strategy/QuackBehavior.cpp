#include <iostream>

#include "QuackBehavior.hpp"

QuackBehavior::QuackBehavior() {}
QuackBehavior::~QuackBehavior() {}

void Quack::quack()
{
    std::cout << "Quack" << std::endl;
}
void MuteQuack::quack()
{
    std::cout << "<< Silence >>" << std::endl;
}
void Squeak::quack()
{
    std::cout << "Squeak" << std::endl;
}
