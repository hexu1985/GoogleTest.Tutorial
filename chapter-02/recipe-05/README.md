### 异常检查

| **Fatal assertion**                      | **Nonfatal assertion**                   | **Verifies**                                    |
| :--------------------------------------- | :--------------------------------------- | :---------------------------------------------- |
| ASSERT_THROW(statement, exception_type); | EXPECT_THROW(statement, exception_type); | statement throws an exception of the given type |
| ASSERT_ANY_THROW(statement);             | EXPECT_ANY_THROW(statement);             | statement throws an exception of any type       |
| ASSERT_NO_THROW(statement);              | EXPECT_NO_THROW(statement);              | statement doesn't throw any exception           |

