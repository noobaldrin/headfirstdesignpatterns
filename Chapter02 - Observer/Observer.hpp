#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

class Observer {
public:
    Observer(const std::string& email);
    virtual ~Observer();

    void update(float& temp, float& humidity, float& pressure);

    bool operator==(Observer& o);

    std::string getEmail() const;

protected:
    std::string m_email;
    float m_temp;
    float m_humidity;
    float m_pressure;
};

#endif // OBSERVER_HPP
