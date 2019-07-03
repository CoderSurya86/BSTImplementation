/*
 * EntryNotFoundException.h
 *
 *  Created on: May 1, 2019
 *      Author: surte
 */

#ifndef ENTRYNOTFOUNDEXCEPTION_H_
#define ENTRYNOTFOUNDEXCEPTION_H_

#include <stdexcept>
#include <string>

class EntryNotFoundException: public std::runtime_error {
public:
	EntryNotFoundException(const std::string& what_arg);
};

#endif /* ENTRYNOTFOUNDEXCEPTION_H_ */
