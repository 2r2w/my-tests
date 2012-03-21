/*
 * main.cpp
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */



#include "../test-fluent-app/vfluent.h"
#include <boost/shared_ptr.hpp>

FluentMaker *(*maker)(void)=NULL;

extern "C" void setmaker(FluentMaker *(*f)(void))
{
	maker=f;
}

baseshptr Function1(const std::string &somestr)
{
	boost::shared_ptr<FluentMaker> _m( maker() );
	FluentMaker &m=*_m;
	return m("test1")(somestr)("test2").Make();
}

baseshptr Function2(baseshptr &ptr)
{
	boost::shared_ptr<FluentMaker> _m( maker() );
	FluentMaker &m=*_m;
	return m(ptr)("test2").Make();
}

baseshptr Function3(void)
{
	boost::shared_ptr<FluentMaker> _m( maker() );
	FluentMaker &m=*_m;
	return m.Make();
}

extern "C" baseshptr call1(const std::string &somestr)
{
	return Function1(somestr);
}

extern "C" baseshptr call2(baseshptr &ptr)
{
	return Function2(ptr);
}

extern "C" baseshptr call3(void)
{
	return Function3();
}
