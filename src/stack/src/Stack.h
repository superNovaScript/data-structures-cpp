#pragma once
#include "Node.h"
class Stack
{
public:
	Stack() : m_top{ nullptr }, m_bottom{ nullptr }, m_height{0} {};
	~Stack();
	Stack(int value) 
	{
		Node* node = new Node(value);
		m_top = node;
		m_bottom = node;
		m_height++;
	}

	Node *getTop() const;
	Node *getBottom() const;
	int getHeight() const;
	void push(int value);
	int pop();

private:
	Node* m_top = nullptr;
	Node* m_bottom = nullptr;
	int m_height = 0;
};

