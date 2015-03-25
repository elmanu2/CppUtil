#include "singleton.h"

Singleton* Singleton::getInstance()
{
	return new Singleton();
}

Singleton::Singleton()
{

}

Singleton::~Singleton()
{

}

