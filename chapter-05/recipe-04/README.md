### \*\_DEBUG_DEATH

先来看定义：

```cpp
#ifdef NDEBUG

#define EXPECT_DEBUG_DEATH(statement, regex) \
  do { statement; } while (false)

#define ASSERT_DEBUG_DEATH(statement, regex) \
  do { statement; } while (false)

#else

#define EXPECT_DEBUG_DEATH(statement, regex) \
  EXPECT_DEATH(statement, regex)

#define ASSERT_DEBUG_DEATH(statement, regex) \
  ASSERT_DEATH(statement, regex)

#endif  // NDEBUG for EXPECT_DEBUG_DEATH
```

可以看到，在Debug版和Release版本下， \*\_DEBUG_DEATH的定义不一样。因为很多异常只会在Debug版本下抛出，而在Realease版本下不会抛出，所以针对Debug和Release分别做了不同的处理。

示例代码如下：

```cpp
int DieInDebugElse12(int* sideeffect) {
    if (sideeffect) *sideeffect = 12;
#ifndef NDEBUG
    GTEST_LOG_(FATAL, "debug death inside DieInDebugElse12()");
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
```
