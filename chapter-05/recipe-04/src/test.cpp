#include <gtest/gtest.h>
#include <stdlib.h>
#include <iostream>

int DieInDebugElse12(int* sideeffect) {
    std::cout << "DieInDebugElse12()" << std::endl;
    if (sideeffect) *sideeffect = 12;
#ifndef NDEBUG
    std::cout << "debug death inside DieInDebugElse12()" << std::endl;
    std::cerr << "debug death inside DieInDebugElse12()"; // for EXPECT_DEBUG_DEATH regular expression
    abort();
#else
    std::cout << "release inside DieInDebugElse12()" << std::endl;
#endif  // NDEBUG
    return 12;
}

TEST(TestCase, TestDieOr12WorksInDgbAndOpt)
{
    int sideeffect = 0;
    // Only asserts in dbg.
    EXPECT_DEBUG_DEATH(DieInDebugElse12(&sideeffect), "death");

    #ifdef NDEBUG
    // opt-mode has sideeffect visible.
    EXPECT_EQ(12, sideeffect);
    #else
    // dbg-mode no visible sideeffect.
    EXPECT_EQ(0, sideeffect);
    #endif
}
