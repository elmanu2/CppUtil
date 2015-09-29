#ifndef DATE_H
#define DATE_H

#ifdef CPPUTILBUILDDLL
#define CPPUTILEXPORT  __declspec( dllexport ) 
#else
#define CPPUTILEXPORT  __declspec( dllimport ) 
#endif

#include <string>

class CPPUTILEXPORT Date
{
public:
    Date(unsigned int year_,
         unsigned int month_,
         unsigned int monthDay_,
         unsigned int hour_,
         unsigned int minute_,
         unsigned int second_);

    Date();

    Date(time_t date_);

    Date(const Date& source);

    ~Date();

    /// Surcharge de l'opérateur ==
    /// @param autre_ Objet à comparer
    /// @return Comparaison
    bool operator== (const Date &autre_) const;

    virtual std::string toStr()const;

    virtual std::string toLog() const;

    time_t toTimeT()const;

    static Date getNow();

    /**
     * Calcule le temps en seconde separant la date 1 de la date 2
     * @param date1_
     * @param date2_
     * @return temps ecoule en seconde
     */
    static double calculerDiff(const Date& date1_, const Date& date2_);

    unsigned int getSecond();

    unsigned int getMinute();

    unsigned int getHour();

    unsigned int getMonthDay();

    unsigned int getMonth();

    unsigned int getYear();

    static void test();

private :
    unsigned int _second;
    unsigned int _minute;
    unsigned int _hour;
    unsigned int _monthDay;
    unsigned int _month;
    unsigned int _year;
};

#endif // DATE_H
