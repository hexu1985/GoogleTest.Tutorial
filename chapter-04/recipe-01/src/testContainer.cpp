// Test.cpp

#include <gtest/gtest.h>
#include "VectorContainer.h"
#include "ListContainer.h"

TEST(VectorContainerTest, ShouldBeEmptyOnStartup) {
    VectorContainer container;
    ASSERT_EQ(container.count(), 0);
}

TEST(VectorContainerTest, ShouldAdd1) {
    VectorContainer container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}

TEST(ListContainerTest, ShouldBeEmptyOnStartup) {
    ListContainer container;
    ASSERT_EQ(container.count(), 0);
}

TEST(ListContainerTest, ShouldAdd1) {
    ListContainer container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}
