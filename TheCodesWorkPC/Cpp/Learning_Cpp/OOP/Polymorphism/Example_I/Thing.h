#pragma once
#include <iostream>

class Thing
{
public:
	virtual void speak() = 0;
	virtual void run() = 0;
	virtual void die() = 0;
};

