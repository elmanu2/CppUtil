#include "testvector.h"
#include "logger.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>

void append2Vectors()
{
    std::vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);

    std::vector<int> intVec2;
    intVec2.push_back(4);
    intVec2.push_back(5);
    intVec2.push_back(6);

    std::cout<<"First vector : ";
    for(std::vector<int>::const_iterator itInt = intVec.begin();
        itInt != intVec.end(); ++itInt)
    {
        std::cout<<*itInt<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Second vector : ";
    for(std::vector<int>::const_iterator itInt = intVec2.begin();
        itInt != intVec2.end(); ++itInt)
    {
        std::cout<<*itInt<<" ";
    }
    std::cout<<std::endl;

    intVec.insert(intVec.end(),intVec2.begin(), intVec2.end());

    std::cout<<"First vector after concatenation : ";
    for(std::vector<int>::const_iterator itInt = intVec.begin();
        itInt != intVec.end(); ++itInt)
    {
        std::cout<<*itInt<<" ";
    }
    std::cout<<std::endl;
}

TestVector::TestVector()
{
    std::vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    intVec.push_back(4);
    intVec.push_back(5);

    std::cout<<"Iterator on vector values : ";
    for(std::vector<int>::const_iterator itInt = intVec.begin();
        itInt != intVec.end(); ++itInt)
    {
        std::cout<<*itInt<<" ";
    }
    std::cout<<std::endl;

    int resultat = std::accumulate(intVec.begin(), intVec.end(),0);
    std::cout<<"Accumulate : "<<resultat<<std::endl;

    append2Vectors();
}

TestVector::~TestVector()
{

}

