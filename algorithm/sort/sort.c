#include "sort.h"
#include <string.h>

static void _get_element_address(void **ppe, uint32_t index, void *base, uint32_t size);
static void _swap_element(void *e1, void *e2, uint32_t size);

/**
  * @brief  冒泡排序
  * @param  base: 数组首地址指针
  * @param  nmemb: 元素个数
  * @param  size: 元素大小
  * @param  compare: 元素比较函数
  * @retval  无
  * @note  时间复杂度: O(n^2)
  */
void bubble_sort(void *base, uint32_t nmemb, uint32_t size, COMPARE compare)
{
    uint32_t i, j;
    void *e1, *e2;

    for(i = nmemb - 1; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            /* 获取两个比较元素的地址 */
            _get_element_address(&e1, j, base, size);
            _get_element_address(&e2, j + 1, base, size);
            
            /* 比较两个元素，并将较大的元素往后排 */
            if(compare(e1, e2) > 0)
            {
                _swap_element(e1, e2, size);
            }
        }
    }
}

/**
  * @brief  选择排序
  * @param  base: 数组首地址指针
  * @param  nmemb: 元素个数
  * @param  size: 元素大小
  * @param  compare: 元素比较函数
  * @retval  无
  * @note  时间复杂度: O(n^2)
  */
void select_sort(void *base, uint32_t nmemb, uint32_t size, COMPARE compare)
{
    uint32_t i, j;
    void *e1, *e2;

    for(i = 0; i <= nmemb - 2; i++)
    {
        uint32_t min = i;
        for(j = i + 1; j < nmemb; j++)
        {
            /* 获取两个比较元素的地址 */
            _get_element_address(&e1, min, base, size);
            _get_element_address(&e2, j, base, size);

            /* 找出最小值的索引 */
            if(compare(e1, e2) > 0)
            {
                min = j;
            }
        }

        /* 如果最小值就在此次开始处，则不需要交换元素 */
        if(i == min)
            continue;
        
        /* 交换元素 */
        _get_element_address(&e1, i, base, size);
        _get_element_address(&e2, min, base, size);
        _swap_element(e1, e2, size);
    }    
}

/* 私有函数 -------------------------------------------------------------------------- */

static void _get_element_address(void **ppe, uint32_t index, void *base, uint32_t size)
{
    *ppe = (void *)((uint32_t)base + index * size);
}

static void _swap_element(void *e1, void *e2, uint32_t size)
{
    // uint8_t temp[TEMP_MAX_SIZE];

    // if(size > TEMP_MAX_SIZE)
    // {
    //     return;
    // }

    // memcpy(temp, e1, size);
    // memcpy(e1, e2, size);
    // memcpy(e2, temp, size);  

    uint32_t i;
    uint8_t *pe1, *pe2;
    for(i = 0; i < size; i++)
    {
        pe1 = (uint8_t *)((uint32_t)e1 + i);
        pe2 = (uint8_t *)((uint32_t)e2 + i);
        (*pe1) ^= (*pe2);
        (*pe2) ^= (*pe1);
        (*pe1) ^= (*pe2);
    } 
}
