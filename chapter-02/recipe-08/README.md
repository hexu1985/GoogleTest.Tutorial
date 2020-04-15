### 浮点型检查

| **Fatal assertion**                 | **Nonfatal assertion**              | **Verifies**                           |
| :---------------------------------- | :---------------------------------- | :------------------------------------- |
| ASSERT_FLOAT_EQ(expected, actual);  | EXPECT_FLOAT_EQ(expected, actual);  | the two float values are almost equal  |
| ASSERT_DOUBLE_EQ(expected, actual); | EXPECT_DOUBLE_EQ(expected, actual); | the two double values are almost equal |


对相近的两个数比较：

| **Fatal assertion**                 | **Nonfatal assertion**              | **Verifies**                                                                 |
| :---------------------------------- | :---------------------------------- | :--------------------------------------------------------------------------- |
| ASSERT_NEAR(val1, val2, abs_error); | EXPECT_NEAR(val1, val2, abs_error); | the difference between val1 and val2 doesn't exceed the given absolute error |
 

同时，还可以使用：

```
EXPECT_PRED_FORMAT2(testing::FloatLE, val1, val2);
EXPECT_PRED_FORMAT2(testing::DoubleLE, val1, val2);
```
