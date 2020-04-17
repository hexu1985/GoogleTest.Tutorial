#ifndef FOO_ENVIRONMENT_INC 
#define FOO_ENVIRONMENT_INC 

#include <gtest/gtest.h>

class FooEnvironment : public testing::Environment {
public:
    virtual void SetUp()
    {
        std::cout << "Foo FooEnvironment SetUP" << std::endl;
    }
    virtual void TearDown()
    {
        std::cout << "Foo FooEnvironment TearDown" << std::endl;
    }
};

#endif
