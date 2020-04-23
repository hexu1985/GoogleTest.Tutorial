#include <gtest/gtest.h>
#include "fun.h"  
  
#define BRANCH_1 //BRANCH_1 //BRANCH_2 //BRANCH_3  
  
#if defined  BRANCH_1  
  
#include <stdint.h>

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
  
//Sample 4: another basic example of using Google Test  
// Tests the Increment() method.  
TEST(Counter, Increment) {  
    Counter c;  
  
    // EXPECT_EQ() evaluates its arguments exactly once, so they  
    // can have side effects.  
  
    EXPECT_EQ(0, c.Increment());  
    EXPECT_EQ(1, c.Increment());  
    EXPECT_EQ(2, c.Increment());  
}  
  
/*------------------------------------TEST_F macro------------------------------------*/  
//Sample 3: In this example, we use a more advanced feature of Google Test called  
// test fixture.  
//  
// A test fixture is a place to hold objects and functions shared by  
// all tests in a test case.  Using a test fixture avoids duplicating  
// the test code necessary to initialize and cleanup those common  
// objects for each test.  It is also useful for defining sub-routines  
// that your tests need to invoke a lot.  
//  
// The tests share the test fixture in the sense of code sharing, not  
// data sharing.  Each test is given its own fresh copy of the  
// fixture.  You cannot expect the data modified by one test to be  
// passed on to another test, which is a bad idea.  
//  
// The reason for this design is that tests should be independent and  
// repeatable.  In particular, a test should not fail as the result of  
// another test's failure.  If one test depends on info produced by  
// another test, then the two tests should really be one big test.  
//  
// The macros for indicating the success/failure of a test  
// (EXPECT_TRUE, FAIL, etc) need to know what the current test is  
// (when Google Test prints the test result, it tells you which test  
// each failure belongs to).  Technically, these macros invoke a  
// member function of the Test class.  Therefore, you cannot use them  
// in a global function.  That's why you should put test sub-routines  
// in a test fixture.  
  
// To use a test fixture, derive a class from testing::Test.  
class QueueTest : public testing::Test {  
protected:  // You should make the members protected s.t. they can be  
    // accessed from sub-classes.  
  
    // virtual void SetUp() will be called before each test is run.  You  
    // should define it if you need to initialize the varaibles.  
    // Otherwise, this can be skipped.  
    virtual void SetUp() {  
        q1_.Enqueue(1);  
        q2_.Enqueue(2);  
        q2_.Enqueue(3);  
    }  
  
    // virtual void TearDown() will be called after each test is run.  
    // You should define it if there is cleanup work to do.  Otherwise,  
    // you don't have to provide it.  
    //  
    // virtual void TearDown() {  
    // }  
  
    // A helper function that some test uses.  
    static int Double(int n) {  
        return 2*n;  
    }  
  
    // A helper function for testing Queue::Map().  
    void MapTester(const Queue<int> * q) {  
        // Creates a new queue, where each element is twice as big as the  
        // corresponding one in q.  
        const Queue<int> * const new_q = q->Map(Double);  
  
        // Verifies that the new queue has the same size as q.  
        ASSERT_EQ(q->Size(), new_q->Size());  
  
        // Verifies the relationship between the elements of the two queues.  
        for ( const QueueNode<int> * n1 = q->Head(), * n2 = new_q->Head();  
            n1 != NULL; n1 = n1->next(), n2 = n2->next() ) {  
                EXPECT_EQ(2 * n1->element(), n2->element());  
        }  
  
        delete new_q;  
    }  
  
    // Declares the variables your tests want to use.  
    Queue<int> q0_;  
    Queue<int> q1_;  
    Queue<int> q2_;  
};  
  
// When you have a test fixture, you define a test using TEST_F  
// instead of TEST.  
// Tests the default c'tor.  
TEST_F(QueueTest, DefaultConstructor) {  
    // You can access data in the test fixture here.  
    EXPECT_EQ(0u, q0_.Size());  
}  
  
// Tests Dequeue().  
TEST_F(QueueTest, Dequeue) {  
    int * n = q0_.Dequeue();  
    EXPECT_TRUE(n == NULL);  
  
    n = q1_.Dequeue();  
    ASSERT_TRUE(n != NULL);  
    EXPECT_EQ(1, *n);  
    EXPECT_EQ(0u, q1_.Size());  
    delete n;  
  
    n = q2_.Dequeue();  
    ASSERT_TRUE(n != NULL);  
    EXPECT_EQ(2, *n);  
    EXPECT_EQ(1u, q2_.Size());  
    delete n;  
}  
  
// Tests the Queue::Map() function.  
TEST_F(QueueTest, Map) {  
    MapTester(&q0_);  
    MapTester(&q1_);  
    MapTester(&q2_);  
}  
  
// Sample 5: This sample teaches how to reuse a test fixture in multiple test  
// cases by deriving sub-fixtures from it.  
//  
// When you define a test fixture, you specify the name of the test  
// case that will use this fixture.  Therefore, a test fixture can  
// be used by only one test case.  
//  
// Sometimes, more than one test cases may want to use the same or  
// slightly different test fixtures.  For example, you may want to  
// make sure that all tests for a GUI library don't leak important  
// system resources like fonts and brushes.  In Google Test, you do  
// this by putting the shared logic in a super (as in "super class")  
// test fixture, and then have each test case use a fixture derived  
// from this super fixture.  
  
// In this sample, we want to ensure that every test finishes within  
// ~5 seconds.  If a test takes longer to run, we consider it a  
// failure.  
//  
// We put the code for timing a test in a test fixture called  
// "QuickTest".  QuickTest is intended to be the super fixture that  
// other fixtures derive from, therefore there is no test case with  
// the name "QuickTest".  This is OK.  
//  
// Later, we will derive multiple test fixtures from QuickTest.  
class QuickTest : public testing::Test {  
protected:  
    // Remember that SetUp() is run immediately before a test starts.  
    // This is a good place to record the start time.  
    virtual void SetUp() {  
        start_time_ = time(NULL);  
    }  
  
    // TearDown() is invoked immediately after a test finishes.  Here we  
    // check if the test was too slow.  
    virtual void TearDown() {  
        // Gets the time when the test finishes  
        const time_t end_time = time(NULL);  
  
        // Asserts that the test took no more than ~5 seconds.  Did you  
        // know that you can use assertions in SetUp() and TearDown() as  
        // well?  
        EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";  
    }  
  
    // The UTC time (in seconds) when the test starts  
    time_t start_time_;  
};  
  
// We derive a fixture named IntegerFunctionTest from the QuickTest  
// fixture.  All tests using this fixture will be automatically  
// required to be quick.  
class IntegerFunctionTest : public QuickTest {  
    // We don't need any more logic than already in the QuickTest fixture.  
    // Therefore the body is empty.  
};  
  
// Now we can write tests in the IntegerFunctionTest test case.  
  
// Tests Factorial()  
TEST_F(IntegerFunctionTest, Factorial) {  
    // Tests factorial of negative numbers.  
    EXPECT_EQ(1, Factorial(-5));  
    EXPECT_EQ(1, Factorial(-1));  
    EXPECT_GT(Factorial(-10), 0);  
  
    // Tests factorial of 0.  
    EXPECT_EQ(1, Factorial(0));  
  
    // Tests factorial of positive numbers.  
    EXPECT_EQ(1, Factorial(1));  
    EXPECT_EQ(2, Factorial(2));  
    EXPECT_EQ(6, Factorial(3));  
    EXPECT_EQ(40320, Factorial(8));  
}  
  
// Tests IsPrime()  
TEST_F(IntegerFunctionTest, IsPrime) {  
    // Tests negative input.  
    EXPECT_FALSE(IsPrime(-1));  
    EXPECT_FALSE(IsPrime(-2));  
    EXPECT_FALSE(IsPrime(INT_MIN));  
  
    // Tests some trivial cases.  
    EXPECT_FALSE(IsPrime(0));  
    EXPECT_FALSE(IsPrime(1));  
    EXPECT_TRUE(IsPrime(2));  
    EXPECT_TRUE(IsPrime(3));  
  
    // Tests positive input.  
    EXPECT_FALSE(IsPrime(4));  
    EXPECT_TRUE(IsPrime(5));  
    EXPECT_FALSE(IsPrime(6));  
    EXPECT_TRUE(IsPrime(23));  
}  
  
// The next test case (named "QueueTest") also needs to be quick, so  
// we derive another fixture from QuickTest.  
//  
// The QueueTest test fixture has some logic and shared objects in  
// addition to what's in QuickTest already.  We define the additional  
// stuff inside the body of the test fixture, as usual.  
class QueueTest1 : public QuickTest {  
protected:  
    virtual void SetUp() {  
        // First, we need to set up the super fixture (QuickTest).  
        QuickTest::SetUp();  
  
        // Second, some additional setup for this fixture.  
        q1_.Enqueue(1);  
        q2_.Enqueue(2);  
        q2_.Enqueue(3);  
    }  
  
    // By default, TearDown() inherits the behavior of  
    // QuickTest::TearDown().  As we have no additional cleaning work  
    // for QueueTest, we omit it here.  
    //  
    // virtual void TearDown() {  
    //   QuickTest::TearDown();  
    // }  
  
    Queue<int> q0_;  
    Queue<int> q1_;  
    Queue<int> q2_;  
};  
  
// Now, let's write tests using the QueueTest fixture.  
  
// Tests the default constructor.  
TEST_F(QueueTest1, DefaultConstructor) {  
    EXPECT_EQ(0u, q0_.Size());  
}  
  
// Tests Dequeue().  
TEST_F(QueueTest1, Dequeue) {  
    int* n = q0_.Dequeue();  
    EXPECT_TRUE(n == NULL);  
  
    n = q1_.Dequeue();  
    EXPECT_TRUE(n != NULL);  
    EXPECT_EQ(1, *n);  
    EXPECT_EQ(0u, q1_.Size());  
    delete n;  
  
    n = q2_.Dequeue();  
    EXPECT_TRUE(n != NULL);  
    EXPECT_EQ(2, *n);  
    EXPECT_EQ(1u, q2_.Size());  
    delete n;  
}  
  
/*-------------------TYPED_TEST macro and TYPED_TEST_P macro------------------*/  
//Sample 6: This sample shows how to test common properties of multiple  
// implementations of the same interface (aka interface tests).  
  
// First, we define some factory functions for creating instances of  
// the implementations.  You may be able to skip this step if all your  
// implementations can be constructed the same way.  
  
template <class T>  
PrimeTable* CreatePrimeTable();  
  
template <>  
PrimeTable* CreatePrimeTable<OnTheFlyPrimeTable>() {  
    return new OnTheFlyPrimeTable;  
}  
  
template <>  
PrimeTable* CreatePrimeTable<PreCalculatedPrimeTable>() {  
    return new PreCalculatedPrimeTable(10000);  
}  
  
// Then we define a test fixture class template.  
template <class T>  
class PrimeTableTest : public testing::Test {  
protected:  
    // The ctor calls the factory function to create a prime table  
    // implemented by T.  
    PrimeTableTest() : table_(CreatePrimeTable<T>()) {}  
  
    virtual ~PrimeTableTest() { delete table_; }  
  
    // Note that we test an implementation via the base interface  
    // instead of the actual implementation class.  This is important  
    // for keeping the tests close to the real world scenario, where the  
    // implementation is invoked via the base interface.  It avoids  
    // got-yas where the implementation class has a method that shadows  
    // a method with the same name (but slightly different argument  
    // types) in the base interface, for example.  
    PrimeTable* const table_;  
};  
  
#if GTEST_HAS_TYPED_TEST  
  
using testing::Types;  
  
// Google Test offers two ways for reusing tests for different types.  
// The first is called "typed tests".  You should use it if you  
// already know *all* the types you are gonna exercise when you write  
// the tests.  
  
// To write a typed test case, first use  
//  
//   TYPED_TEST_CASE(TestCaseName, TypeList);  
//  
// to declare it and specify the type parameters.  As with TEST_F,  
// TestCaseName must match the test fixture name.  
  
// The list of types we want to test.  
typedef Types<OnTheFlyPrimeTable, PreCalculatedPrimeTable> Implementations;  
  
TYPED_TEST_CASE(PrimeTableTest, Implementations);  
  
// Then use TYPED_TEST(TestCaseName, TestName) to define a typed test,  
// similar to TEST_F.  
TYPED_TEST(PrimeTableTest, ReturnsFalseForNonPrimes) {  
    // Inside the test body, you can refer to the type parameter by  
    // TypeParam, and refer to the fixture class by TestFixture.  We  
    // don't need them in this example.  
  
    // Since we are in the template world, C++ requires explicitly  
    // writing 'this->' when referring to members of the fixture class.  
    // This is something you have to learn to live with.  
    EXPECT_FALSE(this->table_->IsPrime(-5));  
    EXPECT_FALSE(this->table_->IsPrime(0));  
    EXPECT_FALSE(this->table_->IsPrime(1));  
    EXPECT_FALSE(this->table_->IsPrime(4));  
    EXPECT_FALSE(this->table_->IsPrime(6));  
    EXPECT_FALSE(this->table_->IsPrime(100));  
}  
  
TYPED_TEST(PrimeTableTest, ReturnsTrueForPrimes) {  
    EXPECT_TRUE(this->table_->IsPrime(2));  
    EXPECT_TRUE(this->table_->IsPrime(3));  
    EXPECT_TRUE(this->table_->IsPrime(5));  
    EXPECT_TRUE(this->table_->IsPrime(7));  
    EXPECT_TRUE(this->table_->IsPrime(11));  
    EXPECT_TRUE(this->table_->IsPrime(131));  
}  
  
TYPED_TEST(PrimeTableTest, CanGetNextPrime) {  
    EXPECT_EQ(2, this->table_->GetNextPrime(0));  
    EXPECT_EQ(3, this->table_->GetNextPrime(2));  
    EXPECT_EQ(5, this->table_->GetNextPrime(3));  
    EXPECT_EQ(7, this->table_->GetNextPrime(5));  
    EXPECT_EQ(11, this->table_->GetNextPrime(7));  
    EXPECT_EQ(131, this->table_->GetNextPrime(128));  
}  
  
// That's it!  Google Test will repeat each TYPED_TEST for each type  
// in the type list specified in TYPED_TEST_CASE.  Sit back and be  
// happy that you don't have to define them multiple times.  
  
#endif  // GTEST_HAS_TYPED_TEST  
  
#if GTEST_HAS_TYPED_TEST_P  
  
using testing::Types;  
  
// Sometimes, however, you don't yet know all the types that you want  
// to test when you write the tests.  For example, if you are the  
// author of an interface and expect other people to implement it, you  
// might want to write a set of tests to make sure each implementation  
// conforms to some basic requirements, but you don't know what  
// implementations will be written in the future.  
//  
// How can you write the tests without committing to the type  
// parameters?  That's what "type-parameterized tests" can do for you.  
// It is a bit more involved than typed tests, but in return you get a  
// test pattern that can be reused in many contexts, which is a big  
// win.  Here's how you do it:  
  
// First, define a test fixture class template.  Here we just reuse  
// the PrimeTableTest fixture defined earlier:  
  
template <class T>  
class PrimeTableTest2 : public PrimeTableTest<T> {  
};  
  
// Then, declare the test case.  The argument is the name of the test  
// fixture, and also the name of the test case (as usual).  The _P  
// suffix is for "parameterized" or "pattern".  
TYPED_TEST_CASE_P(PrimeTableTest2);  
  
// Next, use TYPED_TEST_P(TestCaseName, TestName) to define a test,  
// similar to what you do with TEST_F.  
TYPED_TEST_P(PrimeTableTest2, ReturnsFalseForNonPrimes) {  
    EXPECT_FALSE(this->table_->IsPrime(-5));  
    EXPECT_FALSE(this->table_->IsPrime(0));  
    EXPECT_FALSE(this->table_->IsPrime(1));  
    EXPECT_FALSE(this->table_->IsPrime(4));  
    EXPECT_FALSE(this->table_->IsPrime(6));  
    EXPECT_FALSE(this->table_->IsPrime(100));  
}  
  
TYPED_TEST_P(PrimeTableTest2, ReturnsTrueForPrimes) {  
    EXPECT_TRUE(this->table_->IsPrime(2));  
    EXPECT_TRUE(this->table_->IsPrime(3));  
    EXPECT_TRUE(this->table_->IsPrime(5));  
    EXPECT_TRUE(this->table_->IsPrime(7));  
    EXPECT_TRUE(this->table_->IsPrime(11));  
    EXPECT_TRUE(this->table_->IsPrime(131));  
}  
  
TYPED_TEST_P(PrimeTableTest2, CanGetNextPrime) {  
    EXPECT_EQ(2, this->table_->GetNextPrime(0));  
    EXPECT_EQ(3, this->table_->GetNextPrime(2));  
    EXPECT_EQ(5, this->table_->GetNextPrime(3));  
    EXPECT_EQ(7, this->table_->GetNextPrime(5));  
    EXPECT_EQ(11, this->table_->GetNextPrime(7));  
    EXPECT_EQ(131, this->table_->GetNextPrime(128));  
}  
  
// Type-parameterized tests involve one extra step: you have to  
// enumerate the tests you defined:  
REGISTER_TYPED_TEST_CASE_P(  
    PrimeTableTest2,  // The first argument is the test case name.  
    // The rest of the arguments are the test names.  
    ReturnsFalseForNonPrimes, ReturnsTrueForPrimes, CanGetNextPrime);  
  
// At this point the test pattern is done.  However, you don't have  
// any real test yet as you haven't said which types you want to run  
// the tests with.  
  
// To turn the abstract test pattern into real tests, you instantiate  
// it with a list of types.  Usually the test pattern will be defined  
// in a .h file, and anyone can #include and instantiate it.  You can  
// even instantiate it more than once in the same program.  To tell  
// different instances apart, you give each of them a name, which will  
// become part of the test case name and can be used in test filters.  
  
// The list of types we want to test.  Note that it doesn't have to be  
// defined at the time we write the TYPED_TEST_P()s.  
typedef Types<OnTheFlyPrimeTable, PreCalculatedPrimeTable>  
    PrimeTableImplementations;  
INSTANTIATE_TYPED_TEST_CASE_P(OnTheFlyAndPreCalculated,    // Instance name  
    PrimeTableTest2,             // Test case name  
    PrimeTableImplementations);  // Type list  
  
#endif  // GTEST_HAS_TYPED_TEST_P  
  
/*-----------------------------TEST_P macro--------------------------------*/  
//Sample 7: This sample shows how to test common properties of multiple  
// implementations of an interface (aka interface tests) using  
// value-parameterized tests. Each test in the test case has  
// a parameter that is an interface pointer to an implementation  
// tested.  
  
#if GTEST_HAS_PARAM_TEST  
  
using ::testing::TestWithParam;  
using ::testing::Values;  
  
// As a general rule, to prevent a test from affecting the tests that come  
// after it, you should create and destroy the tested objects for each test  
// instead of reusing them.  In this sample we will define a simple factory  
// function for PrimeTable objects.  We will instantiate objects in test's  
// SetUp() method and delete them in TearDown() method.  
typedef PrimeTable* CreatePrimeTableFunc();  
  
PrimeTable* CreateOnTheFlyPrimeTable() {  
    return new OnTheFlyPrimeTable();  
}  
  
template <size_t max_precalculated>  
PrimeTable* CreatePreCalculatedPrimeTable() {  
    return new PreCalculatedPrimeTable(max_precalculated);  
}  
  
// Inside the test body, fixture constructor, SetUp(), and TearDown() you  
// can refer to the test parameter by GetParam().  In this case, the test  
// parameter is a factory function which we call in fixture's SetUp() to  
// create and store an instance of PrimeTable.  
class PrimeTableTest1 : public TestWithParam<CreatePrimeTableFunc*> {  
public:  
    virtual ~PrimeTableTest1() { delete table_; }  
    virtual void SetUp() { table_ = (*GetParam())(); }  
    virtual void TearDown() {  
        delete table_;  
        table_ = NULL;  
    }  
  
protected:  
    PrimeTable* table_;  
};  
  
TEST_P(PrimeTableTest1, ReturnsFalseForNonPrimes) {  
    EXPECT_FALSE(table_->IsPrime(-5));  
    EXPECT_FALSE(table_->IsPrime(0));  
    EXPECT_FALSE(table_->IsPrime(1));  
    EXPECT_FALSE(table_->IsPrime(4));  
    EXPECT_FALSE(table_->IsPrime(6));  
    EXPECT_FALSE(table_->IsPrime(100));  
}  
  
TEST_P(PrimeTableTest1, ReturnsTrueForPrimes) {  
    EXPECT_TRUE(table_->IsPrime(2));  
    EXPECT_TRUE(table_->IsPrime(3));  
    EXPECT_TRUE(table_->IsPrime(5));  
    EXPECT_TRUE(table_->IsPrime(7));  
    EXPECT_TRUE(table_->IsPrime(11));  
    EXPECT_TRUE(table_->IsPrime(131));  
}  
  
TEST_P(PrimeTableTest1, CanGetNextPrime) {  
    EXPECT_EQ(2, table_->GetNextPrime(0));  
    EXPECT_EQ(3, table_->GetNextPrime(2));  
    EXPECT_EQ(5, table_->GetNextPrime(3));  
    EXPECT_EQ(7, table_->GetNextPrime(5));  
    EXPECT_EQ(11, table_->GetNextPrime(7));  
    EXPECT_EQ(131, table_->GetNextPrime(128));  
}  
  
// In order to run value-parameterized tests, you need to instantiate them,  
// or bind them to a list of values which will be used as test parameters.  
// You can instantiate them in a different translation module, or even  
// instantiate them several times.  
//  
// Here, we instantiate our tests with a list of two PrimeTable object  
// factory functions:  
INSTANTIATE_TEST_CASE_P(  
    OnTheFlyAndPreCalculated,  
    PrimeTableTest1,  
    Values(&CreateOnTheFlyPrimeTable, &CreatePreCalculatedPrimeTable<1000>));  
  
#else  
  
// Google Test may not support value-parameterized tests with some  
// compilers. If we use conditional compilation to compile out all  
// code referring to the gtest_main library, MSVC linker will not link  
// that library at all and consequently complain about missing entry  
// point defined in that library (fatal error LNK1561: entry point  
// must be defined). This dummy test keeps gtest_main linked in.  
TEST(DummyTest, ValueParameterizedTestsAreNotSupportedOnThisPlatform) {}  
  
#endif  // GTEST_HAS_PARAM_TEST  
  
// Sample 8: This sample shows how to test code relying on some global flag variables.  
// Combine() helps with generating all possible combinations of such flags,  
// and each test is given one combination as a parameter.  
  
#if GTEST_HAS_COMBINE  
  
// Suppose we want to introduce a new, improved implementation of PrimeTable  
// which combines speed of PrecalcPrimeTable and versatility of  
// OnTheFlyPrimeTable (see prime_tables.h). Inside it instantiates both  
// PrecalcPrimeTable and OnTheFlyPrimeTable and uses the one that is more  
// appropriate under the circumstances. But in low memory conditions, it can be  
// told to instantiate without PrecalcPrimeTable instance at all and use only  
// OnTheFlyPrimeTable.  
class HybridPrimeTable : public PrimeTable {  
public:  
    HybridPrimeTable(bool force_on_the_fly, int max_precalculated)  
        : on_the_fly_impl_(new OnTheFlyPrimeTable),  
        precalc_impl_(force_on_the_fly ? NULL :  
        new PreCalculatedPrimeTable(max_precalculated)),  
        max_precalculated_(max_precalculated) {}  
    virtual ~HybridPrimeTable() {  
        delete on_the_fly_impl_;  
        delete precalc_impl_;  
    }  
  
    virtual bool IsPrime(int n) const {  
        if (precalc_impl_ != NULL && n < max_precalculated_)  
            return precalc_impl_->IsPrime(n);  
        else  
            return on_the_fly_impl_->IsPrime(n);  
    }  
  
    virtual int GetNextPrime(int p) const {  
        int next_prime = -1;  
        if (precalc_impl_ != NULL && p < max_precalculated_)  
            next_prime = precalc_impl_->GetNextPrime(p);  
  
        return next_prime != -1 ? next_prime : on_the_fly_impl_->GetNextPrime(p);  
    }  
  
private:  
    OnTheFlyPrimeTable* on_the_fly_impl_;  
    PreCalculatedPrimeTable* precalc_impl_;  
    int max_precalculated_;  
};  
  
using ::testing::TestWithParam;  
using ::testing::Bool;  
using ::testing::Values;  
using ::testing::Combine;  
  
// To test all code paths for HybridPrimeTable we must test it with numbers  
// both within and outside PreCalculatedPrimeTable's capacity and also with  
// PreCalculatedPrimeTable disabled. We do this by defining fixture which will  
// accept different combinations of parameters for instantiating a  
// HybridPrimeTable instance.  
class PrimeTableTest3 : public TestWithParam< ::std::tr1::tuple<bool, int> > {  
protected:  
    virtual void SetUp() {  
        // This can be written as  
        //  
        // bool force_on_the_fly;  
        // int max_precalculated;  
        // tie(force_on_the_fly, max_precalculated) = GetParam();  
        //  
        // once the Google C++ Style Guide allows use of ::std::tr1::tie.  
        //  
        bool force_on_the_fly = ::std::tr1::get<0>(GetParam());  
        int max_precalculated = ::std::tr1::get<1>(GetParam());  
        table_ = new HybridPrimeTable(force_on_the_fly, max_precalculated);  
    }  
    virtual void TearDown() {  
        delete table_;  
        table_ = NULL;  
    }  
    HybridPrimeTable* table_;  
};  
  
TEST_P(PrimeTableTest3, ReturnsFalseForNonPrimes) {  
    // Inside the test body, you can refer to the test parameter by GetParam().  
    // In this case, the test parameter is a PrimeTable interface pointer which  
    // we can use directly.  
    // Please note that you can also save it in the fixture's SetUp() method  
    // or constructor and use saved copy in the tests.  
  
    EXPECT_FALSE(table_->IsPrime(-5));  
    EXPECT_FALSE(table_->IsPrime(0));  
    EXPECT_FALSE(table_->IsPrime(1));  
    EXPECT_FALSE(table_->IsPrime(4));  
    EXPECT_FALSE(table_->IsPrime(6));  
    EXPECT_FALSE(table_->IsPrime(100));  
}  
  
TEST_P(PrimeTableTest3, ReturnsTrueForPrimes) {  
    EXPECT_TRUE(table_->IsPrime(2));  
    EXPECT_TRUE(table_->IsPrime(3));  
    EXPECT_TRUE(table_->IsPrime(5));  
    EXPECT_TRUE(table_->IsPrime(7));  
    EXPECT_TRUE(table_->IsPrime(11));  
    EXPECT_TRUE(table_->IsPrime(131));  
}  
  
TEST_P(PrimeTableTest3, CanGetNextPrime) {  
    EXPECT_EQ(2, table_->GetNextPrime(0));  
    EXPECT_EQ(3, table_->GetNextPrime(2));  
    EXPECT_EQ(5, table_->GetNextPrime(3));  
    EXPECT_EQ(7, table_->GetNextPrime(5));  
    EXPECT_EQ(11, table_->GetNextPrime(7));  
    EXPECT_EQ(131, table_->GetNextPrime(128));  
}  
  
// In order to run value-parameterized tests, you need to instantiate them,  
// or bind them to a list of values which will be used as test parameters.  
// You can instantiate them in a different translation module, or even  
// instantiate them several times.  
//  
// Here, we instantiate our tests with a list of parameters. We must combine  
// all variations of the boolean flag suppressing PrecalcPrimeTable and some  
// meaningful values for tests. We choose a small value (1), and a value that  
// will put some of the tested numbers beyond the capability of the  
// PrecalcPrimeTable instance and some inside it (10). Combine will produce all  
// possible combinations.  
INSTANTIATE_TEST_CASE_P(MeaningfulTestParameters,  
    PrimeTableTest3,  
    Combine(Bool(), Values(1, 10)));  
  
#else  
  
// Google Test may not support Combine() with some compilers. If we  
// use conditional compilation to compile out all code referring to  
// the gtest_main library, MSVC linker will not link that library at  
// all and consequently complain about missing entry point defined in  
// that library (fatal error LNK1561: entry point must be  
// defined). This dummy test keeps gtest_main linked in.  
TEST(DummyTest, CombineIsNotSupportedOnThisPlatform) {}  
  
#endif  // GTEST_HAS_COMBINE  
  
int main (int argc, char* argv[])  
{  
    testing::InitGoogleTest(&argc, argv);  
    //::testing::GTEST_FLAG(filter) = "IsPrimeTest.*:FactorialTest.*";  
    return RUN_ALL_TESTS();  
  
    return 0;  
}  
  
#endif   
  
#if defined BRANCH_2  
// Sample 9: This sample shows how to use Google Test listener API to implement  
// an alternative console output and how to use the UnitTest reflection API  
// to enumerate test cases and tests and to inspect their results.  
using ::testing::EmptyTestEventListener;  
using ::testing::InitGoogleTest;  
using ::testing::Test;  
using ::testing::TestCase;  
using ::testing::TestEventListeners;  
using ::testing::TestInfo;  
using ::testing::TestPartResult;  
using ::testing::UnitTest;  
  
namespace {  
  
    // Provides alternative output mode which produces minimal amount of  
    // information about tests.  
    class TersePrinter : public EmptyTestEventListener {  
    private:  
        // Called before any test activity starts.  
        virtual void OnTestProgramStart(const UnitTest& /* unit_test */) {}  
  
        // Called after all test activities have ended.  
        virtual void OnTestProgramEnd(const UnitTest& unit_test) {  
            fprintf(stdout, "TEST %s\n", unit_test.Passed() ? "PASSED" : "FAILED");  
            fflush(stdout);  
        }  
  
        // Called before a test starts.  
        virtual void OnTestStart(const TestInfo& test_info) {  
            fprintf(stdout,  
                "*** Test %s.%s starting.\n",  
                test_info.test_case_name(),  
                test_info.name());  
            fflush(stdout);  
        }  
  
        // Called after a failed assertion or a SUCCEED() invocation.  
        virtual void OnTestPartResult(const TestPartResult& test_part_result) {  
            fprintf(stdout,  
                "%s in %s:%d\n%s\n",  
                test_part_result.failed() ? "*** Failure" : "Success",  
                test_part_result.file_name(),  
                test_part_result.line_number(),  
                test_part_result.summary());  
            fflush(stdout);  
        }  
  
        // Called after a test ends.  
        virtual void OnTestEnd(const TestInfo& test_info) {  
            fprintf(stdout,  
                "*** Test %s.%s ending.\n",  
                test_info.test_case_name(),  
                test_info.name());  
            fflush(stdout);  
        }  
    };  // class TersePrinter  
  
    TEST(CustomOutputTest, PrintsMessage) {  
        printf("Printing something from the test body...\n");  
    }  
  
    TEST(CustomOutputTest, Succeeds) {  
        SUCCEED() << "SUCCEED() has been invoked from here";  
    }  
  
    TEST(CustomOutputTest, Fails) {  
        EXPECT_EQ(1, 2)  
            << "This test fails in order to demonstrate alternative failure messages";  
    }  
  
}  // namespace  
  
int main(int argc, char **argv) {  
    InitGoogleTest(&argc, argv);  
  
    bool terse_output = false;  
    if (argc > 1 && strcmp(argv[1], "--terse_output") == 0 )  
        terse_output = true;  
    else  
        printf("%s\n", "Run this program with --terse_output to change the way "  
        "it prints its output.");  
  
    UnitTest& unit_test = *UnitTest::GetInstance();  
  
    // If we are given the --terse_output command line flag, suppresses the  
    // standard output and attaches own result printer.  
    if (terse_output) {  
        TestEventListeners& listeners = unit_test.listeners();  
  
        // Removes the default console output listener from the list so it will  
        // not receive events from Google Test and won't print any output. Since  
        // this operation transfers ownership of the listener to the caller we  
        // have to delete it as well.  
        delete listeners.Release(listeners.default_result_printer());  
  
        // Adds the custom output listener to the list. It will now receive  
        // events from Google Test and print the alternative output. We don't  
        // have to worry about deleting it since Google Test assumes ownership  
        // over it after adding it to the list.  
        listeners.Append(new TersePrinter);  
    }  
    int ret_val = RUN_ALL_TESTS();  
  
    // This is an example of using the UnitTest reflection API to inspect test  
    // results. Here we discount failures from the tests we expected to fail.  
    int unexpectedly_failed_tests = 0;  
    for (int i = 0; i < unit_test.total_test_case_count(); ++i) {  
        const TestCase& test_case = *unit_test.GetTestCase(i);  
        for (int j = 0; j < test_case.total_test_count(); ++j) {  
            const TestInfo& test_info = *test_case.GetTestInfo(j);  
            // Counts failed tests that were not meant to fail (those without  
            // 'Fails' in the name).  
            if (test_info.result()->Failed() &&  
                strcmp(test_info.name(), "Fails") != 0) {  
                    unexpectedly_failed_tests++;  
            }  
        }  
    }  
  
    // Test that were meant to fail should not affect the test program outcome.  
    if (unexpectedly_failed_tests == 0)  
        ret_val = 0;  
  
    return ret_val;  
}  
  
#endif  
  
#if defined BRANCH_3  
// Sample 10: This sample shows how to use Google Test listener API to implement  
// a primitive leak checker.  
using ::testing::EmptyTestEventListener;  
using ::testing::InitGoogleTest;  
using ::testing::Test;  
using ::testing::TestCase;  
using ::testing::TestEventListeners;  
using ::testing::TestInfo;  
using ::testing::TestPartResult;  
using ::testing::UnitTest;  
  
namespace {  
  
    // We will track memory used by this class.  
    class Water {  
    public:  
        // Normal Water declarations go here.  
  
        // operator new and operator delete help us control water allocation.  
        void* operator new(size_t allocation_size) {  
            allocated_++;  
            return malloc(allocation_size);  
        }  
  
        void operator delete(void* block, size_t /* allocation_size */) {  
            allocated_--;  
            free(block);  
        }  
  
        static int allocated() { return allocated_; }  
  
    private:  
        static int allocated_;  
    };  
  
    int Water::allocated_ = 0;  
  
    // This event listener monitors how many Water objects are created and  
    // destroyed by each test, and reports a failure if a test leaks some Water  
    // objects. It does this by comparing the number of live Water objects at  
    // the beginning of a test and at the end of a test.  
    class LeakChecker : public EmptyTestEventListener {  
    private:  
        // Called before a test starts.  
        virtual void OnTestStart(const TestInfo& /* test_info */) {  
            initially_allocated_ = Water::allocated();  
        }  
  
        // Called after a test ends.  
        virtual void OnTestEnd(const TestInfo& /* test_info */) {  
            int difference = Water::allocated() - initially_allocated_;  
  
            // You can generate a failure in any event handler except  
            // OnTestPartResult. Just use an appropriate Google Test assertion to do  
            // it.  
            EXPECT_LE(difference, 0) << "Leaked " << difference << " unit(s) of Water!";  
        }  
  
        int initially_allocated_;  
    };  
  
    TEST(ListenersTest, DoesNotLeak) {  
        Water* water = new Water;  
        delete water;  
    }  
  
    // This should fail when the --check_for_leaks command line flag is  
    // specified.  
    TEST(ListenersTest, LeaksWater) {  
        Water* water = new Water;  
        EXPECT_TRUE(water != NULL);  
    }  
  
}  // namespace  
  
int main(int argc, char **argv) {  
    InitGoogleTest(&argc, argv);  
  
    bool check_for_leaks = false;  
    if (argc > 1 && strcmp(argv[1], "--check_for_leaks") == 0 )  
        check_for_leaks = true;  
    else  
        printf("%s\n", "Run this program with --check_for_leaks to enable "  
        "custom leak checking in the tests.");  
  
    // If we are given the --check_for_leaks command line flag, installs the  
    // leak checker.  
    if (check_for_leaks) {  
        TestEventListeners& listeners = UnitTest::GetInstance()->listeners();  
  
        // Adds the leak checker to the end of the test event listener list,  
        // after the default text output printer and the default XML report  
        // generator.  
        //  
        // The order is important - it ensures that failures generated in the  
        // leak checker's OnTestEnd() method are processed by the text and XML  
        // printers *before* their OnTestEnd() methods are called, such that  
        // they are attributed to the right test. Remember that a listener  
        // receives an OnXyzStart event *after* listeners preceding it in the  
        // list received that event, and receives an OnXyzEnd event *before*  
        // listeners preceding it.  
        //  
        // We don't need to worry about deleting the new listener later, as  
        // Google Test will do it.  
        listeners.Append(new LeakChecker);  
    }  
    return RUN_ALL_TESTS();  
}  
  
#endif  
