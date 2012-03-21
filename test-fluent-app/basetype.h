/*
 * basetype.h
 *
 *  Created on: Mar 21, 2012
 *      Author: wikaka
 */

#ifndef BASETYPE_H_
#define BASETYPE_H_
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

class Basetype
{
public:
	Basetype();
	Basetype(std::vector<std::string> &initialisator);
	void Print();
private:
	std::vector<std::string> strings;
};
typedef boost::shared_ptr<Basetype> baseshptr;
#endif /* BASETYPE_H_ */
