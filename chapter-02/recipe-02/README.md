### 布尔值和数值型数据检查

#### 布尔值检查

|  **Fatal assertion**     | **Nonfatal assertion**   | **Verifies**       |
| :----------------------- | :----------------------- | :----------------- |
| ASSERT_TRUE(condition);  | EXPECT_TRUE(condition);  | condition is true  |
| ASSERT_FALSE(condition); | EXPECT_FALSE(condition); | condition is false |

#### 数值型数据检查

| **Fatal assertion**          | **Nonfatal assertion**       | **Verifies**       |
| :--------------------------- | :--------------------------- | :----------------- |
| ASSERT_EQ(expected, actual); | EXPECT_EQ(expected, actual); | expected == actual |
| ASSERT_NE(val1, val2);       | EXPECT_NE(val1, val2);       | val1 != val2       |
| ASSERT_LT(val1, val2);       | EXPECT_LT(val1, val2);       | val1 < val2        |
| ASSERT_LE(val1, val2);       | EXPECT_LE(val1, val2);       | val1 <= val2       |
| ASSERT_GT(val1, val2);       | EXPECT_GT(val1, val2);       | val1 > val2        |
| ASSERT_GE(val1, val2);       | EXPECT_GE(val1, val2);       | val1 >= val2       |
