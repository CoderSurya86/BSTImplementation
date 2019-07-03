/*
 * BSTTester.cpp
 *
 *  Created on: May 14, 2019
 *      Author: surte
 */

#include "BSTTester.h"
#include <iostream>
#include <limits>
#include <string>
#include <exception>

BSTTester::BSTTester() {

}

void BSTTester::testAdd(BinaryTree<std::string> bst){
	std::string str="";
	std::cout << "Enter new entry to add:";
	std::cin >> str;

	try{
		bst.add(str);
	}
	catch(const std::exception& e){
		throw;
	}

	bst.inorderTraversal(printTreeEntry);
}

void BSTTester::testRemove(BinaryTree<std::string> bst){
	std::string str="";
	std::cout << "Enter entry to remove:";
	std::cin >> str;

	try{
		bst.remove(str);
	}
	catch(const std::exception& e){
		throw;
	}

	bst.inorderTraversal(printTreeEntry);
}

void BSTTester::testTraverse(BinaryTree<std::string> bst){
	bst.inorderTraversal(printTreeEntry);
}

BSTTester::~BSTTester() {

}

void BSTTester::printTreeEntry(std::string& entry){
	std::cout << entry << "\n";
}
