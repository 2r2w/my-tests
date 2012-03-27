/*
 * exampleapp1.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: wikaka
 */


#include <iostream>
#include "sharedlib.h"
#include "examplelib1.h"

int main(int argc, char**argv)
{
	#if defined _WIN32
	SharedLIbrary lib("./libexamplelib1.dll");	
	#elif defined __GNUC__
	SharedLIbrary lib("./libexamplelib1.so");	
	#endif
	if (!lib.Loaded())
	{
		std::cerr<<"failed to load :"<<lib.Errdesc()<<std::endl;
		return -1;
	}

	testclass1 *(*fn)(void)=
	(testclass1 *(*)(void))lib.GetSymbol("create_testclass1");
	if(!fn)
	{
		std::cerr<<"failed to load :"<<lib.Errdesc()<<std::endl;
		return -2;
	}

	testclass1 *a=fn();
	a->test_method1("hello world");
	std::string str("hello world");
	a->test_method2(&str);
	a->test_method3(str);
	
	delete a;

	return 0;
}
