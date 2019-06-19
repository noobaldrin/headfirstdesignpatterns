#include <iostream>
#include <list>

#include "Observer.hpp"
#include "Subject.hpp"

Subject::Subject()
{
}
Subject::~Subject() {}

WeatherData::WeatherData(float& t, float& h, float& p)
    : m_temperature(t)
    , m_humidity(h)
    , m_pressure(p)
{
    notifyObservers();
}

void WeatherData::notifyObservers()
{
    for (Observer* obs : observers)
        obs->update(m_temperature, m_humidity, m_pressure);
}

void WeatherData::registerObserver(Observer& o)
{
    observers.push_back(&o);
    o.update(m_temperature, m_humidity, m_pressure);
}

void WeatherData::removeObserver(Observer& o)
{
    observers.remove(&o);
}

float WeatherData::getTemperature() const
{
    return m_temperature;
}

float WeatherData::getHumidity() const
{
    return m_humidity;
}

float WeatherData::getPressure() const
{
    return m_pressure;
}

void WeatherData::setMeasurements(float& temperature, float& humidity, float& pressure)
{
    m_temperature = temperature;
    m_humidity = humidity;
    m_pressure = pressure;
    this->measurementsChanged();
}

void WeatherData::measurementsChanged()
{
    notifyObservers();
}
