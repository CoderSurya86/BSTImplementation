/*
 * FileNotFound.cpp
 *
 *  Created on: Apr 29, 2019
 *      Author: surte
 */

#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(const std::string& what_arg):runtime_error("\nFileNotFoundException: "+what_arg+"\n") {

}
