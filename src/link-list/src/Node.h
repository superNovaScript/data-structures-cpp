#pragma once
#include <iostream>
class Node
{
public : 
	Node(size_t value) : m_value{ value }, m_next{nullptr} {	}
	
	size_t m_value;
	Node* m_next = nullptr;
};

