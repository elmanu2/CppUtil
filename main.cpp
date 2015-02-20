#include <iostream>
#include "testvector.h"
#include "date.h"
#include "logger.h"
using namespace std;

int main()
{
    TestVector v;
    Logger::getInstance()->setLevel(Logger::eLevelDebug);
    LOG_DEBUG("now :");

    Date::test();

    Logger::test();

    LOG_DEBUG("Hello World!");

    return 0;
}

