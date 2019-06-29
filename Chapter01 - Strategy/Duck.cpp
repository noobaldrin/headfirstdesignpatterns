#include <iostream>

#include "Duck.hpp"
#include "FlyBehavior.hpp"
#include "QuackBehavior.hpp"

Duck::Duck() {}
Duck::~Duck() {}

void Duck::performFly()
{
    flyBehavior->fly();
}

void Duck::performQuack()
{
    quackBehavior->quack();
}

void Duck::swim()
{
    std::cout << "All ducks float, even decoys!" << std::endl;
}

void Duck::setFlyBehavior(FlyBehavior* fb)
{
    flyBehavior = fb;
}

void Duck::setQuackBehavior(QuackBehavior* qb)
{
    quackBehavior = qb;
}

MallardDuck::MallardDuck()
{
    quackBehavior = new Quack();
    flyBehavior = new FlyWithWings();
}

void MallardDuck::display()
{
    std::cout << "I'm a real Mallard duck" << std::endl;
}

RedheadDuck::RedheadDuck()
{
    quackBehavior = new Quack();
    flyBehavior = new FlyWithWings();
}

void RedheadDuck::display()
{
    std::cout << "I'm a real Red head duck" << std::endl;
}

RubberDuck::RubberDuck()
{
    quackBehavior = new Quack();
    flyBehavior = new FlyWithWings();
}

void RubberDuck::display()
{
    std::cout << "I'm a Rubber duck and I'm a toy" << std::endl;
}

DecoyDuck::DecoyDuck()
{
    quackBehavior = new Quack();
    flyBehavior = new FlyWithWings();
}

void DecoyDuck::display()
{
    std::cout << "I'm not a real duck" << std::endl;
}

