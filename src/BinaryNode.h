/*
 * BinaryNode.h
 *
 *  Created on: Apr 26, 2019
 *      Author: surte
 */

#ifndef BINARYNODE_H_
#define BINARYNODE_H_

template<typename T>
class BinaryNode {
public:
	BinaryNode();
	BinaryNode(const T& newData);
	BinaryNode(const T& newData, BinaryNode<T>* leftSubTree, BinaryNode<T>* rightSubTree);
	virtual ~BinaryNode();
	BinaryNode<T>* getLeft() const;
	BinaryNode<T>* getRight() const;
	T getData() const;
	void setLeft(BinaryNode<T>* leftSubTree);
	void setRight(BinaryNode<T>* rightSubTree);
	void setData(const T& newData);
private:
	BinaryNode<T> *left;
	BinaryNode<T> *right;
	T data;

};

#include "BinaryNode.hpp"

#endif /* BINARYNODE_H_ */
