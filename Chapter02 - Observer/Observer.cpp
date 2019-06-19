#include "Observer.hpp"
#include <string>

Observer::Observer(const std::string& email)
    : m_email(email)
{
}
Observer::~Observer() {}

void Observer::update(float& temp, float& humidity, float& pressure)
{
    m_temp = temp;
    m_humidity = humidity;
    m_pressure = pressure;
}

bool Observer::operator==(Observer& o)
{
    return !this->getEmail().compare(o.getEmail());
}

std::string Observer::getEmail() const
{
    return m_email;
}
