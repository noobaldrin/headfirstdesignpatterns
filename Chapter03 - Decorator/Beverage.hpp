#ifndef BEVERAGE_HPP
#define BEVERAGE_HPP

#include <iostream>

class Beverage {
public:
    Beverage();
    virtual ~Beverage();
    virtual std::string getDescription() const = 0;
    virtual double cost() = 0;

protected:
    std::string m_description;
};

class HouseBlend : public Beverage {
public:
    HouseBlend();
    ~HouseBlend() override;
    std::string getDescription() const override;
    double cost() override;
};

class DarkRoast : public Beverage {
public:
    DarkRoast();
    ~DarkRoast() override;
    std::string getDescription() const override;
    double cost() override;
};

class Espresso : public Beverage {
public:
    Espresso();
    ~Espresso() override;
    std::string getDescription() const override;
    double cost() override;
};

class Decaf : public Beverage {
public:
    Decaf();
    ~Decaf() override;
    std::string getDescription() const override;
    double cost() override;
};

#endif // BEVERAGE_HPP
