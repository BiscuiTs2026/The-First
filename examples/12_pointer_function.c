/*
 * ============================================================
 *  12_pointer_function.c —— 指针作函数参数（传址调用）
 *  对应考点：值传递无法改实参；传地址后函数可“反向修改”实参；
 *            借助指针让一个函数得到多个结果（二级超高频）
 *  编译运行：gcc -Wall -Wextra -std=c99 12_pointer_function.c -o 12_pointer_function
 *
 *  对比 07_function.c：那里值传递的 swap 交换失败；
 *  这里把“变量的地址”传进去，函数顺着地址就能真正改到外面的变量。
 * ============================================================
 */
#include <stdio.h>

void swap(int *x, int *y);                 /* 形参是指针，准备接收地址 */
void getMinMax(int a[], int n, int *pmin, int *pmax);

int main(void)
{
    /* ---------- 1. 真正的两数交换 ---------- */
    int m = 10, n = 20;
    printf("交换前：m=%d, n=%d\n", m, n);
    swap(&m, &n);                          /* 实参用 & 把地址交出去 */
    printf("交换后：m=%d, n=%d\n", m, n);  /* 成功交换 */

    /* ---------- 2. 一个函数同时“带回”最小值和最大值 ---------- */
    int a[6] = {3, 9, 1, 7, 5, 2};
    int mn, mx;                            /* 准备两个变量装结果 */
    getMinMax(a, 6, &mn, &mx);
    printf("数组最小 = %d，最大 = %d\n", mn, mx);   /* 1 和 9 */

    return 0;
}

/* 交换两个 int：x、y 指向主调函数里的变量 */
void swap(int *x, int *y)
{
    int t = *x;     /* t = x 指向的值 */
    *x = *y;        /* 把 y 指向的值，写进 x 指向的变量 */
    *y = t;
}

/* 遍历数组，把最小值、最大值通过指针“写回”主调函数的变量 */
void getMinMax(int a[], int n, int *pmin, int *pmax)
{
    *pmin = a[0];
    *pmax = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < *pmin) *pmin = a[i];
        if (a[i] > *pmax) *pmax = a[i];
    }
}
