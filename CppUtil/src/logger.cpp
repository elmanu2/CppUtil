#include "logger.h"
#include "date.h"
#include "fileUtil.h"
#include <iostream>
#include <fstream>
#include <cassert>

std::map<Logger::ELevel, std::string> Logger::_logLevelDict;
Logger* Logger::_instance = NULL;



#include <windows.h>

// Remember how things were when we started
CONSOLE_SCREEN_BUFFER_INFO csbi;

void changeConsoleColor(unsigned short color)
{
    //    bit 0 - foreground blue
    //    bit 1 - foreground green
    //    bit 2 - foreground red
    //    bit 3 - foreground intensity

    //    bit 4 - background blue
    //    bit 5 - background green
    //    bit 6 - background red
    //    bit 7 - background intensity
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hstdout, color);
}

void changeConsoleColorRed()
{
    changeConsoleColor(0x0C);
}
void changeConsoleColorYellow()
{
    changeConsoleColor(0x0E);
}

void recordConsoleDefault()
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    GetConsoleScreenBufferInfo( hstdout, &csbi );
}

void restoreConsoleColor()
{
    HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
    // Keep users happy
    SetConsoleTextAttribute( hstdout, csbi.wAttributes );
}

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

    _logFilenamePrefix = "";
    _logDirectory = "";

    recordConsoleDefault();
}

Logger::~Logger()
{
    _logFile.close();
}

void Logger::addPrefixLogFile(std::string prefix_)
{
    _logFilenamePrefix = prefix_;
}

void Logger::setLogDirectory(std::string logDirectory_)
{
    _logDirectory = logDirectory_;
    FileUtil::createDirectory(_logDirectory);
}

void Logger::createLogFile()
{
    std::string logDirectory = _logDirectory + "/log";
    FileUtil::createDirectory(logDirectory);
    std::string filename = logDirectory + "/" + _logFilenamePrefix + Date::getNow().toLog() + "-log.txt";
    //If it was already created, then we close it to reopen a new one
    if(_logFile.is_open())
    {
        _logFile.close();
    }
    _logFile.open(filename.c_str());
    if(!_logFile.is_open())
    {
        LOG_ERROR("Log file creation failure " + filename);
    }
    else
    {
        LOG_INFO("Log file path " + filename);
    }
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
    restoreConsoleColor();
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
    changeConsoleColorYellow();
    log(eLevelWarning, msg_);
}

void Logger::logError(std::string msg_)
{
    changeConsoleColorRed();
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

