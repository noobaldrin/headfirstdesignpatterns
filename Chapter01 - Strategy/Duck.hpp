#ifndef DUCK_HPP
#define DUCK_HPP

class FlyBehavior;
class QuackBehavior;

class Duck
{
public:
	Duck();
	virtual ~Duck();
	void performFly();
	void performQuack();
	void swim();
	virtual void display() = 0;
	void setFlyBehavior(FlyBehavior *fb);
	void setQuackBehavior(QuackBehavior *fb);

protected:
	FlyBehavior *flyBehavior;
	QuackBehavior *quackBehavior;

};

class MallardDuck : public Duck
{
public:
	MallardDuck();
	void display() override;
};

#endif // DUCK_HPP
