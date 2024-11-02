#include "BST.h"

void BST::insert(int value)
{
	Node* newNode = new Node(value);
	if (!m_root)
	{
		m_root = newNode;
	}
	else
	{
		Node* tempNode = m_root;

		while (tempNode)
		{
			if (newNode->m_value == tempNode->m_value)
			{
				break;
			}
			else if (newNode->m_value > tempNode->m_value)
			{
				Node* rightNode = tempNode->right;
				// go to right
				if (!rightNode)
				{
					tempNode->right = newNode;
				}
				tempNode = rightNode;
			}
			else
			{
				// go to left
				if (!tempNode->left)
				{
					tempNode->left = newNode;
				}
				tempNode = tempNode->left;

			}
		}
	}
}

bool BST::contains(int value)
{
	Node* tempNode = m_root;

	while (tempNode)
	{
		if (tempNode->m_value == value)
		{
			return true;
		}
		else if(tempNode->m_value > value)
		{
			// go to left
			tempNode = tempNode->left;
		}
		else
		{
			// go to right 
			tempNode = tempNode->right;
		}
	}
	return false;

}



void BST::inOrderRec(Node* node)
{
		if (node != nullptr) {
			inOrderRec(node->left);
			std::cout << node->m_value << " ";
			inOrderRec(node->right);
		}
	
}

Node* BST::getRoot() const
{
	return m_root;
}

void BST::destroyTree(Node* node)
{
	if (node) {
		destroyTree(node->left);  // Recursively delete left subtree
		destroyTree(node->right); // Recursively delete right subtree
		delete node;              // Delete current node
	}
}


