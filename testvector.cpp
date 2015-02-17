#include "testvector.h"
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <numeric>

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

}

TestVector::~TestVector()
{

}

