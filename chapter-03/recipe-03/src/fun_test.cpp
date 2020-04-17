#include <stdint.h>
#include <gtest/gtest.h>
#include "fun.h"

#define INT_MIN INT32_MIN

/*-------------------------------------------TEST macro-----------------------*/  
//Sample 1: This sample shows how to write a simple unit test for a function,  
// using Google C++ testing framework.  
//  
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:  
// Step 1. Include necessary header files such that the stuff your  
// test logic needs is declared.  
// Step 2. Use the TEST macro to define your tests.  
// Step 3. Call RUN_ALL_TESTS() in main().  
  
// TEST has two parameters: the test case name and the test name.  
// After using the macro, you should define your test logic between a  
// pair of braces.  You can use a bunch of macros to indicate the  
// success or failure of a test.  
// The test case name and the test name should both be valid C++  
// identifiers.  And you should not use underscore (_) in the names.  
  
// Tests Factorial().  
// Tests factorial of negative numbers.  
TEST(FactorialTest, Negative) {  
    // This test is named "Negative", and belongs to the "FactorialTest"  
    // test case.  
    EXPECT_EQ(1, Factorial(-5));  
    EXPECT_EQ(1, Factorial(-1));  
    EXPECT_GT(Factorial(-10), 0);  
  
    // EXPECT_EQ(expected, actual) is the same as  
    //  
    // EXPECT_TRUE((expected) == (actual))  
    //  
    // except that it will print both the expected value and the actual  
    // value when the assertion fails.  This is very helpful for  
    // debugging.  Therefore in this case EXPECT_EQ is preferred.  
    //  
    // On the other hand, EXPECT_TRUE accepts any Boolean expression,  
    // and is thus more general.  
}  
  
// Tests factorial of 0.  
TEST(FactorialTest, Zero) {  
    EXPECT_EQ(1, Factorial(0));  
}  
  
// Tests factorial of positive numbers.  
TEST(FactorialTest, Positive) {  
    EXPECT_EQ(1, Factorial(1));  
    EXPECT_EQ(2, Factorial(2));  
    EXPECT_EQ(6, Factorial(3));  
    EXPECT_EQ(40320, Factorial(8));  
}  
  
// Tests IsPrime()  
// Tests negative input.  
TEST(IsPrimeTest, Negative) {  
    // This test belongs to the IsPrimeTest test case.  
  
    EXPECT_FALSE(IsPrime(-1));  
    EXPECT_FALSE(IsPrime(-2));  
    EXPECT_FALSE(IsPrime(INT_MIN));  
}  
  
// Tests some trivial cases.  
TEST(IsPrimeTest, Trivial) {  
    EXPECT_FALSE(IsPrime(0));  
    EXPECT_FALSE(IsPrime(1));  
    EXPECT_TRUE(IsPrime(2));  
    EXPECT_TRUE(IsPrime(3));  
}  
  
// Tests positive input.  
TEST(IsPrimeTest, Positive) {  
    EXPECT_FALSE(IsPrime(4));  
    EXPECT_TRUE(IsPrime(5));  
    EXPECT_FALSE(IsPrime(6));  
    EXPECT_TRUE(IsPrime(23));  
}  
