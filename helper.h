#ifndef HELPER_H
#define HELPER_H

#include <string>

class Helper
{
public:
    Helper();
    ~Helper();

    static std::string toString(int nb);

    static std::string toString(double nb);

    static std::string toString(float nb);

    static int stringToInt(std::string txt);

    static std::string toStringBit(unsigned char uc);

    static std::string toStringBit(unsigned short us);

    static void test();

};

#endif // HELPER_H
