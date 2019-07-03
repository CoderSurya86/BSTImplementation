/*
 * EntryNotFoundException.cpp
 *
 *  Created on: May 1, 2019
 *      Author: surte
 */

#include "EntryNotFoundException.h"

EntryNotFoundException::EntryNotFoundException(const std::string& what_arg):runtime_error("\nEntryNotFoundException: "+what_arg) {

}

