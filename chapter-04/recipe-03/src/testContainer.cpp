// Test.cpp

#include <gtest/gtest.h>
#include "VectorContainer.h"
#include "ListContainer.h"

template <typename T>
class ContainerTest: public ::testing::Test { };
//TYPED_TEST_CASE_P(ContainerTest);
TYPED_TEST_SUITE_P(ContainerTest);

TYPED_TEST_P(ContainerTest, ShouldBeEmptyOnStartup) {
    TypeParam container;
    ASSERT_EQ(container.count(), 0);
}

TYPED_TEST_P(ContainerTest, ShouldAdd1) {
    TypeParam container;
    container.add(1);
    ASSERT_EQ(container.count(), 1);
}

TYPED_TEST_P(ContainerTest, ShouldIterate) {
    TypeParam container;
    container.add(1);
    container.add(2);
    container.add(3);

    std::vector<size_t> verification;
    auto proc = [& verification, & container] (const size_t item) -> void {
        verification.push_back(item);
    };

    container.forEach(proc);

    ASSERT_EQ(verification.size(), 3);
    ASSERT_EQ(verification[0], 1);
    ASSERT_EQ(verification[1], 2);
    ASSERT_EQ(verification[2], 3);
}

//REGISTER_TYPED_TEST_CASE_P(ContainerTest,
REGISTER_TYPED_TEST_SUITE_P(ContainerTest,
    ShouldBeEmptyOnStartup,
    ShouldAdd1,
    ShouldIterate
);

typedef ::testing::Types<VectorContainer, ListContainer> ContainerTypes;
//INSTANTIATE_TYPED_TEST_CASE_P(ContainerTypesInstantiation, ContainerTest, ContainerTypes);
INSTANTIATE_TYPED_TEST_SUITE_P(ContainerTypesInstantiation, ContainerTest, ContainerTypes);

