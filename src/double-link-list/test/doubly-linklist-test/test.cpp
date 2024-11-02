#include "gtest/gtest.h"
#include "DoublelyLinkList.h"


// Test Fixture
class DoublelyLinkListTest : public ::testing::Test 
{

protected:
    void SetUp() override {
        // Optional: Code to run before each test, if needed
    }

    void TearDown() override {
        // Optional: Code to run after each test, if needed
    }
};

namespace Constructor
{
    // Test cases
    TEST_F(DoublelyLinkListTest, CreateLinkListWithSingleValue) {
        
        DoubleLinkList list(10);
        EXPECT_EQ(list.getLength(), 1);
        EXPECT_EQ(list.getHead()->m_value, 10);
        EXPECT_EQ(list.getTail()->m_value, 10);
    }

    TEST_F(DoublelyLinkListTest, CheckInitialHeadAndTail) {
        
        DoubleLinkList list(20);
        EXPECT_NE(list.getHead(), nullptr);
        EXPECT_NE(list.getTail(), nullptr);
        EXPECT_EQ(list.getHead(), list.getTail());  // Head and tail should be the same for single node
    }

}

namespace Append {

    TEST_F(DoublelyLinkListTest, AppendIncreasesLengthAndUpdatesTail)
    {
        DoubleLinkList list;

        // Initially, the length should be 0
        EXPECT_EQ(list.getLength(), 0);
        EXPECT_EQ(list.getTail(), nullptr);

        // Append a value
        list.append(10);

         //Check the new length
        EXPECT_EQ(list.getLength(), 1);

        // Check that the tail is now the new node with value 10
        EXPECT_NE(list.getTail(), nullptr);
        EXPECT_EQ(list.getTail()->m_value, 10);
        EXPECT_EQ(list.getTail()->prev, nullptr); // First element, prev should be nullptr
        EXPECT_EQ(list.getTail()->next, nullptr); // First element, next should be nullptr

        // Append another value
        list.append(20);

        // Check the new length
        EXPECT_EQ(list.getLength(), 2);

        // Check that the tail is now the new node with value 20
        EXPECT_NE(list.getTail(), nullptr);
        EXPECT_EQ(list.getTail()->m_value, 20);
        EXPECT_NE(list.getTail()->prev, nullptr); // Should point to the node with value 10
        EXPECT_EQ(list.getTail()->prev->m_value, 10);
        EXPECT_EQ(list.getTail()->next, nullptr); // Last element, next should be nullptr
    }

}

namespace Prepend
{
    TEST_F(DoublelyLinkListTest, PrependToEmptyList) {
        DoubleLinkList list;

        // Prepend an element to an empty list
        list.prepend(10);

        // Check if head and tail point to the same node
        ASSERT_EQ(list.getHead()->m_value, 10);
        ASSERT_EQ(list.getTail()->m_value, 10);
        ASSERT_EQ(list.getLength(), 1);
    }

    TEST_F(DoublelyLinkListTest, PrependToNonEmptyList) {
        DoubleLinkList list;

        list.prepend(20); // Prepend first
        list.prepend(10); // Now prepend another

        // Check the new head and old head
        ASSERT_EQ(list.getHead()->m_value, 10); // New head should be 10
        ASSERT_EQ(list.getTail()->m_value, 20); // Tail should still be 20
        ASSERT_EQ(list.getLength(), 2);

        // Check if links are correct
        ASSERT_EQ(list.getHead()->next->m_value, 20); // Head's next should point to 20
        ASSERT_EQ(list.getTail()->prev->m_value, 10); // Tail's prev should point back to 10
    }

    TEST_F(DoublelyLinkListTest, PrependMultipleValues) {
        DoubleLinkList list;

        list.prepend(30);
        list.prepend(20);
        list.prepend(10);

        ASSERT_EQ(list.getHead()->m_value, 10);
        ASSERT_EQ(list.getTail()->m_value, 30);
        ASSERT_EQ(list.getLength(), 3);
        ASSERT_EQ(list.getHead()->next->m_value, 20);
        ASSERT_EQ(list.getHead()->next->next->m_value, 30);
    }

    TEST_F(DoublelyLinkListTest, PrependNullValue) {
        DoubleLinkList list;

        // Assuming your Node class allows null or zero as a valid value
        list.prepend(0);
        ASSERT_EQ(list.getHead()->m_value, 0);
        ASSERT_EQ(list.getLength(), 1);
    }
}
namespace Insert 
{

    TEST_F(DoublelyLinkListTest, InsertAtInvalidPositionNegative) {
        DoubleLinkList list;

        ASSERT_THROW(list.insert(-1, 10), std::runtime_error);
    }

    TEST_F(DoublelyLinkListTest, InsertAtInvalidPositionGreaterThanLength) {
        DoubleLinkList list;

        list.prepend(20);
        ASSERT_THROW(list.insert(2, 30), std::runtime_error); // Length is 1, can't insert at pos 2
    }

    TEST_F(DoublelyLinkListTest, InsertAtBeginning) {
        DoubleLinkList list;

        list.prepend(20); // Start with one element
        list.insert(0, 10); // Insert at the beginning

        ASSERT_EQ(list.getHead()->m_value, 10); // New head should be 10
        ASSERT_EQ(list.getLength(), 2); // Length should be 2
        ASSERT_EQ(list.getHead()->next->m_value, 20); // Head's next should be 20
    }

    TEST_F(DoublelyLinkListTest, InsertAtEnd) {
        DoubleLinkList list;

        list.prepend(20); // Start with one element
        list.insert(1, 30); // Insert at the end

        ASSERT_EQ(list.getTail()->m_value, 30); // Tail should be 30
        ASSERT_EQ(list.getLength(), 2); // Length should be 2
        ASSERT_EQ(list.getHead()->next->m_value, 30); 
    }

    TEST_F(DoublelyLinkListTest, InsertInMiddle) {
        DoubleLinkList list;

        list.prepend(30); // List: 30
        list.prepend(20); // List: 20 <-> 30
        list.insert(1, 10); // Insert at position 1 (middle)

        ASSERT_EQ(list.getHead()->next->m_value, 10); // Second element should be 10
        ASSERT_EQ(list.getLength(), 3); // Length should be 3
        ASSERT_EQ(list.getHead()->next->next->m_value, 30); // Next to 10 should be 30
    }

    TEST_F(DoublelyLinkListTest, InsertAtSecondToLastPosition) {
        DoubleLinkList list;

        list.prepend(30); // List: 30
        list.prepend(20); // List: 20 <-> 30
        list.insert(1, 10); // Insert at position 1 (middle) 20-10-30

        list.insert(2, 25); // Insert at second to last position  20-10-25-30

        ASSERT_EQ(list.getTail()->m_value, 30); // Tail should still be 30
        ASSERT_EQ(list.getHead()->next->next->m_value, 25); // Third element should still be 30
        ASSERT_EQ(list.getHead()->next->m_value, 10); // Second element should still be 10
        ASSERT_EQ(list.getHead()->next->next->m_value, 25); // Third element should now be 25
        ASSERT_EQ(list.getLength(), 4); // Length should be 4
    }
}

namespace RemoveFirst
{
    TEST_F(DoublelyLinkListTest, RemoveFromEmptyListThrowsException) {
        DoubleLinkList list;

        EXPECT_THROW(list.removeFirst(), std::runtime_error);
    }

    TEST_F(DoublelyLinkListTest, RemoveLastElementUpdatesHeadAndTail) {
        DoubleLinkList list;

        // Setup: add one element to the list
        list.append(10);  // Assuming add method exists
        list.removeFirst();

        // Test: head and tail should both be nullptr
        EXPECT_EQ(list.getHead(), nullptr);  // Assuming getHead method exists
        EXPECT_EQ(list.getTail(), nullptr);  // Assuming getTail method exists
    }

    TEST_F(DoublelyLinkListTest, RemoveFirstElementUpdatesHeadCorrectly) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);  // Assuming add method exists
        list.append(20);
        list.append(30);

        // Initial state
        EXPECT_EQ(list.getHead()->m_value, 10);  // Assuming Node has data member
        EXPECT_EQ(list.getTail()->m_value, 30);

        // Remove first element
        list.removeFirst();

        // Test: head should now be the second element
        EXPECT_EQ(list.getHead()->m_value, 20);
        EXPECT_EQ(list.getTail()->m_value, 30);
        EXPECT_EQ(list.getLength(), 2);  // Assuming getLength method exists
    }

    TEST_F(DoublelyLinkListTest, RemoveFirstElementDecreasesLength) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);
        list.append(20);
        list.append(30);

        EXPECT_EQ(list.getLength(), 3);
        list.removeFirst();
        EXPECT_EQ(list.getLength(), 2);
    }
}

namespace RemoveLast
{
    TEST_F(DoublelyLinkListTest, RemoveFromEmptyListThrowsException) {
        DoubleLinkList list;

        EXPECT_THROW(list.removeLast(), std::runtime_error);
    }

    TEST_F(DoublelyLinkListTest, RemoveLastElementUpdatesHeadAndTail) {
        DoubleLinkList list;

        // Setup: add one element to the list
        list.append(10);  // Assuming add method exists
        list.removeLast();

        // Test: head and tail should both be nullptr
        EXPECT_EQ(list.getHead(), nullptr);  // Assuming getHead method exists
        EXPECT_EQ(list.getTail(), nullptr);  // Assuming getTail method exists
    }

    TEST_F(DoublelyLinkListTest, RemoveLastElementUpdatesTailCorrectly) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);  // Assuming add method exists
        list.append(20);
        list.append(30);

        // Initial state
        EXPECT_EQ(list.getHead()->m_value, 10);  // Assuming Node has data member
        EXPECT_EQ(list.getTail()->m_value, 30);

        // Remove last element
        list.removeLast();

        // Test: tail should now be the second element
        EXPECT_EQ(list.getHead()->m_value, 10);
        EXPECT_EQ(list.getTail()->m_value, 20);
        EXPECT_EQ(list.getLength(), 2);  // Assuming getLength method exists
    }

    TEST_F(DoublelyLinkListTest, RemoveLastElementDecreasesLength) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);
        list.append(20);
        list.append(30);

        EXPECT_EQ(list.getLength(), 3);
        list.removeLast();
        EXPECT_EQ(list.getLength(), 2);
    }

}

namespace Remove {


    TEST_F(DoublelyLinkListTest, RemoveFirstElement) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);
        list.append(20);
        list.append(30);

        // Initial state
        EXPECT_EQ(list.getHead()->m_value, 10);
        EXPECT_EQ(list.getLength(), 3);

        // Remove the first element
        list.remove(0);

        // Test: head should now be the second element
        EXPECT_EQ(list.getHead()->m_value, 20);
        EXPECT_EQ(list.getLength(), 2);
    }

    TEST_F(DoublelyLinkListTest, RemoveFromEmptyListThrowsException)
    {
        DoubleLinkList list;

        EXPECT_THROW(list.remove(0), std::runtime_error);
    }

    TEST_F(DoublelyLinkListTest, RemoveLastElement) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);
        list.append(20);
        list.append(30);

        // Initial state
        EXPECT_EQ(list.getTail()->m_value, 30);
        EXPECT_EQ(list.getLength(), 3);

        // Remove the last element
        list.remove(2);

        // Test: tail should now be the second element
        EXPECT_EQ(list.getTail()->m_value, 20);
        EXPECT_EQ(list.getLength(), 2);
    }

    TEST_F(DoublelyLinkListTest, RemoveMiddleElement) {
        DoubleLinkList list;

        // Setup: add multiple elements to the list
        list.append(10);
        list.append(20);
        list.append(30);
        list.append(40);

        // Initial state
        EXPECT_EQ(list.getLength(), 4);

        // Remove the second element (index 1)
        list.remove(1);

        // Test: the list should be 10, 30, 40
        EXPECT_EQ(list.getHead()->m_value, 10);
        EXPECT_EQ(list.getHead()->next->m_value, 30);
        EXPECT_EQ(list.getLength(), 3);
    }

    TEST_F(DoublelyLinkListTest, RemoveOutOfBoundsThrowsException) {
        DoubleLinkList list;

        // Setup: add elements to the list
        list.append(10);
        list.append(20);

        // Test: remove at an invalid index
        EXPECT_THROW(list.remove(2), std::runtime_error);  // Index 2 is out of bounds
        EXPECT_THROW(list.remove(3), std::runtime_error);  // Index 3 is out of bounds
    }
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}