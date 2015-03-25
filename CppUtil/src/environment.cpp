#include "environment.h"
#include "logger.h"
#include "helper.h"

#include <stdio.h>
#include <stdlib.h>

#include "direct.h"
#include <process.h>

environment::environment()
{

}

environment::~environment()
{

}

std::string environment::getWorkingDir()
{
    char* buffer;
    // Get the current working directory:
    buffer = _getcwd( NULL, 0 );
    return std::string(buffer);
}

int environment::getProcessusId()
{
    return _getpid();
}

std::string environment::getPath()
{
    return getEnv("PATH");
}

std::string environment::getEnv(std::string env_)
{
    return getenv(env_.c_str());
}

void environment::setPath(std::string newPath_)
{
    setEnv("PATH=" + newPath_);
}

void environment::appendPath(std::string path_)
{
    setEnv("PATH=" + getPath() + ";" + path_);
}

void environment::setEnv(std::string env_)
{
    putenv(env_.c_str());
}

std::string environment::getUserProfile()
{
    return getEnv("USERPROFILE");
}

std::string environment::getUserTempDir()
{
    return getEnv("TMP");
}

std::string environment::getOS()
{
#ifdef _WIN32
#ifdef _WIN64
    return "Windows 64";
#else
    return "Windows 32";
#endif
#elif __linux
    return "Linux"
#endif
}


std::string environment::getOSVersion()
{
    return getEnv("OS");
}

std::string environment::getNumberOfProcessor()
{
    return getEnv("NUMBER_OF_PROCESSORS");
}

std::string environment::getWindowsDir()
{
    return getEnv("windir");
}

void environment::logEnvironment()
{
    std::string msg = "Working directory : " + environment::getWorkingDir();
    LOG_INFO(msg);

    msg = "Process ID : " + Helper::toString(environment::getProcessusId());
    LOG_INFO(msg);

    environment::setEnv("TEST=toto");

    environment::appendPath("C:/Windows");
    LOG_INFO("PATH : " + environment::getPath());

    LOG_INFO("User profile : "  + environment::getUserProfile());

    LOG_INFO("temporary directory : "  + environment::getUserTempDir());

    LOG_INFO("OS : "  + environment::getOS());

    LOG_INFO("OS version : "  + environment::getOSVersion());

    LOG_INFO("Number of processors : "  + environment::getNumberOfProcessor());

    LOG_INFO("Windows directory : "  + environment::getWindowsDir());
}






