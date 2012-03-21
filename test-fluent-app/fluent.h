/*
 * FluentMaker.h
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */

#ifndef FLUENTMAKER_H_
#define FLUENTMAKER_H_

#include "vfluent.h"
#include <string>

class _FluentMaker: public FluentMaker
{
public:
	_FluentMaker();
	~_FluentMaker();
	_FluentMaker &operator()(const std::string &str);
	_FluentMaker &operator()(baseshptr &ptr);
	baseshptr Make(void);
private:
	struct _inst;
	boost::shared_ptr<_inst> inst;
};

extern "C" FluentMaker *GetMaker(void);


#endif /* FLUENTMAKER_H_ */
