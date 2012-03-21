/*
 * main.cpp
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */

#include "crosslib/sharedlib.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include "fluent.h"

int main( int argc, char **argv)
{
	if (argc < 2)
		return -1;

	SharedLib lib(argv[1]);
	if (!lib.Load())
		return -2;


	baseshptr (*f1)(const std::string &)= (baseshptr (*)(const std::string &))lib.GetFunction("call1");
	if (!f1)
		return -3;

	void (*f2)(FluentMaker *(*)(void))=(void (*)(FluentMaker *(*)(void)))lib.GetFunction("setmaker");
	if (!f2)
		return -4;

	baseshptr (*f3)(baseshptr &)= (baseshptr (*)(baseshptr &))lib.GetFunction("call2");
	if (!f3)
		return -5;

	baseshptr (*f4)(void)= (baseshptr (*)(void))lib.GetFunction("call3");
	if (!f4)
		return -3;

	f2(GetMaker);
	baseshptr mptr1(f1("here is zhopa"));
	mptr1->Print();

	baseshptr tmpptr( new Basetype());
	baseshptr mptr2(f3(tmpptr));

	mptr2->Print();
	baseshptr mptr3(f4());
	mptr3->Print();

	return 0;
}
