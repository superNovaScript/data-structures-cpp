#pragma once
class Node
{
public :
	Node(int value) :m_value{ value }, next{ nullptr } {};

	int m_value;
	Node *next = nullptr;

};

