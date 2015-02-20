#include "logger.h"
#include "date.h"
#include <iostream>
#include <fstream>
#include <cassert>


std::map<Logger::ELevel, std::string> Logger::_logLevelDict;
Logger* Logger::_instance = NULL;

Logger* Logger::getInstance()
{
    if(_instance == NULL)
    {
        _instance = new Logger();
    }
    return _instance;
}

Logger::Logger()
{
    _logLevelDict[eLevelDebug]      = "DEBUG  ";
    _logLevelDict[eLevelInfo]       = "INFO   ";
    _logLevelDict[eLevelWarning]    = "WARNING";
    _logLevelDict[eLevelError]      = "ERROR  ";

    std::string filename = Date::getNow().toLog() + "-log.txt";
    _logFile.open(filename.c_str());
}

Logger::~Logger()
{
    _logFile.close();
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

void Logger::log(ELevel level_, std::string msg_)
{
    if(checkLogLevel(level_))
    {
        std::string msg =   "["+Date::getNow().toLog()+"]"+
                            "["+_logLevelDict[level_]+"] - "+
                            msg_;
        std::cout<<msg<<std::endl;
        _logFile<<msg<<std::endl;

    }
}

void Logger::logDebug(std::string msg_)
{
    log(eLevelDebug, msg_);
}

void Logger::logInfo(std::string msg_)
{
    log(eLevelInfo, msg_);
}

void Logger::logWarning(std::string msg_)
{
    log(eLevelWarning, msg_);
}

void Logger::logError(std::string msg_)
{
    log(eLevelError, msg_);
}

void Logger::test()
{
    Logger* logger = Logger::getInstance();
    logger->setLevel(eLevelDebug);
    assert(logger->checkLogLevel(eLevelDebug));
    assert(logger->checkLogLevel(eLevelInfo));
    assert(logger->checkLogLevel(eLevelWarning));
    assert(logger->checkLogLevel(eLevelError));

    LOG_DEBUG("TEST LOG DEBUG");
    LOG_INFO("TEST LOG INFO");
    LOG_WARNING("TEST LOG WARNING");
    LOG_ERROR("TEST LOG ERROR");

    logger->setLevel(eLevelInfo);
    assert(!logger->checkLogLevel(eLevelDebug));
    assert(logger->checkLogLevel(eLevelInfo));
    assert(logger->checkLogLevel(eLevelWarning));
    assert(logger->checkLogLevel(eLevelError));

    logger->setLevel(eLevelWarning);
    assert(!logger->checkLogLevel(eLevelDebug));
    assert(!logger->checkLogLevel(eLevelInfo));
    assert(logger->checkLogLevel(eLevelWarning));
    assert(logger->checkLogLevel(eLevelError));

    logger->setLevel(eLevelError);
    assert(!logger->checkLogLevel(eLevelDebug));
    assert(!logger->checkLogLevel(eLevelInfo));
    assert(!logger->checkLogLevel(eLevelWarning));
    assert(logger->checkLogLevel(eLevelError));

    logger->setLevel(eLevelNoError);
    assert(!logger->checkLogLevel(eLevelDebug));
    assert(!logger->checkLogLevel(eLevelInfo));
    assert(!logger->checkLogLevel(eLevelWarning));
    assert(!logger->checkLogLevel(eLevelError));

    logger->setLevel(eLevelDebug);
    LOG_INFO("Unit tests on logger class passed successfully");
}

