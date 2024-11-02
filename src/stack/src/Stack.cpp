#include "Stack.h"
#include <exception>
#include <stdexcept>
Stack::~Stack()
{
	//Node* temp = m_top;
	//while (m_top)
	//{
	//	m_top = m_top->next;
	//	
	//	delete temp;
	//	
	//}
}
Node* Stack::getTop() const
{
	return m_top;
}

Node* Stack::getBottom() const
{
	return m_bottom;
}

int Stack::getHeight() const
{
	return m_height;
}

void Stack::push(int value)
{
	Node* node = new Node(value);
	if (m_height == 0)
	{
		m_top = node;
		m_bottom = node;
	}
	else
	{
		node->next = m_top;
		m_top = node;
	}
	
	m_height++;

}

int Stack::pop()
{
	if (m_height == 0)
	{
		throw std::runtime_error("Empty stack ! You cant pop!");
	}
	else
	{
		Node* temp = m_top;
		int poppedValue = temp->m_value;

		m_top = temp->next;

		delete temp;
		m_height--;
		return poppedValue;
	}
	
}
