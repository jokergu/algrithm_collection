#include <gtest/gtest.h>
#include <stdlib.h>

extern "C"
{

#include "sort.h"

/* 比较整型数 */
static int comp_int(const void *e1, const void *e2)
{
    return (*(int *)e1 - *(int *)e2);
}

/* 比较浮点数 */
static int comp_float(const void *e1, const void *e2)
{
    float EPSINON = 0.0001;

    float dif = *(float *)e1 - *(float *)e2;
    if(dif < EPSINON)
    {
        return -1;
    }
    else if(dif > EPSINON)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* 比较字符串 */
static int comp_string(const void *e1, const void *e2)
{
    return strcmp(*(char **)e1, *(char **)e2);
}

} /* End extern "C" */

namespace
{

class ALGTest : public ::testing::Test
{
    void SetUp() override
    {
        
    }

    void TearDown() override
    {
        
    }
};

/**
 * @brief 测试冒泡排序对整型数排序时的行为
 */
TEST_F(ALGTest, BubbleSortIntTest)
{   
    int array[] = {5, 2, 7, 12, 3, 1, 9, 2};
    const int sort_array[] = {1, 2, 2, 3, 5, 7, 9, 12};
    const int memb_num = sizeof(array) / sizeof(array[0]);
    const int size = sizeof(array[0]);

    bubble_sort(array, memb_num, size, comp_int);
    EXPECT_EQ(0, memcmp(array, sort_array, sizeof(array)));
}

/**
 * @brief 测试冒泡排序对浮点数排序时的行为
 */
TEST_F(ALGTest, BubbleSortFloatTest)
{   
    float array[] = {2.9, 1.0, 3.3, 1.2, 5.0};
    const float sort_array[] = {1.0, 1.2, 2.9, 3.3, 5.0};
    const int memb_num = sizeof(array) / sizeof(array[0]);
    const int size = sizeof(array[0]);

    bubble_sort(array, memb_num, size, comp_float);
    EXPECT_EQ(0, memcmp(array, sort_array, sizeof(array)));
}

/**
 * @brief 测试冒泡排序对字符串排序时的行为
 */
TEST_F(ALGTest, BubbleSortStringTest)
{   
    char *array[] = {"CBA", "BAA", "AAA"};
    const char *sort_array[] = {"AAA", "BAA", "CBA"};
    const int memb_num = sizeof(array) / sizeof(array[0]);
    const int size = sizeof(array[0]);

    bubble_sort(array, memb_num, size, comp_string);
    EXPECT_EQ(0, memcmp(array, sort_array, sizeof(array)));
}

/**
 * @brief 测试选择排序对整型数排序时的行为
 */
TEST_F(ALGTest, SelectSortIntTest)
{    
    int array[] = {5, 2, 7, 12, 3, 1, 9, 2};
    const int sort_array[] = {1, 2, 2, 3, 5, 7, 9, 12};
    const int memb_num = sizeof(array) / sizeof(array[0]);
    const int size = sizeof(array[0]);

    select_sort(array, memb_num, size, comp_int);
    EXPECT_EQ(0, memcmp(array, sort_array, sizeof(array)));
}

/**
 * @brief 测试插入排序对整型数排序时的行为
 */
TEST_F(ALGTest, InsertSortIntTest)
{    
    int array[] = {5, 2, 7, 12, 3, 1, 9, 2};
    const int sort_array[] = {1, 2, 2, 3, 5, 7, 9, 12};
    const int memb_num = sizeof(array) / sizeof(array[0]);
    const int size = sizeof(array[0]);

    printf("%d, %d, %d, %d, %d, %d, %d, %d\n", array[0], array[1], array[2], array[3],
        array[4], array[5], array[6], array[7]);
    insert_sort(array, memb_num, size, comp_int);
    printf("%d, %d, %d, %d, %d, %d, %d, %d\n", array[0], array[1], array[2], array[3],
        array[4], array[5], array[6], array[7]);
    EXPECT_EQ(0, memcmp(array, sort_array, sizeof(array)));
}


} /* namespace */
