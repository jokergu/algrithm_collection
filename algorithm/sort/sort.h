#ifndef __SORT_H
#define __SORT_H

#include <stdint.h>

/* 排序所需的最大临时大小 */
#define TEMP_MAX_SIZE    8

typedef int (*COMPARE)(const void *e1, const void *e2);

void bubble_sort(void *base, uint32_t nmemb, uint32_t size, COMPARE compare);
void select_sort(void *base, uint32_t nmemb, uint32_t size, COMPARE compare);

#endif /* __SORT_H */
