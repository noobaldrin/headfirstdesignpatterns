#ifndef PIZZA_HPP
#define PIZZA_HPP

#include <iostream>

class Pizza
{
public:
    virtual void prepare() {}
    virtual void bake() {}
    virtual void cut() {}
    virtual void box() {}
    virtual void print() = 0;
};

class CheesePizza : public Pizza
{
public:
    void print() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class PepperoniPizza : public Pizza
{
    void print() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class ClamPizza : public Pizza
{
    void print() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

class VeggiePizza : public Pizza
{
    void print() override { std::cout << __PRETTY_FUNCTION__ << std::endl; }
};

#endif
