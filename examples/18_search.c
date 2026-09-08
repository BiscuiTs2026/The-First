/*
 * ============================================================
 *  18_search.c —— 顺序查找 与 折半查找（二分查找）
 *  对应考点：顺序查找不要求有序；折半查找要求【已升序】，
 *            用 low/high/mid 每次砍掉一半，循环条件 low<=high
 *  编译运行：gcc -Wall -Wextra -std=c99 18_search.c -o 18_search
 * ============================================================
 */
#include <stdio.h>

int seqSearch(int a[], int n, int key);  /* 顺序查找，返回下标，找不到返回 -1 */
int binSearch(int a[], int n, int key);  /* 折半查找，a 必须已升序 */

int main(void)
{
    int a[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int key = 13;

    printf("顺序查找 %d -> 下标 %d\n", key, seqSearch(a, 10, key));
    printf("折半查找 %d -> 下标 %d\n", key, binSearch(a, 10, key));
    printf("查找不存在的 8：顺序=%d，折半=%d（-1 表示没找到）\n",
           seqSearch(a, 10, 8), binSearch(a, 10, 8));
    return 0;
}

/* 顺序查找：从头到尾逐个比对，有序无序都能用 */
int seqSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

/* 折半查找：前提是数组已升序，效率更高 */
int binSearch(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;     /* 取中间位置 */
        if (a[mid] == key)
            return mid;                 /* 命中 */
        else if (a[mid] < key)
            low = mid + 1;              /* 中间偏小，目标在右半区 */
        else
            high = mid - 1;             /* 中间偏大，目标在左半区 */
    }
    return -1;                          /* low>high 仍没找到 */
}
