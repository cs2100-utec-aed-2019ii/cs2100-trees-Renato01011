#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Node.h"
using namespace std;

template <typename T>
class BinaryTree {
	Node<T>* root;

public:
	BinaryTree() { root = nullptr; }
	~BinaryTree() { DeleteAll(); }

	bool CheckIfTwoTreesAreEqual(BinaryTree<T> bt) {
		if (String_InOrderTraversal() == bt.String_InOrderTraversal()) {
			return true;
		}
		else { return false; }
	}

	void InsertNode(T value) {
		if (root == nullptr) {
			root = new Node<T>(value);
		}
		else {
			Node<T>* temp = root;

			while (temp != nullptr) {
				if (value < **temp) {
					if (temp->left == nullptr) { temp->left = new Node<T>(value); break; }
					else { temp = temp->left; }
				}
				else if (value > **temp) {
					if (temp->right == nullptr) { temp->right = new Node<T>(value); break; }
					else { temp = temp->right; }
				}
				else {
					cout << "Valores iguales en un BST" << endl;
				}
			}
		}
	}
	
	Node<T>* ReturnParent(Node<T>* node) {
		if (node == root || node == nullptr) { return nullptr; }
		Node<T>* temp = root;
		while (**temp != **node) {
			if (temp->left == nullptr) {
				if (**temp->right == **node) { return temp; }
				if (**node > * *temp) { temp = temp->right; }
				else { temp = temp->left; }
			}
			else if (temp->right == nullptr) {
				if (**temp->left == **node) { return temp; }
				if (**node > * *temp) { temp = temp->right; }
				else { temp = temp->left; }
			}
			else {
				if (**temp->right == **node || **temp->left == **node) { return temp; }
				if (**node > * *temp) { temp = temp->right; }
				else { temp = temp->left; }
			}
		}
		return nullptr;
	}

	Node<T>* FindNode(T value) {
		Node<T>* temp = root;
		while (*(*temp) != value) {
			if (value > * (*temp)) { temp = temp->right; }
			else { temp = temp->left; }
		}
		return temp;
	}
	
	Node<T>* minValue(Node<T>* node) {
		Node<T>* current = node;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	Node<T>* InOrderSuccessor(Node<T>* n) {
		if (n->right != nullptr) {
			return minValue(n->right);
		}
		Node<T>* p = ReturnParent(n);
		while (p != nullptr && n == p->right) {
			n = p;
			p = ReturnParent(p);
		}
		return p;
	}
	
	void DeleteNode(T value) {
		Node<T>* temp = root;
		while (*(*temp) != value) {
			if (value > * (*temp)) { temp = temp->right; }
			else { temp = temp->left; }
		}
		
		if (temp->right == nullptr && temp->left == nullptr) {
			Node<T>* Parent = ReturnParent(temp);
			if (Parent->left == temp) {
				delete temp;
				Parent->left = nullptr;
				return;
			}
			else { 
				delete temp;
				Parent->right = nullptr;
				return;
			}
		}
		else if (temp->right == nullptr || temp->left == nullptr) {
			if (temp->left != nullptr) {
				*(*temp) = *(*temp->left);
				delete temp->left;
				temp->left = nullptr;
				return;
			}
			else {
				*(*temp) = *(*temp->right);
				delete temp->right;
				temp->right = nullptr;
				return;
			}
		}
		else {
			Node<T>* inOrderSuccesor = InOrderSuccessor(temp);
			T val = *(*inOrderSuccesor);
			DeleteNode(*(*inOrderSuccesor));
			*(*temp) = val;
		}
	}

	void DeleteAll(Node<T>* node) {
		if (node == nullptr) { return; }

		DeleteAll(node->left);
		DeleteAll(node->right);

		delete node;
	}
	void DeleteAll() {
		if (root == nullptr) { return; }

		DeleteAll(root->left);
		DeleteAll (root->right);

		delete root;
		root = nullptr;
	}

	void PreOrderTraversal(Node<T>* node) {
		if (node == nullptr) { return; }
		cout << *(*node) << ' ';
		PreOrderTraversal(node->left);
		PreOrderTraversal(node->right);
	}
	void PreOrderTraversal() {
		if (root == nullptr) { return; }
		cout << *(*root) << ' ';
		if (root->left != nullptr) { PreOrderTraversal(root->left); }
		if (root->right != nullptr) { PreOrderTraversal(root->right); }
	}
	
	void String_InOrderTraversal(Node<T>* node, string& S) {
		if (node == nullptr) { return; }
		String_InOrderTraversal(node->left, S);
		S = S + to_string(*(*node)) + " ";
		String_InOrderTraversal(node->right, S);
	}
	string String_InOrderTraversal() {
		string S = "";
		if (root == nullptr) { return S; }
		if (root->left != nullptr) { String_InOrderTraversal(root->left, S); }
		S = S + to_string(*(*root)) + " ";
		if (root->right != nullptr) { String_InOrderTraversal(root->right, S); }
		return S;
	}

	void InOrderTraversal(Node<T>* node) {
		if (node == nullptr) { return; }
		InOrderTraversal(node->left);
		cout << *(*node) << ' ';
		InOrderTraversal(node->right);
	}
	void InOrderTraversal() {
		if (root == nullptr) { return; }
		if (root->left != nullptr) { InOrderTraversal(root->left); }
		cout << *(*root) << ' ';
		if (root->right != nullptr) { InOrderTraversal(root->right); }
	}

	void PostOrderTraversal(Node<T>* node) {
		if (node == nullptr) { return; }
		if (node->left != nullptr) { PostOrderTraversal(node->left); }
		if (node->right != nullptr) { PostOrderTraversal(node->right); }
		cout << *(*node) << ' ';
	}
	void PostOrderTraversal() {
		if (root == nullptr) { return; }
		if (root->left != nullptr) { PostOrderTraversal(root->left); }
		if (root->right != nullptr) { PostOrderTraversal(root->right); }
		cout << *(*root) << ' ';
	}

	bool CheckIfComplete(Node<T>* node) {
		if (node == nullptr) {
			return false;
		}
		else if (node->right == nullptr && node->left == nullptr) {
			return true;
		}
		else if (CheckIfComplete(node->right)) {
			if (CheckIfComplete(node->left)) {
				return true;
			}
		}
		return false;
	}
	bool CheckIfComplete() {
		if (CheckIfComplete(root->right)) {
			if (CheckIfComplete(root->left)) {
				return true;
			}
		}
		return false;
	}
	
	void FindAncestors(T value) {
		if (root == nullptr) {
			return;
		}
		Node<T>* parent = ReturnParent(FindNode(value));
		while (parent != nullptr) {
			cout << **parent << ' ';
			parent = ReturnParent(parent);
		}
	}

	int Height(Node<T>* node) {
		if (node == nullptr) {
			return 0;
		}

		int HeightLeft = Height(node->left);
		int HeightRight = Height(node->right);

		if (HeightLeft > HeightRight) {
			return HeightLeft + 1;
		}
		else { return HeightRight + 1; }
	}
	int Height() {
		if (root == nullptr) {
			return 0;
		}
		int HeightLeft = Height(root->left);
		int HeightRight = Height(root->right);

		if (HeightLeft > HeightRight) {
			return HeightLeft + 1;
		}
		else {
			return HeightRight + 1;
		}
	}

	vector<T> vector_Height(Node<T>* node) {
		if (node == nullptr) {
			vector<T> none;
			return none;
		}

		vector<T> lengthLeft = vector_Height(node->left);
		vector<T> lengthRight = vector_Height(node->right);

		if (lengthLeft.size() >= lengthRight.size()) {
			lengthLeft.push_back(**node);
			return lengthLeft;
		}
		else {
			lengthRight.push_back(**node);
			return lengthRight;
		}
	}
	vector<T> vector_Height() {
		if (root == nullptr) {
			vector<T> none;
			return none;
		}

		vector<T> lengthLeft = vector_Height(root->left);
		vector<T> lengthRight = vector_Height(root->right);

		if (lengthLeft.size() >= lengthRight.size()) {
			lengthLeft.push_back(**root);
			return lengthLeft;
		}
		else {
			lengthRight.push_back(**root);
			return lengthRight;
		}
	}


	void FindNextNodeInLevel(T value) {
		unsigned int level = 0;
		Node<T>* temp = root;
		while (**temp != value) {
			if (value > **temp) { temp = temp->right; level++; }
			else { temp = temp->left; level++; }
		}
		if (ReturnParent(temp) == nullptr) { return; }
		Node<T>* parent = ReturnParent(temp);
		if (**parent > **temp) { 
			if (parent->right == nullptr) { return; }
			cout << **(parent->right); 
			return;
		}
		else {
			if (ReturnParent(parent) == nullptr) { return; }
			parent = ReturnParent(parent);
			if (parent->right != nullptr) { parent = parent->right; }
			else { return; }
			if (**parent->left > * *temp) { cout << **parent->left; }
			else if (**parent->right > * *temp) { cout << **parent->right; }
			else { return; }
		}
	}

	Node<T>* Node_FindNextNodeInLevel(T value) {
		Node<T>* temp = root;
		while (**temp != value) {
			if (value > * *temp) { temp = temp->right; }
			else { temp = temp->left; }
		}
		if (ReturnParent(temp) == nullptr) { return nullptr; }
		Node<T>* parent = ReturnParent(temp);
		if (**parent > **temp) {
			if (parent->right == nullptr) { return nullptr; }
			return parent->right;
		}
		else {
			if (ReturnParent(parent) == nullptr) { return nullptr; }
			parent = ReturnParent(parent);
			if (parent->right != nullptr) { parent = parent->right; }
			else { return nullptr; }
			if (**parent->left > **temp) { return parent->left; }
			else if (**parent->right > **temp) { return parent->right; }
			else { return nullptr; }
		}
	}

	void CreateCDLL() {
		Node<T>* LastLeftNode = root;
		vector<T> longestPath = vector_Height();
		reverse(longestPath.begin(), longestPath.end());
		for (int i = 1; i < longestPath.size(); i++) {
			if (**LastLeftNode->left == longestPath[i]) {
				LastLeftNode = LastLeftNode->left;
			}
			else if (**LastLeftNode->right == longestPath[i]) {
				LastLeftNode = LastLeftNode->right;
			}
		}
			
		Node<T>* temp = LastLeftNode;
		while (Node_FindNextNodeInLevel(**temp) != nullptr) {
			Node<T>* Right = Node_FindNextNodeInLevel(**temp);
			Right->leftPartner = temp;
			temp->rightParter = Node_FindNextNodeInLevel(**temp);
			temp = Node_FindNextNodeInLevel(**temp);
		}
		temp->rightParter = LastLeftNode;
		LastLeftNode->leftPartner = temp;
	}

	void RootToLeafPaths(Node<T>* node, vector<T>& paths) {
		if (node == nullptr) { return; }
		paths.push_back(node->value);
		if (node->left == nullptr && node->right == nullptr) {
			for (unsigned int i = 0; i < paths.size(); i++) {
				cout << paths[i] << " ";
			}
			cout << endl;
		}
		RootToLeafPaths(node->left, paths);
		RootToLeafPaths(node->right, paths);
		paths.pop_back();
	}
	void RootToLeafPaths() {
		vector<T> paths;
		RootToLeafPaths(root, paths);
	}

	int isBalanced(Node<T>* node) {
		if (node == nullptr) {
			return 0;
		}

		int HeightLeft = Height(node->left);
		int HeightRight = Height(node->right);
		
		if (HeightLeft > HeightRight) {
			return HeightLeft + 1;
		}
		else { return HeightRight + 1; }
	}
	bool isBalanced() {
		if (root == nullptr) {
			return 0;
		}

		int HeightLeft = Height(root->left);
		int HeightRight = Height(root->right);

		if (HeightLeft == HeightRight) {
			return true;
		}
		else { return false; }
	}

	bool CheckBinaryTreeIsBST(Node<T>* root_1) {
		string S = "";
		if (root_1 == nullptr) { return S; }
		if (root_1->left != nullptr) { String_InOrderTraversal(root_1->left, S); }
		S = S + to_string(*(*root_1)) + " ";
		if (root_1->right != nullptr) { String_InOrderTraversal(root_1->right, S); }
		
		for (std::string::size_type i = 0; i < S.size()-1; ++i) {
			if (S[i] >= S[i + 1]) { return 0; }
		}
		return 1;
	}

	

	void print2DUtil(Node<T>* root, int space) {
		if (root == NULL)
			return;
		space += 10;
		print2DUtil(root->right, space);
		cout << endl;
		for (int i = 10; i < space; i++)
			cout << " ";
		cout << root->value << "\n";
		print2DUtil(root->left, space);
	}
	void print2D() {
		print2DUtil(root, 0);
	}
};