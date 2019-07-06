#ifndef DUCK_GUI_HPP
#define DUCK_GUI_HPP

#include <string>
#include <vector>
#include "Duck.hpp"
#include "QuackBehavior.hpp"
#include "FlyBehavior.hpp"

class G_Duck : public Duck
{
public:
    G_Duck(const std::string name) : m_name(name) {}
    void display() override {}
    std::string getName() const { return m_name; }
    QuackBehavior* getQuackBehaviorInstance() { return quackBehavior; }
    FlyBehavior* getFlyBehaviorInstance() { return flyBehavior; }

private:
    std::string m_name;
};

class G_MallardDuck : public G_Duck
{
public:
    G_MallardDuck(const std::string name) : G_Duck(name)
    {
	m_mallardDuck = new MallardDuck();
    }
    MallardDuck* getDuckInstance() { return m_mallardDuck; }

private:
    MallardDuck* m_mallardDuck;
};

class G_RedheadDuck : public G_Duck
{
public:
    G_RedheadDuck(const std::string name) : G_Duck(name)
    {
	m_redheadDuck = new RedheadDuck();
    }

    RedheadDuck* getDuckInstance() { return m_redheadDuck; }

private:
    RedheadDuck* m_redheadDuck;
};

class G_RubberDuck : public G_Duck
{
public:
    G_RubberDuck(const std::string name) : G_Duck(name)
    {
	m_rubberDuck = new RubberDuck();
    }
    RubberDuck* getDuckInstance() { return m_rubberDuck; }

private:
    RubberDuck* m_rubberDuck;
};

class G_DecoyDuck : public G_Duck
{
public:
    G_DecoyDuck(const std::string name) : G_Duck(name)
    {
	m_decoyDuck = new DecoyDuck();
    }

    DecoyDuck* getDuckInstance() { return m_decoyDuck; }

private:
    DecoyDuck* m_decoyDuck;
};

class G_DuckCreator
{
public:
    static G_Duck* createDuck(const std::string& s_duck,
			      std::vector<QuackBehavior*> quack,
			      std::vector<FlyBehavior*> fly)
    {
	if (!s_duck.compare("Mallard Duck")) {
	    G_MallardDuck* g_mallardDuck = new G_MallardDuck(s_duck);
	    g_mallardDuck->setQuackBehavior(quack.at(0));
	    g_mallardDuck->setFlyBehavior(fly.at(0));

	    return g_mallardDuck;

	} else if (!s_duck.compare("Red Head Duck")) {
	    G_RedheadDuck* g_redheadDuck = new G_RedheadDuck(s_duck);
	    g_redheadDuck->setQuackBehavior(quack.at(0));
	    g_redheadDuck->setFlyBehavior(fly.at(0));

	    return g_redheadDuck;

	} else if (!s_duck.compare("Rubber Duck")) {
	    G_RubberDuck* g_rubberDuck = new G_RubberDuck(s_duck);
	    g_rubberDuck->setQuackBehavior(quack.at(2));
	    g_rubberDuck->setFlyBehavior(fly.at(1));

	    return g_rubberDuck;

	} else if (!s_duck.compare("Decoy Duck")) {
	    G_DecoyDuck* g_decoyDuck = new G_DecoyDuck(s_duck);
	    g_decoyDuck->setQuackBehavior(quack.at(1));
	    g_decoyDuck->setFlyBehavior(fly.at(2));

	    return g_decoyDuck;

	} else {
	    G_MallardDuck* g_mallardDuck = new G_MallardDuck(s_duck);
	    g_mallardDuck->setQuackBehavior(quack.at(0));
	    g_mallardDuck->setFlyBehavior(fly.at(0));

	    return g_mallardDuck;
	}
    }
};

#endif    // DUCK_GUI_HPP
