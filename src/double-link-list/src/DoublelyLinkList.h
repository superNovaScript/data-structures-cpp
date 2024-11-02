#pragma once
#include "Node.h"

class DoubleLinkList
{
public:
	DoubleLinkList() : m_length{ 0 }, m_head{ nullptr }, m_tail{ nullptr } {};
	DoubleLinkList(size_t val)  
	{
		Node* node = new Node(val);

		m_head = node;
		m_tail = node;
		m_length++;
	};
	~DoubleLinkList();
	Node* getHead() const;
	Node* getTail() const;
	size_t getLength() const;

	void append(const size_t val);
	void prepend(const size_t val);
	void insert(const size_t pos, const size_t val);
	void removeFirst();
	void removeLast();
	void remove(const size_t pos);

private:
	size_t m_length = 0;
	Node* m_head = nullptr;
	Node* m_tail= nullptr;
};

