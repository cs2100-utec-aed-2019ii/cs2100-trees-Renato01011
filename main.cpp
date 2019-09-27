#include <iostream>
#include "Trees.h"
using namespace std;

int main() {
	
	BinaryTree<int> bt;
	bt.InsertNode(5);
	bt.InsertNode(3);
	bt.InsertNode(7);
	bt.InsertNode(2);
	bt.InsertNode(4);
	bt.InsertNode(8);
	bt.InsertNode(6);
	/*
	bt.InOrderTraversal();
	cout << endl;
	bt.print2D();
	bt.PreOrderTraversal();
	cout << endl;
	bt.PostOrderTraversal();
	cout << endl;

	cout << bt.CheckIfComplete();
	cout << endl;

	bt.DeleteNode(8);
	bt.InOrderTraversal();
	cout << endl;
	
	bt.FindAncestors(2);
	cout << endl;

	cout << bt.Height();
	cout << endl;
	
	
	bt.FindNextNodeInLevel(2);
	cout << ' ';
	bt.FindNextNodeInLevel(4);
	bt.FindNextNodeInLevel(6);
	cout << endl;
	*/
	bt.CreateCDLL();
	/*
	
	bt.RootToLeafPaths();
	
	cout << bt.isBalanced();
	*/
	return 0;
}