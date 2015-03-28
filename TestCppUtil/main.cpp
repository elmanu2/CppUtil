#include <iostream>
#include "date.h"
#include "logger.h"
#include "environment.h"
#include "helper.h"
#include "stdlib.h"
#include "point2d.h"

using namespace std;

int main()
{
    Logger::getInstance()->setLevel(Logger::eLevelDebug);
    
    Logger::test();
    Date::test();
    Helper::test();
    Point2D::test();
	environment::logEnvironment();
	system("PAUSE");
    return 0;
}

