/*
 * basetype.cpp
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */

#include "basetype.h"
#include <iostream>
#include <algorithm>


Basetype::Basetype()
{
	strings.push_back("base1");
	strings.push_back("base2");
	strings.push_back("base3");
}

Basetype::Basetype(std::vector<std::string> &initialisator)
{
	strings.clear();
	std::copy(initialisator.begin(), initialisator.end(), std::back_inserter(strings));
}

void Basetype::Print()
{
	for(size_t i(0);i<strings.size();++i)
		std::cout<<strings[i]<<" ";
	std::cout<<std::endl;
}
