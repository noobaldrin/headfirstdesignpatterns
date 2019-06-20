#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <string>

#include "Beverage.hpp"

// These is the abstract class for the condiments or the "addons"
class Decorator : public Beverage {
public:
    Decorator(Beverage& bev);
    std::string getDescription() const override;

protected:
    Beverage* m_bev;
};

class Milk : public Decorator {
public:
    Milk(Beverage& bev);
    ~Milk() override;
    double cost() override;
};

class Mocha : public Decorator {
public:
    Mocha(Beverage& bev);
    ~Mocha() override;
    double cost() override;
};

class Soy : public Decorator {
public:
    Soy(Beverage& bev);
    ~Soy() override;
    double cost() override;
};

class Whip : public Decorator {
public:
    Whip(Beverage& bev);
    ~Whip() override;
    double cost() override;
};

#endif // DECORATOR_HPP
