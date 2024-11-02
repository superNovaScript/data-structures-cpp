#include "gtest/gtest.h"
#include "BST.h"

namespace Constructor
{
    // Unit test for the BST constructor
    TEST(BSTTest, ConstructorInitializesRoot) {
        // Arrange
        int initialValue = 10;

        // Act
        BST bst(initialValue);

        // Assert
        EXPECT_NE(bst.getRoot(), nullptr);               // Check that the root is not null
        EXPECT_EQ(bst.getRoot()->m_value, initialValue);  // Check that the root's value is as expected
        EXPECT_EQ(bst.getRoot()->left, nullptr);         // Check that the left child is null
        EXPECT_EQ(bst.getRoot()->right, nullptr);        // Check that the right child is null
    }
}
namespace Insert
{
    // Unit test for the BST insert method
    TEST(BSTTest, InsertMethod) {
        // Arrange
        BST bst;

        // Act
        bst.insert(10); // Insert root
        bst.insert(5);  // Insert left child
        bst.insert(15); // Insert right child
        bst.insert(10); // Try inserting duplicate

        // Assert
        EXPECT_NE(bst.getRoot(), nullptr);
        EXPECT_EQ(bst.getRoot()->m_value, 10);
        EXPECT_NE(bst.getRoot()->left, nullptr);
        EXPECT_EQ(bst.getRoot()->left->m_value, 5);
        EXPECT_NE(bst.getRoot()->right, nullptr);
        EXPECT_EQ(bst.getRoot()->right->m_value, 15);

        // Ensure the duplicate is not added
        EXPECT_EQ(bst.getRoot()->left->m_value, 5);
        EXPECT_EQ(bst.getRoot()->right->m_value, 15);
        EXPECT_EQ(bst.getRoot()->m_value, 10);
    }
}

namespace Contains
{
    // Unit test for the BST contains method
    TEST(BSTTest, ContainsMethod) {
        // Arrange
        BST bst;
        bst.insert(10);
        bst.insert(5);
        bst.insert(15);
        bst.insert(7);

        // Act & Assert
        EXPECT_TRUE(bst.contains(10)); // Check if root is found
        EXPECT_TRUE(bst.contains(5));  // Check if left child is found
        EXPECT_TRUE(bst.contains(15)); // Check if right child is found
        EXPECT_TRUE(bst.contains(7));  // Check if a leaf node is found
        EXPECT_FALSE(bst.contains(1));  // Check if a non-existent value is found
        EXPECT_FALSE(bst.contains(20)); // Check if a non-existent value is found
    }
}

// Main function to run tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}