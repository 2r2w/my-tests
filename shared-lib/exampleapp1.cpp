/*
 * exampleapp1.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: wikaka
 */


#include <iostream>
#include "sharedlib.h"

int main(int argc, char**argv)
{
	if (argc<2)
		return -1;
	SharedLIbrary lib(argv[1]);
	if (!lib.Loaded())
	{
		std::cerr<<"failed to load ["<<argv[1]<<"] :"<<lib.Errdesc()<<std::endl;
		return -1;
	}
	return 0;
}
