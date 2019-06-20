#include "Decorator.hpp"

Decorator::Decorator(Beverage& bev)
{
    m_bev = &bev;
}

std::string Decorator::getDescription() const
{
    return m_bev->getDescription() + ", " + m_description;
}

Milk::Milk(Beverage& bev)
    : Decorator(bev)
{
    m_description = "Milk";
}
Milk::~Milk() {}

double Milk::cost()
{
    return m_bev->cost() + 0.1;
}

Mocha::Mocha(Beverage& bev)
    : Decorator(bev)
{
    m_description = "Mocha";
}
Mocha::~Mocha() {}

double Mocha::cost()
{
    return m_bev->cost() + 0.2;
}

Soy::Soy(Beverage& bev)
    : Decorator(bev)
{
    m_description = "Soy";
}
Soy::~Soy() {}

double Soy::cost()
{
    return m_bev->cost() + 0.3;
}

Whip::Whip(Beverage& bev)
    : Decorator(bev)
{
    m_description = "Whip";
}
Whip::~Whip() {}

double Whip::cost()
{
    return m_bev->cost() + 0.4;
}
