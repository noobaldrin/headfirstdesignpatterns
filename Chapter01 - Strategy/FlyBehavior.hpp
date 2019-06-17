#ifndef FLYBEHAVIOR_HPP
#define FLYBEHAVIOR_HPP

class FlyBehavior
{
public:
	FlyBehavior();
	virtual ~FlyBehavior();
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
	void fly() override;
};


class FlyNoWay: public FlyBehavior
{
public:
	void fly() override;
};


class FlyRocketPowered : public FlyBehavior
{
public:
	void fly() override;
};



#endif // FLYBEHAVIOR_HPP
