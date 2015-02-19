#include "date.h"
#include <ctime>
#include <cmath>
#include <cassert>
#include <iostream>


Date::Date( unsigned int year_,
            unsigned int month_,
             unsigned int monthDay_,
             unsigned int hour_,
             unsigned int minute_,
             unsigned int second_)
{
    _year       = year_;
    _month      = month_;
    _monthDay   = monthDay_;
    _hour       = hour_;
    _minute     = minute_;
    _second     = second_;
}

Date::Date(const Date& source)
{
    _year       = source._year;
    _month      = source._month;
    _monthDay   = source._monthDay;
    _hour       = source._hour;
    _minute     = source._minute;
    _second     = source._second;
}

Date::Date(time_t date_)
{
    struct tm time;
    time = *gmtime(&date_);
    _year = 1900 + time.tm_year;
    _month = 1 + time.tm_mon;
    _monthDay = time.tm_mday;
    _hour = time.tm_hour;
    _minute = time.tm_min;
    _second = time.tm_sec;
}


Date::~Date()
{

}

bool Date::operator== (const Date &autre_) const {
  return
      _year == autre_._year &&
      _month == autre_._month &&
      _monthDay == autre_._monthDay &&
      _hour == autre_._hour &&
      _minute == autre_._minute &&
      _second == autre_._second;
}

Date Date::getNow()
{
    time_t rawTime;
    time(&rawTime);
    return Date(rawTime);
}

std::string Date::toStr() const
{
    char buffer[128];
    std::string str = "e";
    sprintf(buffer, "[y:%d+][m:%d][d:%d]"
                    "[h:%d][m:%d][s:%d]",
            _year,_month, _monthDay, _hour, _minute, _second);

    return std::string(buffer);
}

std::string Date::toLog() const
{
    char date[64];
    sprintf(date, "%04d-%02d-%02dT%02d:%02d:%02d",
            _year,_month, _monthDay, _hour, _minute, _second);
    return std::string(date);
}

time_t Date::toTimeT()const
{
    struct tm date;
    //tm_year : donner le nombre d annee depuis 1900
    date.tm_year  = _year - 1900;
    //tm_mon :mois de 0-11
    date.tm_mon   = _month - 1;
    //tm_day : jour de 1-31
    date.tm_mday  = _monthDay;
    //tm_hour : heure 0-23
    date.tm_hour  = _hour;
    //tm_min : minute 0-59
    date.tm_min   = _minute;
    //tm_sec : second 0-59
    date.tm_sec   = _second;
    //tm_isdst : flag sur horaire hiver/ete pour lequel nou n avons pas connaissance
    //dans ce cas la on le fixe a 1 pour que les calculs de difference de date
    //se basent sur le meme systeme
    date.tm_isdst = -1;
    return mktime(&date);
}

double Date::calculerDiff(const Date &date1_, const Date &date2_)
{
    //Transformation des dates vers des format STL
    time_t date1 = date1_.toTimeT();
    //Transformation des dates vers des format STL
    time_t date2 = date2_.toTimeT();

    //Retourne la difference en seconde
    return fabs(difftime(date1,date2));
}

#define EPSILON 10e-6

void Date::test()
{
    //1 janvier 2015,h:0,m:0,s:0
    Date date1(2015,1,1,0,0,0);
    //1 janvier 2015,h:0,m:0,s:1
    Date date2(2015,1,1,0,0,1);
    //1 janvier 2015,h:0,m:1,s:0
    Date date3(2015,1,1,0,1,0);
    //1 janvier 2015,h:1,m:0,s:0
    Date date4(2015,1,1,1,0,0);

    assert((fabs(Date::calculerDiff(date1, date2)) - 1.0)  < EPSILON);
    assert((fabs(Date::calculerDiff(date1, date3)) - 60.0)  < EPSILON);
    assert((fabs(Date::calculerDiff(date1, date4)) - 3600.0)  < EPSILON);
    assert(date4.toLog() == "2015-01-01T01:00:00");

    Date date5(2015,1,1,1,1,1);
    Date date6 = date5;
    assert(date5 == date6);

    std::cout<<"Unit tests on Date class passed sucessfully"<<std::endl;
}



