#ifndef QUACKBEHAVIOR_HPP
#define QUACKBEHAVIOR_HPP

class QuackBehavior
{
public:
	QuackBehavior();
	virtual ~QuackBehavior();

	virtual void quack() = 0;

};

class Quack : public QuackBehavior
{
public:
	void quack() override;
};

class MuteQuack : public QuackBehavior
{
public:
	void quack() override;
};

class Squeak : public QuackBehavior
{
public:
	void quack() override;
};

#endif // QUACKBEHAVIOR_HPP
