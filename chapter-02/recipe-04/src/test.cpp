#include <gtest/gtest.h>

TEST(ExplicitTest, Demo)
{
    ADD_FAILURE() << "Sorry"; // None Fatal Asserton，继续往下执行。

    // FAIL(); // Fatal Assertion，不往下执行该案例。

    SUCCEED();
}
