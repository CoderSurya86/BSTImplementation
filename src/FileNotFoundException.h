/*
 * FileNotFound.h
 *
 *  Created on: Apr 29, 2019
 *      Author: surte
 */

#ifndef FILENOTFOUNDEXCEPTION_H_
#define FILENOTFOUNDEXCEPTION_H_

#include <stdexcept>
#include <string>

class FileNotFoundException: public std::runtime_error{
public:
	FileNotFoundException(const std::string& what_arg);
};

#endif /* FILENOTFOUNDEXCEPTION_H_ */
