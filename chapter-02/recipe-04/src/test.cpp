#include <gtest/gtest.h>

TEST(ExplicitTest, Demo)
{
    ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。

    std::cout << "after ADD_FAILURE" <<  std::endl;

    // FAIL(); // Fatal Assertion，不往下执行该test case。

    ADD_FAILURE_AT("test_file.cpp", 19) << "Sorry again"; // None Fatal Asserton，继续往下执行。

    SUCCEED();

    std::cout << "after SUCCEED" <<  std::endl;
}
