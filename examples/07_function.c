/*
 * ============================================================
 *  07_function.c —— 函数：声明、定义、调用、值传递、递归
 *  对应考点：函数原型、形参与实参、return、值传递特点、递归出口
 *  编译运行：gcc -Wall -Wextra -std=c99 07_function.c -o 07_function
 * ============================================================
 */
#include <stdio.h>

/* 函数原型“声明”：当函数定义写在 main 后面时，要先在前面声明，
   相当于提前告诉编译器：有这么个函数，它叫什么、要几个什么参数、返回什么 */
int  add(int a, int b);        /* 有参数、有返回值 */
void printLine(void);         /* 无参数、无返回值 */
void trySwap(int x, int y);   /* 用来演示“值传递” */
long factorial(int n);        /* 递归求阶乘 */

int main(void)
{
    printLine();
    printf("3 + 5 = %d\n", add(3, 5));

    /* ---- 值传递：形参只是实参的“复印件”，函数内改形参不影响实参 ---- */
    int m = 10, n = 20;
    printf("调用前：m=%d, n=%d\n", m, n);
    trySwap(m, n);
    printf("调用后：m=%d, n=%d  （值传递，交换不会带回来）\n", m, n);

    /* ---- 递归：函数直接/间接调用自己，必须设置“递归出口” ---- */
    for (int i = 1; i <= 5; i++)
        printf("%d! = %ld\n", i, factorial(i));

    printLine();
    return 0;
}

/* ================= 以下是函数“定义”（具体实现） ================= */

int add(int a, int b)
{
    return a + b;             /* return 把结果交还给调用处 */
}

void printLine(void)
{
    printf("----------------\n");
}

void trySwap(int x, int y)
{
    int t = x; x = y; y = t;  /* 只交换了复印件 x、y */
    printf("  函数内部：x=%d, y=%d（确实交换了）\n", x, y);
}

long factorial(int n)
{
    if (n <= 1)
        return 1;                      /* 递归出口，缺了它会无限递归直到崩溃 */
    return (long)n * factorial(n - 1); /* 递推关系：n! = n * (n-1)! */
}
