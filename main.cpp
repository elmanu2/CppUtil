#include <iostream>
#include "testvector.h"
#include "date.h"
#include "logger.h"
#include "environment.h"
#include "helper.h"
#include "stdlib.h"

using namespace std;



int main()
{
    TestVector v;
    Logger::getInstance()->setLevel(Logger::eLevelDebug);
    LOG_DEBUG("now :");

    Date::test();

    Logger::test();

    Helper::test();

    std::string msg = "Working directory : " + environment::getWorkingDir();
    LOG_DEBUG(msg);

    msg = "Process ID : " + Helper::toString(environment::getProcessusId());
    LOG_DEBUG(msg);


    LOG_DEBUG("Hello World!");

    unsigned short val = 0b00000001;
    LOG_DEBUG(Helper::toString(val));
    val = 0b11111111;
    LOG_DEBUG(Helper::toStringBit(val));

    unsigned char byte = 0b11111111;
    LOG_DEBUG(Helper::toStringBit(byte));

    return 0;
}

