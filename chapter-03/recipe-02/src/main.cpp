#include <gtest/gtest.h>
#include "FooEnvironment.h"

int main (int argc, char* argv[])  
{  
    testing::AddGlobalTestEnvironment(new FooEnvironment);
    testing::InitGoogleTest(&argc, argv);  
    return RUN_ALL_TESTS();  
}  
  
