#ifndef HELPER_H
#define HELPER_H

#ifdef CPPUTILBUILDDLL
#define CPPUTILEXPORT  __declspec( dllexport ) 
#else
#define CPPUTILEXPORT  __declspec( dllimport ) 
#endif

#include <string>
#include "windows.h"

class CPPUTILEXPORT Helper
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

    static unsigned char bitShiftToLSB(const unsigned char& c);

    static unsigned char bitShiftToMSB(const unsigned char& c);

    static std::string windowsError( const DWORD& dwErrorCode);

    static void test();

};

#endif // HELPER_H
