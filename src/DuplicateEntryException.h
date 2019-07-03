/*
 * DuplicateEntryException.h
 *
 *  Created on: Apr 27, 2019
 *      Author: surte
 */

#ifndef DUPLICATEENTRYEXCEPTION_H_
#define DUPLICATEENTRYEXCEPTION_H_

#include<stdexcept>
#include<string>

class DuplicateEntryException: public std::runtime_error {
public:
	DuplicateEntryException(const std::string& what_arg);
};

#endif /* DUPLICATEENTRYEXCEPTION_H_ */
