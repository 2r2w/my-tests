/*
 * examplelib1.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: wikaka
 */


#include "examplelib1.h"
#include <iostream>

DLLSPEC testclass1::testclass1()
{
}

DLLSPEC void testclass1::test_method1(const std::string &str)
{
	std::cout<<str<<std::endl;
}

DLLSPEC void testclass1::test_method2(std::string *str)
{
	std::cout<<"string capacity: "<<str->capacity()<<std::endl;
	str->resize(str->capacity()*2);
	std::cout<<"string capacity: "<<str->capacity()<<std::endl;
	std::cout<<*str<<std::endl;
}

DLLSPEC void testclass1::test_method3(std::string &str)
{
	std::cout<<"string capacity: "<<str.capacity()<<std::endl;
	str.resize(str.capacity()*2);
	std::cout<<"string capacity: "<<str.capacity()<<std::endl;
	std::cout<<str<<std::endl;
}


testclass1::~testclass1()
{
}

DLLSPEC testclass1 *create_testclass1(void)
{
	return new testclass1();
}
