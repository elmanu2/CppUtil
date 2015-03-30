#ifndef LOGGER_H
#define LOGGER_H

#ifdef CPPUTILBUILDDLL
#define CPPUTILEXPORT  __declspec( dllexport ) 
#else
#define CPPUTILEXPORT  __declspec( dllimport ) 
#endif

#include <string>
#include <map>
#include <fstream>

#define LOG_DEBUG(message) Logger::getInstance()->logDebug(message)
#define LOG_INFO(message) Logger::getInstance()->logInfo(message)
#define LOG_WARNING(message) Logger::getInstance()->logWarning(message)
#define LOG_ERROR(message) Logger::getInstance()->logError(message)

class CPPUTILEXPORT Logger
{
public:
    enum ELevel
    {
        eLevelDebug,
        eLevelInfo,
        eLevelWarning,
        eLevelError,
        eLevelNoError
    };

public:

    static Logger* getInstance();

    virtual ~Logger();

    void setLevel(ELevel level_);

    ELevel getLevel()const;

    void log(ELevel level_, std::string msg_);

    void logDebug(std::string msg_);

    void logInfo(std::string msg_);

    void logWarning(std::string msg_);

    void logError(std::string msg_);

    static void test();

protected :

    Logger();

    static Logger* _instance;


    bool checkLogLevel(ELevel level_)const;

    ELevel _level;

private :
	#pragma warning(disable:4251)

    std::ofstream _logFile;

    static std::map<ELevel, std::string> _logLevelDict;

	#pragma warning(default:4251)
};

#endif // LOGGER_H
