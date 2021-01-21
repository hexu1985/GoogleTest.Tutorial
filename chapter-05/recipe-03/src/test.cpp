#include <gtest/gtest.h>
#include <stdlib.h>
#include <iostream>

void Foo() {
	std::cout << "Fail Foo\n";
	std::cerr << "Fail Foo\n";  // for EXPECT_EXIT regular expression
	exit(0);
}
 
TEST(MyDeathTest, Foo) {
    EXPECT_EXIT(Foo(), ::testing::ExitedWithCode(0), ".*Foo");
}
