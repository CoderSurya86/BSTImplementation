/*
 * BinaryTree.h
 *
 *  Created on: Apr 26, 2019
 *      Author: surte
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "BinaryNode.h"

template<typename T>
class BinaryTree {
public:
	BinaryTree();
	BinaryTree(const BinaryTree<T>& orig);
	bool isEmpty() const;
	BinaryTree<T>& operator=(const BinaryTree<T>& rhs);
	virtual ~BinaryTree();
	int getTreeDepth() const;
	T getSmallestSubTreeAllDeepestNodes() const;
	bool add(const T& newDataItem);
	bool remove(const T& existingItem);
	void preorderTraversal(void dataOperation(T&)) const;
	void inorderTraversal(void dataOperation(T&)) const;
	void postorderTraversal(void dataOperation(T&)) const;

private:
	BinaryNode<T>* root;
	BinaryNode<T>* copyTree(BinaryNode<T>* subTree);
	void discardTree(BinaryNode<T> *subTree);
	int getTreeDepthRec(BinaryNode<T> *subTree) const;
	T getSmallestSubTreeAllDeepestNodesRec(BinaryNode<T> *subTree) const;
	bool addRec(BinaryNode<T> *newNode, BinaryNode<T> *subTree);
	BinaryNode<T>* removeRec(const T& remDItem, BinaryNode<T> *subTree);
	void preorderTraversalRec(BinaryNode<T> *subTree, void dataOperation(T&)) const;
	void inorderTraversalRec(BinaryNode<T> *subTree, void dataOperation(T&)) const;
	void postorderTraversalRec(BinaryNode<T> *subTree, void dataOperation(T&)) const;
};

#include "BinaryTree.hpp"

#endif /* BINARYTREE_H_ */
