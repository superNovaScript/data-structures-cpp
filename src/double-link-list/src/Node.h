#pragma once
class Node
{
public :
	Node(size_t value) : m_value{value}, next{nullptr}, prev{nullptr}{}

	size_t m_value;
	Node * next;
	Node* prev ;
};

