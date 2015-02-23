#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>

class environment
{
public:
    environment();

    virtual ~environment();

    static std::string getWorkingDir();

    static int getProcessusId();



};

#endif // ENVIRONMENT_H
