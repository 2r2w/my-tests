/*
 * vfluent.h
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */

#ifndef VFLUENT_H_
#define VFLUENT_H_

#include "basetype.h"
extern "C" {
class FluentMaker
{
public:
	virtual ~FluentMaker(){}
	virtual FluentMaker &operator()(const std::string &str)=0;
	virtual FluentMaker &operator()(baseshptr &ptr)=0;
	virtual baseshptr Make(void)=0;
};
}
#endif /* VFLUENT_H_ */
