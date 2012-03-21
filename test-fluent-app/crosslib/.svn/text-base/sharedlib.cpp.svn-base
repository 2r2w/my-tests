/*
 * Loader.cpp
 *
 *  Created on: 17.02.2011
 *      Author: wikaka
 */

#include "sharedlib.h"
#ifdef __cplusplus
#include <iostream>
#include <boost/interprocess/detail/atomic.hpp>


struct SharedLib::_impl
{
	cross_LibHandle mHandle;
	std::string mPath;
	_impl() :	mHandle(NULL)
	{}
};

SharedLib::SharedLib(const std::string &path) :	impl(new SharedLib::_impl)
{
	impl->mPath.assign(path);
}

SharedLib::~SharedLib()
{
	if (impl->mHandle)
		cross_CloseLibrary(impl->mHandle);
}

bool SharedLib::Load()
{
	impl->mHandle = cross_LoadLibrary(impl->mPath.c_str());
	if (!impl->mHandle)
	{
		std::cerr<<"Loading shared lib: "<< cross_GetLibError() <<std::endl;
		return false;
	}
	return true;
}

void* SharedLib::GetFunction(const std::string & name)
{
	if (!impl->mHandle)
	{
		//ANALISATOR_SHLIB_LOGERR("Shared lib : "<<impl->mPath<<" not loaded");
		return NULL;
	}
	return reinterpret_cast<void*>(cross_GetSymAddr(impl->mHandle, name.c_str()));
}

#endif
