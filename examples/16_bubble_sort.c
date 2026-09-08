/*
 * ============================================================
 *  16_bubble_sort.c —— 冒泡排序（升序）
 *  对应考点：相邻两两比较、大的往后“冒泡”、n-1 轮、每轮比较次数递减、
 *            swapped 标志优化（已有序则提前结束）
 *  编译运行：gcc -Wall -Wextra -std=c99 16_bubble_sort.c -o 16_bubble_sort
 * ============================================================
 */
#include <stdio.h>

void printArr(int a[], int n);

int main(void)
{
    int a[8] = {5, 2, 9, 1, 5, 6, 3, 8};
    int n = 8;
    printf("排序前："); printArr(a, n);

    for (int i = 0; i < n - 1; i++) {        /* 最多 n-1 轮 */
        int swapped = 0;                     /* 记录本轮有没有交换 */
        for (int j = 0; j < n - 1 - i; j++) {/* 末尾 i 个已排好，不用再比 */
            if (a[j] > a[j + 1]) {           /* 前大后小就交换，把大的往后送 */
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = 1;
            }
        }
        printf("第 %d 轮后：", i + 1); printArr(a, n);
        if (!swapped) break;                 /* 整轮没交换 => 已经有序，提前收工 */
    }

    printf("排序后："); printArr(a, n);
    return 0;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
