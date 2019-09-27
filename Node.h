#pragma once

template <typename T>
class Node {
protected:
	T value;
	Node<T>* right;
	Node<T>* left;
	Node<T>* rightParter;
	Node<T>* leftPartner;

	template <typename T>
	friend class BinaryTree;

public:
	Node(T value) : value{ value }, right{ nullptr }, left{ nullptr }, rightParter{ nullptr }, leftPartner{ nullptr } {}
	Node() : right{ nullptr }, left{ nullptr }, rightParter{ nullptr } {}
	T& operator*() { return value; }

	
};