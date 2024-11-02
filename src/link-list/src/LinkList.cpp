#include "LinkList.h"
#include <iostream>
#include <algorithm>
#include <sstream>

LinkList::LinkList(size_t value)
{
	// Create a node
	Node* node = new Node(value);

	// Adjust head and tail 
	head = node;

	tail = node;


	// Set length 
	m_lenght = 1;

}

LinkList::~LinkList()
{

	Node* temp = head;
	while (head)
	{
		head = head->m_next;
		delete temp;
		temp = head;

	}

	m_lenght = 0;
	
}

Node* LinkList::getHead() const
{
	return head;
}

Node* LinkList::get(const size_t index)
{
	if (index >= m_lenght || index < 0)
	{
		throw std::runtime_error("Out of bounds !");
	}

	Node* current = head;
	for (size_t i = 0; i < m_lenght; i++)
	{
		if (i == index) {

			return current;
		}
		current = current->m_next;
	}
	return nullptr;
}

void LinkList::set(const size_t index, const size_t value)
{
	if (index >= m_lenght || index < 0)
	{
		throw std::runtime_error("Out of bounds !");
	}
	Node* current = head;
	for (size_t i = 0; i < m_lenght; i++)
	{
		if (i == index) 
		{
			current->m_value = value;
			break;
		}
		current = current->m_next;
	}
}

Node* LinkList::getTail() const
{
	return tail;
}

size_t LinkList::getLength() const
{
	return m_lenght;
}

std::string LinkList::printList() const
{
	std::ostringstream oss;

	Node* current = head;

	while (current)
	{
		// Print values
		oss << current->m_value;
		if (current->m_next)
		{
			oss << ",";
		}
		// Update current node
		current = current->m_next;
	}

	return oss.str();
}

void LinkList::append(const size_t val)
{
	// Create a new node
	Node* newNode = new Node(val);
	if (head)
	{
		tail->m_next = newNode;
		
	}
	else
	{
		head = newNode;
		
	}

	tail = newNode;
	m_lenght++;

	// Complexyt is O(1)
}

void LinkList::prepend(const size_t val)
{
	// Create a new node
	Node* newNode = new Node(val);

	if (head)
	{
		newNode->m_next = head;
		
		head = newNode;

	}
	else
	{
		head = newNode;
		tail = newNode;

	}


	m_lenght++;

	// Complexty is O(1)

}

void LinkList::removeLast()
{
	if (! head)
	{
		throw std::runtime_error("Cannot remove this position !");
		
	}
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* temp = head;
		while (temp->m_next != tail)
		{
			temp = temp->m_next;

		}
		// Tail i silmen lazým ve yeni tail temp olmalý
		delete tail;
		tail = temp;
		tail->m_next = nullptr;
	}
	
	

	m_lenght--;

	// Complexty of remove last is O(n)

}

void LinkList::removeFirst()
{
	if (!head)
	{
		throw std::runtime_error("Cannot remove this position !");

	}
	else if (head == tail)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node *newHead = head->m_next;
		delete head;
		head = newHead;
	}
	m_lenght--;

	// Complexty is O(1) . Constant
}

void LinkList::insert(const size_t val, const size_t pos)
{
	if (m_lenght < pos)
	{
		throw std::runtime_error("Cannot insert this position !");
		
	}
	else if (m_lenght == pos)
	{
		// append or prepend
		append(val);
	}
	else if (pos == 0)
	{
		prepend(val);
	}
	else
	{
		Node* newNode = new Node(val);
		size_t curIndex = 0;
		
		Node* tempNode = head;
		while (tempNode)
		{
			if (curIndex == pos-1)
			{
				newNode->m_next = tempNode->m_next;
				tempNode->m_next = newNode;
			}
			tempNode = tempNode->m_next;
			curIndex++;
		}
	m_lenght++;
	}

	// Complexty for middle insert O(n) otherwise O(1)
}

void LinkList::remove(const size_t pos)
{
	if (m_lenght < pos)
	{
		throw std::runtime_error("Cannot insert this position !");

	}
	else if (m_lenght == pos)
	{
		// append or prepend
		removeLast();
	}
	else if (pos == 0)
	{
		removeFirst();

	}
	else
	{
		// Remove at middle
		size_t curIndex = 0;

		Node* tempNode = head;
		while (tempNode)
		{
			if (curIndex == pos - 1)
			{
				Node * newNext = tempNode->m_next->m_next;

				delete tempNode->m_next;

				tempNode->m_next = newNext;
			}
			tempNode = tempNode->m_next;
			curIndex++;
		}
		m_lenght--;
	}



}

void LinkList::reverse()
{
	Node* prev = nullptr;
	Node* current = head;
	tail = head;
	
	while (current) {
		Node* next = current->m_next; // Store next node
		current->m_next = prev; // Reverse the current node's pointer
		prev = current; // Move prev and current one step forward
		current = next;
	}
	head = prev; // Update head to the new front of the list
}
