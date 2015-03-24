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

    std::string msg = "Working directory : " + environment::getWorkingDir();
    LOG_DEBUG(msg);

    msg = "Process ID : " + Helper::toString(environment::getProcessusId());
    LOG_DEBUG(msg);

    environment::setEnv("TEST=toto");

    environment::appendPath("C:/Windows");
    LOG_DEBUG("PATH : " + environment::getPath());

    LOG_DEBUG("User profile : "  + environment::getUserProfile());

    LOG_DEBUG("temporary directory : "  + environment::getUserTempDir());

    LOG_DEBUG("OS : "  + environment::getOS());

    LOG_DEBUG("OS version : "  + environment::getOSVersion());

    LOG_DEBUG("Number of processors : "  + environment::getNumberOfProcessor());

    LOG_DEBUG("Windows directory : "  + environment::getWindowsDir());

    int a = 10;
    int b = 1;
    fprintf(stdout, "%02d",a);
    fprintf(stdout, "%02d",b);

	system("PAUSE");
    return 0;
}

