#pragma once
#include "Node.h"
#include <string>
class LinkList
{
public:
	LinkList(size_t value);
	LinkList() {};
	~LinkList();


	Node* getHead() const;
	Node* get(const size_t index);
	void set(const size_t index, const size_t value);
	Node* getTail() const;
	size_t getLength() const;
	std::string printList() const;
	void append(const size_t val);
	void prepend(const size_t val);
	void removeLast();
	void removeFirst();
	void insert(const size_t val, const size_t pos);
	void remove(const size_t pos);
	void reverse();

private:
	size_t m_lenght = 0;
;	Node* head = nullptr;
	Node* tail = nullptr;
};

