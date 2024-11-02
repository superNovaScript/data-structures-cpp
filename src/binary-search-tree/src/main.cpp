// binary-search-tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BST.h"
int main()
{
    BST binarySearchTree(5);
    binarySearchTree.insert(5);
    binarySearchTree.insert(3);
    binarySearchTree.insert(7);
    binarySearchTree.insert(2);
    binarySearchTree.insert(4);
    binarySearchTree.insert(6);
    binarySearchTree.insert(6);
    binarySearchTree.insert(8);

    std::cout << "In-order traversal of the BST: ";
    binarySearchTree.printInOrder();

    std::cout << "BST contains 0: " << (binarySearchTree.contains(0) ? "evet" : "hayýr") << std::endl;

}

