#include <iostream>
#include "testvector.h"
#include "date.h"

using namespace std;

int main()
{
    TestVector v;
    std::cout<<"now :"<<std::endl;
    std::cout<<Date::getNow().toLog()<<std::endl;

    Date::test();

    std::cout << "Hello World!" << std::endl;

    return 0;
}

