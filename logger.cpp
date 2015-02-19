#include "logger.h"
#include "date.h"
#include <iostream>
#include <cassert>


std::map<Logger::ELevel, std::string> Logger::_logLevelDict;

Logger::Logger()
{
    _logLevelDict[eLevelDebug] = "DEBUG";
    _logLevelDict[eLevelInfo] = "INFO";
    _logLevelDict[eLevelWarning] = "WARNING";
    _logLevelDict[eLevelError] = "ERROR";
}

Logger::~Logger()
{

}

void Logger::setLevel(ELevel level_)
{
    _level = level_;
}

Logger::ELevel Logger::getLevel()const
{
    return _level;
}

bool Logger::checkLogLevel(ELevel level_) const
{
    if(level_ >= _level)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Logger::log(ELevel level_, std::string msg_) const
{
    if(checkLogLevel(level_))
    {
        std::cout<<Date::getNow().toLog()
                 <<"["<<_logLevelDict[level_]<<"]:"
                 <<msg_<<std::endl;
    }
}

void Logger::logDebug(std::string msg_)const
{
    log(eLevelDebug, msg_);
}

void Logger::logInfo(std::string msg_)const
{
    log(eLevelInfo, msg_);
}

void Logger::logWarning(std::string msg_)const
{
    log(eLevelDebug, msg_);
}

void Logger::logError(std::string msg_)const
{
    log(eLevelDebug, msg_);
}

void Logger::test()
{
    Logger logger;
    logger.setLevel(eLevelDebug);
    assert(logger.checkLogLevel(eLevelDebug));
    assert(logger.checkLogLevel(eLevelInfo));
    assert(logger.checkLogLevel(eLevelWarning));
    assert(logger.checkLogLevel(eLevelError));

    logger.setLevel(eLevelInfo);
    assert(!logger.checkLogLevel(eLevelDebug));
    assert(logger.checkLogLevel(eLevelInfo));
    assert(logger.checkLogLevel(eLevelWarning));
    assert(logger.checkLogLevel(eLevelError));

    logger.setLevel(eLevelWarning);
    assert(!logger.checkLogLevel(eLevelDebug));
    assert(!logger.checkLogLevel(eLevelInfo));
    assert(logger.checkLogLevel(eLevelWarning));
    assert(logger.checkLogLevel(eLevelError));

    logger.setLevel(eLevelError);
    assert(!logger.checkLogLevel(eLevelDebug));
    assert(!logger.checkLogLevel(eLevelInfo));
    assert(!logger.checkLogLevel(eLevelWarning));
    assert(logger.checkLogLevel(eLevelError));

    logger.setLevel(eLevelNoError);
    assert(!logger.checkLogLevel(eLevelDebug));
    assert(!logger.checkLogLevel(eLevelInfo));
    assert(!logger.checkLogLevel(eLevelWarning));
    assert(!logger.checkLogLevel(eLevelError));

    std::cout<<"Unit tests on logger class passed successfully"<<std::endl;
}

