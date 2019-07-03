/*
 * BinaryNode.cpp
 *
 *  Created on: Apr 26, 2019
 *      Author: surte
 */

template<typename T>
BinaryNode<T>::BinaryNode() {
	left=nullptr;
	right=nullptr;
	data = T();
}

template<typename T>
BinaryNode<T>::~BinaryNode() {

}

template<typename T>
BinaryNode<T>::BinaryNode(const T& newData){
	data=newData;
	left=nullptr;
	right=nullptr;
}

template<typename T>
BinaryNode<T>::BinaryNode(const T& newData, BinaryNode<T>* leftSubTree, BinaryNode<T>* rightSubTree){
	data=newData;
	left=leftSubTree;
	right=rightSubTree;
}

template<typename T>
BinaryNode<T>*  BinaryNode<T>::getLeft() const{
	return left;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getRight() const{
	return right;
}


template<typename T>
T BinaryNode<T>::getData() const{
	return data;
}

template<typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* leftSubTree){
	left=leftSubTree;
}

template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* rightSubTree){
	right=rightSubTree;
}


template<typename T>
void BinaryNode<T>::setData(const T& newData){
	data=newData;
}
