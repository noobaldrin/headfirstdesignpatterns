#include <iostream>

#include "DisplayElement.hpp"

DisplayElement::DisplayElement() {}
DisplayElement::~DisplayElement() {}

CurrentConditionsDisplay::CurrentConditionsDisplay(std::string email)
    : Observer(email)
{
}
CurrentConditionsDisplay::~CurrentConditionsDisplay() {}

ForecastDisplay::ForecastDisplay(std::string email)
    : Observer(email)
{
}
ForecastDisplay::~ForecastDisplay() {}

StatisticsDisplay::StatisticsDisplay(std::string email)
    : Observer(email)
{
}
StatisticsDisplay::~StatisticsDisplay() {}

ThirdPartyDisplay::ThirdPartyDisplay(std::string email)
    : Observer(email)
{
}
ThirdPartyDisplay::~ThirdPartyDisplay() {}

void CurrentConditionsDisplay::display()
{
    std::cout << "CurrentConditionDisplay: " << m_email
              << "\n"
              << "Temp: " << m_temp << "\n"
              << "Humidity: " << m_humidity << "\n"
              << "Pressure: " << m_pressure << std::endl;
}

void ForecastDisplay::display()
{
    std::cout << "ForecastDisplay: " << m_email
              << "\n"
              << "Temp: " << m_temp << "\n"
              << "Humidity: " << m_humidity << "\n"
              << "Pressure: " << m_pressure << std::endl;
}

void StatisticsDisplay::display()
{
    std::cout << "StatisticsDisplay: " << m_email
              << "\n"
              << "Temp: " << m_temp << "\n"
              << "Humidity: " << m_humidity << "\n"
              << "Pressure: " << m_pressure << std::endl;
}

void ThirdPartyDisplay::display()
{
    std::cout << "ThirdPartyDisplay: " << m_email
              << "\n"
              << "Temp: " << m_temp << "\n"
              << "Humidity: " << m_humidity << "\n"
              << "Pressure: " << m_pressure << std::endl;
}
