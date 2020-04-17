#include <gtest/gtest.h>
#include "MyString.h"

//Sample 2: This sample shows how to write a more complex unit test for a class  
// that has multiple member functions.  
//  
// Usually, it's a good idea to have one test for each method in your  
// class.  You don't have to do that exactly, but it helps to keep  
// your tests organized.  You may also throw in additional tests as  
// needed.  
  
// Tests the default c'tor.  
TEST(MyString, DefaultConstructor) {  
    const MyString s;  
  
    // Asserts that s.c_string() returns NULL.  
    //  
    // If we write NULL instead of  
    //  
    //   static_cast<const char *>(NULL)  
    //  
    // in this assertion, it will generate a warning on gcc 3.4.  The  
    // reason is that EXPECT_EQ needs to know the types of its  
    // arguments in order to print them when it fails.  Since NULL is  
    // #defined as 0, the compiler will use the formatter function for  
    // int to print it.  However, gcc thinks that NULL should be used as  
    // a pointer, not an int, and therefore complains.  
    //  
    // The root of the problem is C++'s lack of distinction between the  
    // integer number 0 and the null pointer constant.  Unfortunately,  
    // we have to live with this fact.  
    EXPECT_STREQ(NULL, s.c_string());  
  
    EXPECT_EQ(0u, s.Length());  
}  
  
const char kHelloString[] = "Hello, world!";  
  
// Tests the c'tor that accepts a C string.  
TEST(MyString, ConstructorFromCString) {  
    const MyString s(kHelloString);  
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));  
    EXPECT_EQ(sizeof(kHelloString)/sizeof(kHelloString[0]) - 1,  
        s.Length());  
}  
  
// Tests the copy c'tor.  
TEST(MyString, CopyConstructor) {  
    const MyString s1(kHelloString);  
    const MyString s2 = s1;  
    EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));  
}  
  
// Tests the Set method.  
TEST(MyString, Set) {  
    MyString s;  
  
    s.Set(kHelloString);  
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));  
  
    // Set should work when the input pointer is the same as the one  
    // already in the MyString object.  
    s.Set(s.c_string());  
    EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));  
  
    // Can we set the MyString to NULL?  
    s.Set(NULL);  
    EXPECT_STREQ(NULL, s.c_string());  
}  
