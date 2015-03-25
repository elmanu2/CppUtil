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
    LOG_DEBUG("now :");

    Date::test();

    Logger::test();

    Helper::test();

    Point2D::test();

	environment::logEnvironment();

    int a = 10;
    int b = 1;
    fprintf(stdout, "%02d",a);
    fprintf(stdout, "%02d",b);

	system("PAUSE");
    return 0;
}

