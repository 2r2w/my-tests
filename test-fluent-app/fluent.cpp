/*
 * FluentMaker.cpp
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */

#include "fluent.h"
#include <iostream>

struct _FluentMaker::_inst
{
	static baseshptr nullptr;
	baseshptr ptr;
	std::vector<std::string> strings;

	_inst():ptr(nullptr){}
};
baseshptr _FluentMaker::_inst::nullptr;

extern "C" _FluentMaker::_FluentMaker(): inst( new _inst)
{
}

extern "C" _FluentMaker::~_FluentMaker()
{
}

extern "C" _FluentMaker &_FluentMaker::operator()(const std::string &str)
{
	if (inst->ptr==_inst::nullptr)
		inst->strings.push_back(str);
	return *this;
}

extern "C" _FluentMaker &_FluentMaker::operator()(baseshptr &ptr)
{
	if (inst->ptr==_inst::nullptr)
		inst->ptr = ptr;
	return *this;
}

extern "C" baseshptr _FluentMaker::Make(void)
{
	if (inst->ptr==_inst::nullptr)
	{
		if ( !inst->strings.empty() )
		{
			baseshptr bptr(new Basetype(inst->strings));
			inst->strings.clear();
			return bptr;
		}
		else
		{
			std::cout<<"this is my abortion()\n";
			abort();
		}
	}
	baseshptr bptr(inst->ptr);
	inst->ptr=_inst::nullptr;
	return bptr;
}

extern "C" FluentMaker *GetMaker(void)
{return new _FluentMaker();}
