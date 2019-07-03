/*
 * BTOperator.h
 *
 *  Created on: Apr 29, 2019
 *      Author: surte
 */

#ifndef BTOPERATOR_H_
#define BTOPERATOR_H_

#include "BinaryTree.h"
#include <string>
#include <fstream>

class BTOperator {
public:
	BTOperator();
	BTOperator(const std::string& iFile);
	void run();
	virtual ~BTOperator();
	static void printDataEntry(std::string& dEntry);
	static void printDataToFile(std::string& dEntry);

private:
	BinaryTree<std::string> myBTree;
	BinaryTree<std::string> copyBTree;
	bool copyCreated;
	static std::ofstream traversalOutFStream;
};

#endif /* BTOPERATOR_H_ */
