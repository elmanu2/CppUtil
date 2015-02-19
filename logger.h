#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <map>

class Logger
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
    Logger();

    virtual ~Logger();

    void setLevel(ELevel level_);

    ELevel getLevel()const;

    void log(ELevel level_, std::string msg_) const;

    void logDebug(std::string msg_)const;

    void logInfo(std::string msg_)const;

    void logWarning(std::string msg_)const;

    void logError(std::string msg_)const;

    static void test();

protected :

    static std::map<ELevel, std::string> _logLevelDict;

    bool checkLogLevel(ELevel level_)const;

    ELevel _level;

};

#endif // LOGGER_H
