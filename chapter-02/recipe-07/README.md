### 自定义格式的Predicate Assertions

| **Fatal assertion**                            | **Nonfatal assertion**                         | **Verifies**                           |
| :--------------------------------------------- | :--------------------------------------------- | :------------------------------------- |
| ASSERT_PRED_FORMAT1(pred_format1, val1);       | EXPECT_PRED_FORMAT1(pred_format1, val1);       | pred_format1(val1) is successful       |
| ASSERT_PRED_FORMAT2(pred_format2, val1, val2); | EXPECT_PRED_FORMAT2(pred_format2, val1, val2); | pred_format2(val1, val2) is successful |
| ...                                            | ...                                            | ...                                    |
