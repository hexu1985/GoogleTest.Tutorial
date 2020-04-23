#include <gtest/gtest.h>
#include <stdlib.h>

int DieInDebugElse12(int* sideeffect) {
    if (sideeffect) *sideeffect = 12;
#ifndef NDEBUG
    std::cerr << "debug death inside DieInDebugElse12()";
    abort();
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
