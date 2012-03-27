/*
 * sharedlib.cpp
 *
 *  Created on: Mar 26, 2012
 *      Author: wikaka
 */
#include "sharedlib.h"
#include <stdlib.h>
#include <iostream>

#if defined _WIN32
#include <windows.h>
#include <sstream>
#elif defined __GNUC__
#include <dlfcn.h>
#endif

struct SharedLIbrary::_impl
{
	std::string lasterr;
#if defined _WIN32
	HMODULE libhandle;
#elif defined __GNUC__
	void *libhandle;
#endif

	_impl():lasterr("No error"),libhandle(0)
	{}

	void clear_error()
	{
#if defined _WIN32

#elif defined __GNUC__
		dlerror();//clear errors
#endif
		lasterr.assign("No Error");
	}

	void set_error(const std::string & str="")
	{
		if(str.empty())
		{
#if defined _WIN32
			DWORD errcode=GetLastError();
			std::stringstream ss;
			ss<<errcode;
			lasterr.assign(ss.str());
#elif defined __GNUC__
			lasterr.assign(dlerror());
#endif
		}
		else
		{
			lasterr.assign(str);
		}
	}
#if defined _WIN32
	HMODULE load(const std::string &path)
	{
		libhandle=LoadLibrary(path.c_str());
#elif defined __GNUC__
	void *load(const std::string &path)
	{
		libhandle=dlopen(path.c_str(),RTLD_LAZY);
#endif
		return libhandle;
	}

	bool unload(void)
	{
#if defined _WIN32
		return 1==FreeLibrary(libhandle);
#elif defined __GNUC__
		return 0==dlclose(libhandle);
#endif
	}

	void *symbol(const std::string &name)
	{
#if defined _WIN32
		return reinterpret_cast<void*>(GetProcAddress(libhandle,name.c_str()));
#elif defined __GNUC__
		return reinterpret_cast<void*>(dlsym(libhandle,name.c_str()));
#endif
	}
};


SharedLIbrary::SharedLIbrary(): impl(new _impl)
{
}

SharedLIbrary::SharedLIbrary(const std::string &path):impl(new _impl)
{
	Load(path);
}

SharedLIbrary::~SharedLIbrary()
{
	if(!Unload())
	{
		std::cerr<<"failed to unload shared library"
		<<impl->lasterr<<std::endl;
		abort();
	}

	delete impl;
}

bool SharedLIbrary::Unload(void)
{
	impl->clear_error();
	if(impl->libhandle)
	{
		if ( !impl->unload() )
		{
			impl->set_error();
			return false;
		}
		else
		{
			impl->libhandle=0;
		}
	}
	return true;
}

bool SharedLIbrary::Load(const std::string &path)
{
	impl->clear_error();
	if (!Unload())
		return false;

	impl->libhandle=impl->load(path);
	if(!impl->libhandle)
	{
		impl->set_error();
		return false;
	}
	else
	{
		return true;
	}
}

bool SharedLIbrary::Loaded(void)
{
	return impl->libhandle!=0;
}

const std::string &SharedLIbrary::Errdesc(void)
{
	return impl->lasterr;
}

void *SharedLIbrary::GetSymbol(const std::string &sym)
{
	impl->clear_error();
	if(!impl->libhandle)
	{
		impl->set_error("Library lot loaded");
		return 0;
	}
	void *res(impl->symbol(sym.c_str()));
	if(!res)
		impl->set_error();
	return res;
}


