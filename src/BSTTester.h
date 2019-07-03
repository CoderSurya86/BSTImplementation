/*
 * BSTTester.h
 *
 *  Created on: May 14, 2019
 *      Author: surte
 */

#ifndef BSTTESTER_H_
#define BSTTESTER_H_

#include "BinaryTree.h"
#include <string>

class BSTTester {
public:
	BSTTester();
	void testAdd(BinaryTree<std::string> bst);
	void testRemove(BinaryTree<std::string> bst);
	void testTraverse(BinaryTree<std::string> bst);
	static void printTreeEntry(std::string& entry);
	virtual ~BSTTester();
};

#endif /* BSTTESTER_H_ */
