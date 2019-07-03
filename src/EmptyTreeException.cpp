/*
 * EmptyTreeException.cpp
 *
 *  Created on: Apr 30, 2019
 *      Author: surte
 */

#include "EmptyTreeException.h"

EmptyTreeException::EmptyTreeException(const std::string& what_arg):runtime_error("\nEmptyTreeException: "+what_arg+"\n"){

}

