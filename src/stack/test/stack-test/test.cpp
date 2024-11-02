#include "gtest/gtest.h"
#include "Stack.h"

namespace Constuctor
{
    // Unit tests for Stack constructor
    TEST(StackTest, ConstructorInitializesStackWithSingleValue) {
        Stack stack(10);

        // Check that the height is set correctly
        EXPECT_EQ(stack.getHeight(), 1);

        // Check that the top value is correct
        EXPECT_EQ(stack.pop(), 10);

        // Check that the stack is empty after popping
        EXPECT_THROW(stack.pop(), std::runtime_error);
    }

    TEST(StackTest, ConstructorSetsTopAndBottomToSameNode) {
        Stack stack(20);

        // Check that top and bottom are the same
        EXPECT_EQ(stack.getHeight(), 1);

        // Ensure popping returns the correct value
        EXPECT_EQ(stack.pop(), 20);
        EXPECT_THROW(stack.pop(), std::runtime_error); // Stack should be empty now
    }

    TEST(StackTest, ConstructorHandlesDifferentInitialValues) {
        Stack stack1(30);
        Stack stack2(40);

        // Check initial height and values
        EXPECT_EQ(stack1.getHeight(), 1);
        EXPECT_EQ(stack1.pop(), 30);
        EXPECT_THROW(stack1.pop(), std::runtime_error); // Should be empty

        EXPECT_EQ(stack2.getHeight(), 1);
        EXPECT_EQ(stack2.pop(), 40);
        EXPECT_THROW(stack2.pop(), std::runtime_error); // Should be empty
    }

    // Unit tests for Stack default constructor
    TEST(StackTest, DefaultConstructorInitializesEmptyStack) {
        Stack stack;

        // Check that the stack is initialized as empty
        EXPECT_EQ(stack.getHeight(), 0);
    }

    TEST(StackTest, PopFromEmptyStackThrowsException) {
        Stack stack;

        // Check that popping from an empty stack throws an exception
        EXPECT_THROW(stack.pop(), std::runtime_error);
    }

    TEST(StackTest, PushAfterDefaultConstructorIncreasesHeight) {
        Stack stack;

        // Initially empty
        EXPECT_EQ(stack.getHeight(), 0);

        // Push a value
        stack.push(10);
        EXPECT_EQ(stack.getHeight(), 1);
        EXPECT_EQ(stack.pop(), 10); // Check value
    }
}
namespace Pop
{
    // Unit tests for Stack
    TEST(StackTest, PopFromEmptyStackThrowsException) {
        Stack stack;
        EXPECT_THROW(stack.pop(), std::runtime_error);
    }

    TEST(StackTest, PopReturnsCorrectValue) {
        Stack stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        EXPECT_EQ(stack.pop(), 30);
        EXPECT_EQ(stack.pop(), 20);
        EXPECT_EQ(stack.pop(), 10);
    }

    TEST(StackTest, PopDecreasesStackHeight) {
        Stack stack;
        stack.push(10);
        stack.push(20);
        stack.push(30);

        EXPECT_EQ(stack.getHeight(), 3);
        stack.pop();
        EXPECT_EQ(stack.getHeight(), 2);
        stack.pop();
        EXPECT_EQ(stack.getHeight(), 1);
        stack.pop();
        EXPECT_EQ(stack.getHeight(), 0);
    }

    TEST(StackTest, MultiplePopsFromNonEmptyStack) {
        Stack stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);

        EXPECT_EQ(stack.pop(), 3);
        EXPECT_EQ(stack.pop(), 2);
        EXPECT_EQ(stack.pop(), 1);
    }

}

namespace Push {
    // Unit tests for Stack
    TEST(StackTest, PushIncreasesStackHeight) {
        Stack stack;
        EXPECT_EQ(stack.getHeight(), 0);

        stack.push(10);
        EXPECT_EQ(stack.getHeight(), 1);

        stack.push(20);
        EXPECT_EQ(stack.getHeight(), 2);

        stack.push(30);
        EXPECT_EQ(stack.getHeight(), 3);
    }

    TEST(StackTest, PushStoresValuesInCorrectOrder) {
        Stack stack;

        stack.push(10);
        stack.push(20);
        stack.push(30);

        // Check that popping returns the values in LIFO order
        EXPECT_EQ(stack.pop(), 30);
        EXPECT_EQ(stack.pop(), 20);
        EXPECT_EQ(stack.pop(), 10);
    }

    TEST(StackTest, PushWhenEmptySetsTopAndBottom) {
        Stack stack;

        stack.push(10);
        EXPECT_EQ(stack.getHeight(), 1);
        EXPECT_EQ(stack.pop(), 10); // Check value

        stack.push(20);
        EXPECT_EQ(stack.getHeight(), 1);
        EXPECT_EQ(stack.pop(), 20); // Check value
    }

    TEST(StackTest, PushHandlesMultipleValues) {
        Stack stack;

        for (int i = 1; i <= 5; ++i) {
            stack.push(i);
        }

        EXPECT_EQ(stack.getHeight(), 5);

        // Check that popping returns the values in LIFO order
        for (int i = 5; i >= 1; --i) {
            EXPECT_EQ(stack.pop(), i);
        }
    }
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}