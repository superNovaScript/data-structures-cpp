#pragma once
#include "Node.h"
#include <iostream>
class BST
{
public :
	BST() {
	
	};
	~BST()
	{
		destroyTree(m_root);		
	}
	BST(int value ) {
	
		Node* node = new Node(value);

		m_root = node;
	
	};
	void printInOrder() {
		inOrderRec(m_root);
		std::cout << std::endl;
	}

	void insert(int value);
	bool contains(int value);
	void inOrderRec(Node *node);
	Node* getRoot() const;
	void destroyTree(Node* node);
	
private:
	Node* m_root = nullptr;
};

