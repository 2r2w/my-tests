/*
 * examplelib1.h
 *
 *  Created on: Mar 26, 2012
 *      Author: wikaka
 */

#ifndef EXAMPLELIB1_H_
#define EXAMPLELIB1_H_

#include <string>
#ifndef DLLSPEC
  #if defined(_WIN32)
  #ifndef _USRDLL
   #define DLLSPEC __declspec(dllimport)
  #else
   #define DLLSPEC __declspec(dllexport)
  #endif
 #elif defined(__GNUC__)
  #define DLLSPEC
 #endif
#endif

class DLLSPEC testclass1
{
public:
	testclass1();
	virtual ~testclass1();
	virtual void test_method1(const std::string &str);
	virtual void test_method2(std::string *str);
	virtual void test_method3(std::string &str);
};

extern "C" DLLSPEC testclass1 *create_testclass1(void);

#endif /* EXAMPLELIB1_H_ */
