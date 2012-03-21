/*
 * Loader.h
 *
 *  Created on: 17.02.2011
 *      Author: wikaka
 */

#ifndef SHAREDLIB_H_
#define SHAREDLIB_H_

#ifdef __WIN32__
#	ifndef WIN32
#		define WIN32
#	endif/*WIN32*/
#endif/*__WIN32__*/

#if defined(WIN32)
#include <windows.h>
#define cross_LibHandle HMODULE
#define cross_LoadLibrary(path) LoadLibrary(path)
#define cross_GetSymAddr(lib,name) GetProcAddress(lib,name)
static char ___dll_error_buf[] = "!GetLibError!";
#define cross_GetLibError() ___dll_error_buf
#define cross_CloseLibrary(lib) FreeLibrary(lib)
#ifndef __DLL_SOURCE__
#define DLLSPEC  __declspec(dllimport)
#else
#define DLLSPEC __declspec(dllexport)
#endif

#elif defined(__unix__)
#include <dlfcn.h>
#define cross_LibHandle void*
#define cross_LoadLibrary(path) dlopen(path,RTLD_LAZY)
#define cross_GetSymAddr(lib,name) dlsym(lib,name)
#define cross_GetLibError() dlerror()
#define cross_CloseLibrary(lib) dlclose(lib)
#define DLLSPEC

#endif

#ifdef __cplusplus
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

class SharedLib {
public:
	SharedLib(const std::string &path);
	~SharedLib();
	bool Load();
	void *GetFunction( const std::string & name );
private:
	struct _impl;
	boost::shared_ptr<_impl> impl;
};
typedef boost::shared_ptr<SharedLib> SharedLibShPtr;
typedef boost::weak_ptr<SharedLib>   SharedLibWeakPtr;
#endif // __cplusplus
#endif /* SHAREDLIB_H_ */
