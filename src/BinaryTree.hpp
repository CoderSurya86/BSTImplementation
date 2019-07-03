/*
 * BinaryTree.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: surte
 */

#include<algorithm>
#include<exception>
#include "DuplicateEntryException.h"
#include "EmptyTreeException.h"
#include "EntryNotFoundException.h"
#include <iostream>

template<typename T>
BinaryTree<T>::BinaryTree() {
	root = nullptr;
}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& orig){

	root = copyTree(orig.root);

}


template<typename T>
bool BinaryTree<T>::isEmpty() const{

	return (this->root == nullptr);

}


template<typename T>
BinaryNode<T>* BinaryTree<T>::copyTree(BinaryNode<T>* origSubTree){

	BinaryNode<T>* copySubTree = nullptr;

	if(!(origSubTree == nullptr)){
		copySubTree = new BinaryNode<T>(origSubTree->getData());
		copySubTree->setLeft(copyTree(origSubTree->getLeft()));
		copySubTree->setRight(copyTree(origSubTree->getRight()));
	}

	return copySubTree;

}


template<typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& rhs){
	if(!(this->root == rhs.root)){ // Check if assignment is between the same trees
		// Clear the lhs before assignment
		discardTree(this->root);
		this->root = copyTree(rhs.root);
	}

	return *this;
}


template<typename T>
void BinaryTree<T>::discardTree(BinaryNode<T> *subTree){
	if(!(subTree == nullptr)){
		discardTree(subTree->getLeft());
		discardTree(subTree->getRight());
		delete subTree;
	}
}


template<typename T>
BinaryTree<T>::~BinaryTree() {
	discardTree(root);
}

template<typename T>
int BinaryTree<T>::getTreeDepth() const{
	return getTreeDepthRec(root);
}

template<typename T>
int BinaryTree<T>::getTreeDepthRec(BinaryNode<T> *subTree) const{

	if(subTree == nullptr)
		return 0;
	//else if(!(subTree->getLeft() == nullptr) && !(subTree->getRight() == nullptr))
	return 1+std::max(getTreeDepthRec(subTree->getLeft()), getTreeDepthRec(subTree->getRight()));
	/*else if(!(subTree->getLeft() == nullptr))
		return 1+getTreeDepthRec(subTree->getLeft());
	else // left is null but right is not null. If null would have been covered by first case
		return 1+getTreeDepthRec(subTree->getRight());*/
}

template<typename T>
T BinaryTree<T>::getSmallestSubTreeAllDeepestNodes() const{

	if(root == nullptr)
		throw EmptyTreeException("Attempt to extract data from an empty tree");
	else
		return getSmallestSubTreeAllDeepestNodesRec(root);
}

template<typename T>
T BinaryTree<T>::getSmallestSubTreeAllDeepestNodesRec(BinaryNode<T> *subTree) const{

	if((subTree->getLeft() == nullptr) && (subTree->getRight() == nullptr)){
		return subTree->getData();
	}
	else if(!(subTree->getLeft() == nullptr) && !(subTree->getRight() == nullptr)){

		int leftSubTreeHeight, rightSubTreeHeight;
		leftSubTreeHeight = getTreeDepthRec(subTree->getLeft());
		rightSubTreeHeight = getTreeDepthRec(subTree->getRight());

		if(leftSubTreeHeight == rightSubTreeHeight)
			return subTree->getData();
		else
			return leftSubTreeHeight > rightSubTreeHeight ? getSmallestSubTreeAllDeepestNodesRec(subTree->getLeft()) : getSmallestSubTreeAllDeepestNodesRec(subTree->getRight());
	}
	else if(!(subTree->getLeft() == nullptr))
		return getSmallestSubTreeAllDeepestNodesRec(subTree->getLeft());
	else // left is null but right is not null. If null would have been covered by first case
		return getSmallestSubTreeAllDeepestNodesRec(subTree->getRight());
}

template<typename T>
bool BinaryTree<T>::add(const T& newDataItem){

	BinaryNode<T> *newDataNode = new BinaryNode<T>(newDataItem);

	if(root == nullptr)
		root = newDataNode;
	else{
		try{
			return addRec(newDataNode, root);
		}
		catch(const std::exception& excp){
			throw;
		}
	}

	return true;
}


template<typename T>
bool BinaryTree<T>::addRec(BinaryNode<T> *newNode, BinaryNode<T> *subTree){

	if(newNode->getData() == subTree->getData()){
		throw DuplicateEntryException("Attempt to add duplicate data !");
	}
	else if(newNode->getData() < subTree->getData()){
		if(subTree->getLeft() == nullptr)
			subTree->setLeft(newNode);
		else
			return addRec(newNode, subTree->getLeft());
	}
	else if(newNode->getData() > subTree->getData()){
		if(subTree->getRight() == nullptr)
			subTree->setRight(newNode);
		else
			return addRec(newNode, subTree->getRight());
	}

	return true;
}


template<typename T>
bool BinaryTree<T>::remove(const T& existingItem){
	if(root == nullptr)
		throw EmptyTreeException("Attempted remove operation on an empty tree !");
	else{
		try{
			root = removeRec(existingItem, root);
		}
		catch(const std::exception& e){
			throw;
		}
	} // end of else-part
	return true;
}


template<typename T>
BinaryNode<T>* BinaryTree<T>::removeRec(const T& existingItem, BinaryNode<T> *subTree){

	try{
		if(!(subTree == nullptr)){
			if(existingItem == subTree->getData()){

				// 3 cases: (i) entry is leaf node (easy)
				//          (ii) entry is a subtree with just one child (moderately hard)
				//          (iii) entry is a subtree with both children (hard)
				if((subTree->getLeft() == nullptr) && (subTree->getRight() == nullptr)){ // match is a leaf-node
					delete subTree;
					subTree = nullptr;
				}
				else if(!(subTree->getLeft() == nullptr) && !(subTree->getRight() == nullptr)){ // match has both children
					BinaryNode<T>* tmp = subTree->getRight();
					if(tmp->getLeft() == nullptr){ // no left child
						subTree->setData(tmp->getData());
						subTree->setRight(tmp->getRight()); // works with nullptr and valid reference in right-child of tmp.
						delete tmp;
					}
					else{ // has left child
						BinaryNode<T> *tmpPrev=tmp, *tmpCurr=tmp->getLeft();
						T tmpData=T();

						// get to the left-most node
						while(!(tmpCurr->getLeft() == nullptr)){
							tmpPrev=tmpCurr;
							tmpCurr=tmpCurr->getLeft();
						}

						// reached the left-most node... extract data and delete
						tmpData = tmpCurr->getData();
						delete tmpCurr;
						tmpPrev->setLeft(nullptr);

						subTree->setData(tmpData); // set data of deleted node in subTree, giving the effect of its deletion
					}
				}
				else{ // match has single-child
					BinaryNode<T> *tmpChildPtr = subTree->getLeft();

					if(tmpChildPtr == nullptr)
						tmpChildPtr = subTree->getRight();

					delete subTree;

					subTree = tmpChildPtr;
				}

			}
			else if(existingItem < subTree->getData()){
				subTree->setLeft(removeRec(existingItem, subTree->getLeft()));
			}
			else{ // existingItem > subTree->getData()
				subTree->setRight(removeRec(existingItem, subTree->getRight()));
			}

			return subTree;

		} // end of if(!(subTree == nullptr))
		else
			throw EntryNotFoundException("Remove operation unsuccessful - ");
	}
	catch(const std::exception& e){
		throw;
	}
}


template<typename T>
void BinaryTree<T>::preorderTraversal(void dataOp(T&)) const{

	preorderTraversalRec(root, dataOp);

}


template<typename T>
void BinaryTree<T>::inorderTraversal(void dataOp(T&)) const{

	inorderTraversalRec(root, dataOp);

}


template<typename T>
void BinaryTree<T>::postorderTraversal(void dataOp(T&)) const{

	postorderTraversalRec(root, dataOp);

}


template<typename T>
void BinaryTree<T>::preorderTraversalRec(BinaryNode<T> *subTree, void dataOperation(T&)) const{

	if(!(subTree == nullptr)){
		T dItem = subTree->getData();

		dataOperation(dItem);
		preorderTraversalRec(subTree->getLeft(), dataOperation);
		preorderTraversalRec(subTree->getRight(), dataOperation);
	}

}


template<typename T>
void BinaryTree<T>::inorderTraversalRec(BinaryNode<T> *subTree, void dataOperation(T&)) const{

	if(!(subTree == nullptr)){
		T dItem = subTree->getData();

		inorderTraversalRec(subTree->getLeft(), dataOperation);
		dataOperation(dItem);
		inorderTraversalRec(subTree->getRight(), dataOperation);
	}

}


template<typename T>
void BinaryTree<T>::postorderTraversalRec(BinaryNode<T> *subTree, void dataOperation(T&)) const{

	if(!(subTree == nullptr)){
		T dItem = subTree->getData();

		postorderTraversalRec(subTree->getLeft(), dataOperation);
		postorderTraversalRec(subTree->getRight(), dataOperation);
		dataOperation(dItem);
	}

}
