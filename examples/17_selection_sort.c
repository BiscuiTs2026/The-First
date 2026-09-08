/*
 * ============================================================
 *  17_selection_sort.c —— 选择排序（升序）
 *  对应考点：每轮在未排序区间找最小值下标，与区间第一个位置交换；
 *            每轮最多交换 1 次（对比冒泡：比较次数多但交换次数少）
 *  编译运行：gcc -Wall -Wextra -std=c99 17_selection_sort.c -o 17_selection_sort
 * ============================================================
 */
#include <stdio.h>

void printArr(int a[], int n);

int main(void)
{
    int a[8] = {5, 2, 9, 1, 5, 6, 3, 8};
    int n = 8;
    printf("排序前："); printArr(a, n);

    for (int i = 0; i < n - 1; i++) {
        int min = i;                    /* 先假设位置 i 上的元素最小 */
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;                /* 发现更小的，记下它的下标 */
        if (min != i) {                 /* 确实找到更小的才交换 */
            int t = a[i];
            a[i] = a[min];
            a[min] = t;
        }
        printf("第 %d 轮后：", i + 1); printArr(a, n);
    }

    printf("排序后："); printArr(a, n);
    return 0;
}

void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}
