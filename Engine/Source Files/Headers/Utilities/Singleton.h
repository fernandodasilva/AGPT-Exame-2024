#pragma once

template<typename T>
class Singleton
{
protected:
	Singleton() {};
	Singleton(const T&);
	Singleton& operator=(const T&);


public:
	static T& getInstance()
	{
		static T instance;
		return instance;
	}
};