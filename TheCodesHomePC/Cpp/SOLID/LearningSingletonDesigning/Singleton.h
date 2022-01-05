#pragma once
class Singleton
{
public: 
	static Singleton* Instance();
	int getValue();
	void setValue(int);

private:
	static Singleton* s_pInstance;
	int value;
	Singleton();
};

