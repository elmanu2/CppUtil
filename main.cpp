#include <iostream>
#include "testvector.h"
#include "date.h"
#include "logger.h"
using namespace std;

int main()
{
    TestVector v;
    Logger logger;
    logger.setLevel(Logger::eLevelDebug);
    logger.logDebug("now :");

    Date::test();

    Logger::test();

    logger.logDebug("Hello World!");

    return 0;
}

