#include "environment.h"
#include <stdio.h>

#include "direct.h"

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





