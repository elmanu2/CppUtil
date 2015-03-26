#include "helper.h"
#include "stdlib.h"
#include <cassert>

Helper::Helper()
{

}

Helper::~Helper()
{

}

std::string Helper::toString(int nb)
{
    char buffer[256];
    sprintf_s(buffer,"%i",nb);
    return std::string(buffer);
}

std::string Helper::toString(double nb)
{
    char buffer[256];
    sprintf_s(buffer,"%f",nb);
    return std::string(buffer);
}

std::string Helper::toString(float nb)
{
    char buffer[256];
    sprintf_s(buffer,"%f",nb);
    return std::string(buffer);
}

std::string Helper::toStringBit(unsigned char uc)
{
    int i;
    int size = sizeof(uc);
    std::string bitString;
    for(i=8*size-1; i>=0; i--) {
        if((uc & (1 << i)))
        {
            bitString += "1";
        }
        else
        {
            bitString += "0";
        }
    }
    return bitString;
}

std::string Helper::toStringBit(unsigned short us)
{
    int i;
    int size = sizeof(us);
    std::string bitString;
    for(i=8*size-1; i>=0; i--) {
        if((us & (1 << i)))
        {
            bitString += "1";
        }
        else
        {
            bitString += "0";
        }
    }
    return bitString;
}

unsigned char Helper::bitShiftToLSB(const unsigned char& c)
{
    unsigned char resultat = c;
    if(c == 0x00)
    {
        return c;
    }

    while((resultat&0x01)!=0x01)
    {
        resultat = resultat>>1;
    }
    return resultat;
}

unsigned char Helper::bitShiftToMSB(const unsigned char& c)
{
    unsigned char resultat = c;
    if(c == 0x00)
    {
        return c;
    }

    while((resultat&0x80)!=0x80)
    {
        resultat = resultat<<1;
    }
    return resultat;
}

void Helper::test()
{
    int a = 255;
    unsigned short us = 0xF0F0;
    unsigned char b = 255;
    assert(toString(a) == "255");
    assert(toStringBit(us) == "1111000011110000");
    assert(toStringBit(b) == "11111111");

    unsigned char c = 0x30;

    c = bitShiftToLSB(c);
    assert(toStringBit(c) == "00000011");
    c = bitShiftToMSB(c);
    assert(toStringBit(c) == "11000000");

}


