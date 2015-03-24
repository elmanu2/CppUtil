#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#ifdef CPPUTILBUILDDLL
#define CPPUTILEXPORT  __declspec( dllexport ) 
#else
#define CPPUTILEXPORT  __declspec( dllimport ) 
#endif

#include <string>

class CPPUTILEXPORT environment
{
public:
    environment();

    virtual ~environment();

    static std::string getWorkingDir();

    static int getProcessusId();

    static void setPath(std::string newPath_);

    static void appendPath(std::string appendPath_);

    static std::string getPath();

    static std::string getEnv(std::string env_);

    static void setEnv(std::string env_);

    static std::string getUserProfile();

    static std::string getUserTempDir();

    static std::string getSystemTempDir();

    static std::string getOS();

    static std::string getOSVersion();

    static std::string getNumberOfProcessor();

    static std::string getWindowsDir();


};

#endif // ENVIRONMENT_H
