#include <iostream>

#include "DisplayElement.hpp"
#include "Subject.hpp"

int main()
{
    float temp = 0.0;
    float hum = 0.0;
    float pre = 0.0;

    // Declare the subject / observable
    WeatherData* weatherData = new WeatherData(temp, hum, pre);

    // Declare 3 observer objects
    CurrentConditionsDisplay obs1("tim@xmail.com");
    ForecastDisplay obs2("jim@xmail.com");
    StatisticsDisplay obs3("mim@xmail.com");

    // Register observers to subject/observable
    weatherData->registerObserver(obs1);
    weatherData->registerObserver(obs2);
    weatherData->registerObserver(obs3);

    // Remove 1 observer from subject
    weatherData->removeObserver(obs2);

    // Display data in observers
    obs1.display();
    obs2.display();
    obs3.display();

    // Update data
    temp = 33.0;
    hum = 44.0;
    pre = 55.0;
    weatherData->setMeasurements(temp, hum, pre);

    std::cout << "+++++++++++++++++++++++" << std::endl;

    // Display updated data
    obs1.display();
    obs2.display();
    obs3.display();

    return 0;
}
