#include "testvector.h"
#include "logger.h"
#include "helper.h"
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

void vectorMinMax()
{
    std::vector<double> v1;
    v1.push_back(-1.0);
    v1.push_back(0.0);
    v1.push_back(2.0);
    v1.push_back(3.0);

    double min = *std::min_element(v1.begin(), v1.end());
    double max = *std::max_element(v1.begin(), v1.end());

    LOG_DEBUG("MIN VECTOR : " + Helper::toString(min));
    LOG_DEBUG("MAX VECTOR : " + Helper::toString(max));
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

    vectorMinMax();
}

TestVector::~TestVector()
{

}

