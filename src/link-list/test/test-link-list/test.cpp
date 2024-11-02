#include "gtest/gtest.h"
#include "LinkList.h"

// Test Fixture
class LinkListTest : public ::testing::Test {
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
    TEST_F(LinkListTest, CreateLinkListWithSingleValue) {
        LinkList list(10);
        EXPECT_EQ(list.getLength(), 1);
        EXPECT_EQ(list.getHead()->m_value, 10);
        EXPECT_EQ(list.getTail()->m_value, 10);
    }

    TEST_F(LinkListTest, CheckInitialHeadAndTail) {
        LinkList list(20);
        EXPECT_NE(list.getHead(), nullptr);
        EXPECT_NE(list.getTail(), nullptr);
        EXPECT_EQ(list.getHead(), list.getTail());  // Head and tail should be the same for single node
    }

}

namespace Print
{


    TEST_F(LinkListTest, PrintListSingleElement)
    {
        LinkList list(10);

        EXPECT_EQ(list.printList(), "10");
    }

    TEST_F(LinkListTest, PrintListMultipleElements) {
        // Adding more nodes to the list
        LinkList list(10);

        Node* second = new Node(20);
        Node* third = new Node(30);
        list.getTail()->m_next = second; // Assuming you have a way to access tail
        second->m_next = third;

        // Since we haven't implemented a method to actually add nodes, we will simulate the linking
        EXPECT_EQ(list.printList(), "10,20,30");
    }

}

namespace Append 
{
    TEST_F(LinkListTest, AppendToEmptyList) {
        // Create a new list
        LinkList emptyList;
        emptyList.append(20); // Append to an empty list

        EXPECT_EQ(emptyList.printList(), "20"); // Expect the list to contain the new value
    }

    TEST_F(LinkListTest, AppendMultipleElements) 
    {
        LinkList list(10);

        list.append(20);
        list.append(30);

        EXPECT_EQ(list.printList(), "10,20,30"); // Check that all elements are present in order
    }

    TEST_F(LinkListTest, AppendToSingleElementList) {
        LinkList list(10);

        list.append(20);

        EXPECT_EQ(list.printList(), "10,20"); // Expect the list to contain both values
    }

}
namespace Prepend
{
    TEST_F(LinkListTest, PrependToEmptyList) {
        LinkList emptyList;
        emptyList.prepend(20); // Prepend to an empty list

        EXPECT_EQ(emptyList.printList(), "20"); // Expect the list to contain the new value
    }

    TEST_F(LinkListTest, PrependMultipleElements) 
    {
        LinkList list(10);

        list.prepend(20);
        list.prepend(30);

        EXPECT_EQ(list.printList(), "30,20,10"); // Check that all elements are present in reverse order
    }

    TEST_F(LinkListTest, PrependToSingleElementList) {
        LinkList list(10);

        list.prepend(20);

        EXPECT_EQ(list.printList(), "20,10"); // Expect the list to contain both values in correct order
    }
}

namespace RemoveLast
{
    TEST_F(LinkListTest, RemoveLastFromEmptyList) {
        LinkList emptyList;
        

        EXPECT_THROW(emptyList.removeLast(), std::runtime_error); // Expect the list to be empty
    }

    TEST_F(LinkListTest, RemoveLastFromSingleElementList) {
        LinkList list(10);

        list.removeLast(); // Remove the only element

        EXPECT_EQ(list.printList(), ""); // Expect the list to be empty
        EXPECT_EQ(list.getLength(), 0); // Expect length to be 0
    }

    TEST_F(LinkListTest, RemoveLastFromMultipleElements) {
        LinkList list(10);

        list.append(20);
        list.append(30);
        list.removeLast(); // Remove the last element (30)

        EXPECT_EQ(list.printList(), "10,20"); // Expect list to be "10,20"
        EXPECT_EQ(list.getLength(), 2); // Expect length to be 2
    }

    TEST_F(LinkListTest, RemoveLastUpdatesTail) {
        LinkList list(10);

        list.append(20);
        list.append(30);
        list.removeLast(); // Remove the last element (30)

        EXPECT_EQ(list.printList(), "10,20"); // Check list content
        EXPECT_EQ(list.getTail()->m_value, 20); // Ensure tail is now 20
    }
}
namespace RemoveFirst
{
    TEST_F(LinkListTest, RemoveFirstFromEmptyList) {
        LinkList emptyList;
        
        // Should handle gracefully without error

        EXPECT_THROW(emptyList.removeFirst(), std::runtime_error); // Expect the list to be empty
    }

    TEST_F(LinkListTest, RemoveFirstFromSingleElementList) {
        LinkList list(10);

        list.removeFirst(); // Remove the only element

        EXPECT_EQ(list.printList(), ""); // Expect the list to be empty
        EXPECT_EQ(list.getLength(), 0); // Expect length to be 0
    }

    TEST_F(LinkListTest, RemoveFirstFromMultipleElements) {
        LinkList list(10);

        list.append(20);
        list.append(30);
        list.removeFirst(); // Remove the first element (10)

        EXPECT_EQ(list.printList(), "20,30"); // Expect list to be "20,30"
        EXPECT_EQ(list.getLength(), 2); // Expect length to be 2
    }

    TEST_F(LinkListTest, RemoveFirstUpdatesHead) {
        LinkList list(10);

        list.append(20);
        list.removeFirst(); // Remove the first element (10)

        EXPECT_EQ(list.printList(), "20"); // Check list content
        EXPECT_EQ(list.getHead()->m_value, 20); // Ensure head is now 20
    }
}
namespace Insert
{
    TEST_F(LinkListTest, InsertIntoEmptyList) {
        LinkList emptyList;
        emptyList.insert(20, 0); // Insert at position 0

        EXPECT_EQ(emptyList.printList(), "20"); // Expect the list to contain the new value
    }

    TEST_F(LinkListTest, InsertAtBeginning) {
        LinkList list(10);

        list.insert(20, 0); // Insert at position 0

        EXPECT_EQ(list.printList(), "20,10"); // Check list content
    }

    TEST_F(LinkListTest, InsertAtMiddle) {
        LinkList list(10);

        list.append(20); // Now list is "10,20"
        list.insert(15, 1); // Insert at position 1

        EXPECT_EQ(list.printList(), "10,15,20"); // Check that 15 is inserted in the middle
    }

    TEST_F(LinkListTest, InsertAtEnd) {
        LinkList list(10);

        list.append(20); // Now list is "10,20"
        list.insert(30, 2); // Insert at position 2 (end)

        EXPECT_EQ(list.printList(), "10,20,30"); // Check that 30 is added at the end
    }

    TEST_F(LinkListTest, InsertAtInvalidPosition) {
        LinkList list(10);

        EXPECT_THROW(list.insert(40, 3), std::runtime_error); // Attempt to insert at an invalid position
    }
}

namespace Remove
{
    TEST_F(LinkListTest, RemoveFromEmptyList) {

        LinkList emptyList;
        EXPECT_THROW(emptyList.remove(0), std::runtime_error); // Attempt to remove from an empty list
    }

    TEST_F(LinkListTest, RemoveFirstFromSingleElementList) {
        LinkList list(10);

        list.remove(0); // Remove the only element

        EXPECT_EQ(list.printList(), ""); // Expect the list to be empty
        EXPECT_EQ(list.getLength(), 0); // Expect length to be 0
    }

    TEST_F(LinkListTest, RemoveLastFromMultipleElements) {
        LinkList list(10);
        list.append(20); // Now list is "10,20"
        list.append(30); // Now list is "10,20,30"

        list.remove(2); // Remove the last element (30)

        EXPECT_EQ(list.printList(), "10,20"); // Expect list to be "10,20"
    }

    TEST_F(LinkListTest, RemoveFromMiddle) {
        LinkList list(10);

        list.append(20); // Now list is "10,20"
        list.append(30); // Now list is "10,20,30"

        list.remove(1); // Remove the middle element (20)

        EXPECT_EQ(list.printList(), "10,30"); // Expect list to be "10,30"
    }

    TEST_F(LinkListTest, RemoveAtInvalidPosition) {
        LinkList list(10);

        EXPECT_THROW(list.remove(3), std::runtime_error); // Attempt to remove at an invalid position
    }
}

namespace Reverse
{

    TEST_F(LinkListTest, ReverseEmptyList) 
    {
        LinkList emptyList;

        emptyList.reverse(); // Reverse an empty list
        EXPECT_EQ(emptyList.printList(), ""); // Expect the list to still be empty
    }

    TEST_F(LinkListTest, ReverseSingleElementList) 
    {
        LinkList list(10);
        EXPECT_EQ(list.printList(), "10"); // Expect the list to remain the same
    }

    TEST_F(LinkListTest, ReverseMultipleElements)
    {
        LinkList list(10);

        list.append(20); // Now list is "10,20"
        list.append(30); // Now list is "10,20,30"

        list.reverse(); // Reverse the list

        EXPECT_EQ(list.printList(), "30,20,10"); // Expect list to be "30,20,10"
    }
}

namespace GetAndSet 
{
    TEST_F(LinkListTest, GetValidIndex) {
        LinkList list(10);
        list.append(20);
        list.append(30);
        EXPECT_EQ(list.get(0)->m_value, 10); // Get first element
        EXPECT_EQ(list.get(1)->m_value, 20); // Get second element
        EXPECT_EQ(list.get(2)->m_value, 30); // Get third element
    }

    TEST_F(LinkListTest, GetInvalidIndex) 
    {
        LinkList list(10);
        list.append(20);
        list.append(30);
        EXPECT_EQ(list.get(3), nullptr); // Index out of bounds
        EXPECT_EQ(list.get(100), nullptr); // Large index out of bounds
    }

    TEST_F(LinkListTest, SetValidIndex)
    {
        LinkList list(10);
        list.append(20);
        list.append(30);

        list.set(0, 100); // Set first element to 100
        list.set(1, 200); // Set second element to 200
        list.set(2, 300); // Set third element to 300

        EXPECT_EQ(list.get(0)->m_value, 100); // Verify first element
        EXPECT_EQ(list.get(1)->m_value, 200); // Verify second element
        EXPECT_EQ(list.get(2)->m_value, 300); // Verify third element
    }

    TEST_F(LinkListTest, SetInvalidIndex)
    {
        LinkList list(10);
        list.append(20);
        list.append(30);

        EXPECT_THROW(list.set(3, 400), std::runtime_error); // Attempt to set at an out-of-bounds index
        EXPECT_THROW(list.set(100, 500), std::runtime_error); // Large index out of bounds
        EXPECT_EQ(list.get(0)->m_value, 10); // Ensure the first element remains unchanged
    }
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}