#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <list>

class Observer;

// Also known as the Observable class
class Subject {
public:
    Subject();
    virtual ~Subject();
    virtual void registerObserver(Observer& o) = 0;
    virtual void removeObserver(Observer& o) = 0;
    virtual void notifyObservers() = 0;

protected:
    std::list<Observer*> observers;
};

class WeatherData : public Subject {
public:
    WeatherData(float& t, float& h, float& p);
    void notifyObservers() override;
    void registerObserver(Observer& o) override;
    void removeObserver(Observer& o) override;
    float getTemperature() const;
    float getHumidity() const;
    float getPressure() const;
    void setMeasurements(float& temperature, float& humidity, float& pressure);
    void measurementsChanged();

private:
    float m_temperature;
    float m_humidity;
    float m_pressure;
};

#endif // SUBJECT_HPP
