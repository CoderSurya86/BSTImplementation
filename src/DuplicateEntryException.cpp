/*
 * DuplicateEntryException.cpp
 *
 *  Created on: Apr 27, 2019
 *      Author: surte
 */

#include "DuplicateEntryException.h"

DuplicateEntryException::DuplicateEntryException(const std::string& what_arg):runtime_error("\nDuplicateEntryException: "+what_arg+"\n") {

}


