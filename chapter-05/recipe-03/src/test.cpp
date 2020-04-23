#include <gtest/gtest.h>
#include <stdlib.h>
#include <iostream>

void Foo() {
	std::cerr << "Fail Foo\n";
	exit(0);
}
 
TEST(MyDeathTest, Foo) {
    EXPECT_EXIT(Foo(), ::testing::ExitedWithCode(0), ".*Foo");
}
