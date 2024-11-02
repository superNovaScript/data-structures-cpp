#include "DoublelyLinkList.h"
#include <exception>
#include <stdexcept>

DoubleLinkList::~DoubleLinkList()
{
	Node* dummyNode = m_head;

	while (m_head)
	{

		m_head = m_head->next;
		
	
		delete dummyNode;

		dummyNode = m_head;
		
		m_length--;
	}

}

Node* DoubleLinkList::getHead() const
{
	return m_head;
}

Node* DoubleLinkList::getTail() const
{
	return m_tail;
}

size_t DoubleLinkList::getLength() const
{
	return m_length;
}

void DoubleLinkList::append(const size_t val)
{
	Node* newNode = new Node(val);

	if (m_length == 0)
	{
		m_tail = newNode;
		m_head = newNode;
	}
	else
	{
		Node* dummyNode = m_tail;
		
		dummyNode->next = newNode;
		newNode->prev = m_tail;

		m_tail = newNode;

	}


	m_length++;

}

void DoubleLinkList::prepend(const size_t val)
{
	Node* newNode = new Node(val);

	if (m_length == 0)
	{
		m_tail = newNode;
		m_head = newNode;

	}
	else {

		Node* dummy = m_head;

		newNode->next = dummy;

		dummy->prev = newNode;

		m_head = newNode;
	}
	m_length++;

}

void DoubleLinkList::insert(const size_t pos, const size_t val)
{
	if (pos > m_length || pos < 0)
	{
		throw std::runtime_error("Invalid position!");
	}
	else if (pos == m_length)
	{
		append(val);
	}
	else if (pos == 0)
	{
		prepend(val);
	}
	else
	{
		Node* newNode = new Node(val);
		Node* dummy = m_head;
		
		size_t currentndex = 1;
		while (dummy)
		{
			if (pos == currentndex )
			{
				newNode->next = dummy->next;
				newNode->prev = dummy;
				dummy->next = newNode;
				break;
			}
			dummy = dummy->next;
			currentndex++;
		}
		m_length++;
	}

	

}

void DoubleLinkList::removeFirst()
{
	if (m_length == 0)
	{
		throw std::runtime_error("Empty list ! Cant remove anything");
	}
	else if (m_length == 1)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
	}
	else
	{
		Node* dummy = m_head;
		m_head = m_head->next;
		m_head->prev = nullptr;
		delete dummy;

		
	}

	m_length--;
}

void DoubleLinkList::removeLast()
{
	if (m_length == 0)
	{
		throw std::runtime_error("Empty list ! Cant remove anything");
	}
	else if (m_length == 1)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
	}
	else
	{
		Node* dummy = m_tail;
		m_tail = m_tail->prev;
		m_tail->next = nullptr;
		delete dummy;

	}

	m_length--;
}

void DoubleLinkList::remove(const size_t pos)
{
	if (pos >= m_length || pos < 0 || m_length == 0)
	{
		throw std::runtime_error("Empty list ! Cant remove anything");
	}
	else if (pos == 0)
	{
		removeFirst();
	}
	else if (pos == m_length-1)
	{
		removeLast();
	}
	else
	{
		//remove id
		Node* dummy = m_head;
		size_t ind = 0;
		while (dummy)
		{
			if (pos == ind)
			{
				dummy->prev->next = dummy->next;
				dummy->next->prev = dummy->prev;
				delete dummy;
				break;
			}
			ind++;
			dummy = dummy->next;
		}
		m_length--;

	}


}
