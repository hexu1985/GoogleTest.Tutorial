#include <gtest/gtest.h>
#include <string>

TEST(StringCmpTest, Demo)
{
    char* pszCoderZh = "CoderZh";

    EXPECT_STREQ("CoderZh", pszCoderZh);
    EXPECT_STRNE("CnBlogs", pszCoderZh);
    EXPECT_STRCASEEQ("coderzh", pszCoderZh);
    EXPECT_STREQ("coderzh", pszCoderZh);
}
