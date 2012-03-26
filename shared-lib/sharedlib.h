/*
 * sharedlib.h
 *
 *  Created on: Mar 26, 2012
 *      Author: wikaka
 */

#ifndef SHAREDLIB_H_
#define SHAREDLIB_H_

#include <string>

class SharedLIbrary
{
public:

	SharedLIbrary();
	explicit SharedLIbrary(const std::string &path);

	~SharedLIbrary();

	bool Load(const std::string &path);
	bool Unload(void);

	bool Loaded(void);

	const std::string &Errdesc(void);

	void *GetSymbol(const std::string &sym);

private:

	struct _impl;
	_impl *impl;
};


#endif /* SHAREDLIB_H_ */
