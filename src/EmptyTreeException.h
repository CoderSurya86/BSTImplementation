/*
 * EmptyTreeException.h
 *
 *  Created on: Apr 30, 2019
 *      Author: surte
 */

#ifndef EMPTYTREEEXCEPTION_H_
#define EMPTYTREEEXCEPTION_H_

#include <stdexcept>
#include <string>

class EmptyTreeException: public std::runtime_error{
public:
	EmptyTreeException(const std::string& what_arg);
};

#endif /* EMPTYTREEEXCEPTION_H_ */
