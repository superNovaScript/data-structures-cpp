#pragma once
class Node
{
public:
	Node(int value) {
		m_value = value;
		left = nullptr;
		right = nullptr;
	}

	int m_value = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

