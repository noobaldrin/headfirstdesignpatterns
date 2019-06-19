#ifndef DISPLAYELEMENT_HPP
#define DISPLAYELEMENT_HPP

#include "Observer.hpp"

class DisplayElement {
public:
    DisplayElement();
    virtual ~DisplayElement();
    virtual void display() = 0;
};

class CurrentConditionsDisplay : public Observer, public DisplayElement {
public:
    CurrentConditionsDisplay(std::string email);
    ~CurrentConditionsDisplay() override;
    void display() override;
};

class ForecastDisplay : public Observer, public DisplayElement {
public:
    ForecastDisplay(std::string email);
    ~ForecastDisplay() override;
    void display() override;
};

class StatisticsDisplay : public Observer, public DisplayElement {
public:
    StatisticsDisplay(std::string email);
    ~StatisticsDisplay() override;
    void display() override;
};

class ThirdPartyDisplay : public Observer, public DisplayElement {
public:
    ThirdPartyDisplay(std::string email);
    ~ThirdPartyDisplay() override;
    void display() override;
};

#endif // DISPLAYELEMENT_HPP
