#include "Beverage.hpp"

Beverage::Beverage()
{
    m_description = "Unkown Beverage";
}
Beverage::~Beverage() {}

HouseBlend::HouseBlend()
{
    m_description = "House Blend";
}
HouseBlend::~HouseBlend() {}

std::string HouseBlend::getDescription() const
{
    return m_description;
}

double HouseBlend::cost()
{
    return 1.0;
}

DarkRoast::DarkRoast()
{
    m_description = "Dark Roast";
}
DarkRoast::~DarkRoast() {}

std::string DarkRoast::getDescription() const
{
    return m_description;
}

double DarkRoast::cost()
{
    return 2.0;
}

Espresso::Espresso()
{
    m_description = "Espresso";
}
Espresso::~Espresso() {}

std::string Espresso::getDescription() const
{
    return m_description;
}

double Espresso::cost()
{
    return 3.0;
}

Decaf::Decaf()
{
    m_description = "Decaf";
}
Decaf::~Decaf() {}

std::string Decaf::getDescription() const
{
    return m_description;
}

double Decaf::cost()
{
    return 4.0;
}
